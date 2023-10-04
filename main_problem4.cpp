#include <iostream>
#include "NumberLinkedList.h"
using namespace std;

int main()
{
    NumberLinkedList List1;
    NumberLinkedList List2;
    NumberLinkedList List3;
    NumberLinkedList List4;
    NumberLinkedList List5;
    NumberLinkedList List6;
    for(int i = 0; i < 5; i++)
    {
        List1.insertLast(i);
        List3.insertLast(i + 5);
        List4.insertLast(i + 8);
        List5.insertLast(i + 6);
        List6.insertLast(i + 8);
    }

    if(List1.isSet())
    {
        cout << "List1 is a set!\n";
    }
    else
    {
        cout << "List1 is not a set!\n";
    }

    if(List1.isSubset(List2))
    {
        cout << "List2 is a subset of List1\n";
    }
    else
    {
        cout << "List2 is not a subset of List1\n";
    }

    cout << "List3:\n";
    List3.displayList();
    cout << "List4:\n";
    List4.displayList();
    cout << "Get a new List3 by unioning List3 and List4:\n";
    List3.unionSet(List4);
    List3.displayList();

    cout << "List5:\n";
    List5.displayList();
    cout << "List6:\n";
    List6.displayList();
    cout << "Get a new List5 by interseting List5 and List6:\n";
    List5.intersetSet(List6);
    List5.displayList();
    return 0;
}