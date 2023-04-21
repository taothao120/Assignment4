#include <iostream>
#include <string>

using namespace std;

// function template
template <class p1, class p2>
p1 min(p1 a, p2 b)
{
   if ( a > b )
     return b;
   else if ( a < b )
     return a;
   return b;
}

template <class x, class y>
x max(x a, y b)
{
   if ( a > b )
     return a;
   else if ( a < b )
     return b;
   return b;
}

int main()
{
  int a = 5;
  int b = 10;
  cout << "Max: "<< max(a,b);
  float x = 3.4;
  float y = 6.7;
  cout << "Min: "<< min(x,y);
  return 0;
}
