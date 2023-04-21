#include <iostream>
#include <string>

using namespace std;

template <class t>
t total(int n)
{
   t sum = 0;
   for(int i = 0; i < n; i++)
   {
     t value;
     cout <<"Enter value "<< i+1;
     cin >> value;
     sum += value;
   }
   return sum;
}

int main()
{
   int n;
   cout <<"Enter number value: ";
   cin >> n;

   cout << "Sum of" << n << "in interger" << total<int>(n) <<endl;

   return 0;
}
