#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector <double> rainfall(12);
  for (int i = 0; i < 12; i++)
  {
    double rain;
    cout << "Rainfall for month "<<i+1<<": ";
    cin >> rain;
    try { 
      if ( rain < 0 )
        throw "0";
    }
    catch(const char* n){ cout << "Error" << n ;}
    rainfall[i] = rain;
  }
  
  double total=0, highest=0, lowest=0;
  for (int i = 0; i < 12; i++)
  {
      total += rainfall[i];
      if ( highest < rainfall[i] )
        highest = rainfall[i];
      if (lowest > rainfall[i] )
        lowest = rainfall[i];
  }

  cout << "Total rainfall: "<< total<<endl;
  cout << "Average rainfall: "<<total/12<<endl;
  cout << "highest and lowest:" << highest << lowest ;

  return 0;
  
}
