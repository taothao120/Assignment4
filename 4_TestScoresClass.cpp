#include <iostream>
#include <exception>

using namespace std;

class TestScores {
private:
    int *scores;   
    int numScores;  
public:
    // Constructor
    TestScores(int *s, int n) {
        scores = new int[n];         numScores = n;
        for (int i = 0; i < numScores; i++) {
            if (s[i] < 0 || s[i] > 100) {
                throw out_of_range("Test score out of range (0-100)");
            }
            scores[i] = s[i];
        }
    }

    // Destructor
    ~TestScores() {
        delete[] scores; 
    }

    // Calculate and return average test score
    double getAverage() const {
        int sum = 0;
        for (int i = 0; i < numScores; i++) {
            sum += scores[i];
        }
        return static_cast<double>(sum) / numScores;
    }
};

int main() {
    int validScores[] = { 80, 85, 90, 95, 100 };
    try {
        TestScores ts(validScores, 5);
        cout << "Average score: " << ts.getAverage() << endl;
    }
    catch (out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    int invalidScores[] = { 80, 85, -90, 95, 105 };
    try {
        TestScores ts(invalidScores, 5);
        cout << "Average score: " << ts.getAverage() << endl;
    }
    catch (out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
