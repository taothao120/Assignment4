#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int number;
    string hire_date;

public:
    Employee() {}  // Default constructor
    
    Employee(string name, int number, string hire_date) {
        if (number < 0 || number > 9999)
          throw number;
        this->name = name;
        this->number = number;
        this->hire_date = hire_date;
    }
    
    void set_name(string name) {
        this->name = name;
    }
    
    void set_number(int number) {
      if (number < 0 || number > 9999)
        throw number;
        this->number = number;
    }
    
    void set_hire_date(string hire_date) {
        this->hire_date = hire_date;
    }
    
    string get_name() const {
        return name;
    }
    
    int get_number() const {
        return number;
    }
    
    string get_hire_date() const {
        return hire_date;
    }
};

class ProductionWorker : public Employee {
private:
    int shift;
    double pay_rate;

public:
    ProductionWorker() {}  // Default constructor
    
    ProductionWorker(string name, int number, string hire_date,
                      int shift, double pay_rate) :
                      Employee(name, number, hire_date) {
        if ( shift < 0 ) throw shift;
        if ( pay_rate < 0 ) throw "0";
        this->shift = shift;
        this->pay_rate = pay_rate;
    }
    
    void set_shift(int shift) {
      if (shift < 0) throw shift ;
        this->shift = shift;
    }
    
    void set_pay_rate(double pay_rate) {
        if (pay_rate < 0 ) throw "0";
        this->pay_rate = pay_rate;
    }
    
    int get_shift() const {
        return shift;
    }
    
    double get_pay_rate() const {
        return pay_rate;
    }
        
 };
 
 int main() {
     
   try {
     Employee e("John Doe", -1, "01/02/2012");
   } catch (int e){
     cout << " InvalidEmployeeNumber" <<endl;
   }
   
   try {
   ProductionWorker s("John Doe", 123, "01/01/2022", -1, 12.50);
   } catch (int s){
     cout << " InvalidShift";
   }
   
   try {
   ProductionWorker worker("John Doe", 123, "01/01/2022", 1, -12.50);
   } catch (const char* worker){
     cout << " InvalidPaayRates";
   }


      
    return 0;
}

