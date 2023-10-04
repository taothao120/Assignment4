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
    for(int i = 0; i < 5; i ++)
    {
        List1.insertLast(i);
        List2.insertLast(i);
        List3.insertLast(i);
        List4.insertLast(i);
        List5.insertLast(i);
        List6.insertLast(i);
    }
    cout << "List1: \n";
    List1.displayList();
    cout << "List2: \n";
    List2.displayList();
    cout << "List3: \n";
    List3.displayList();
    cout << "List4: \n";
    List4.displayList();
    cout << "List5: \n";
    List5.displayList();
    cout << "List6: \n";
    List6.displayList();

    cout << "Get new List1 Merging List1 and List2:\n";
    List1.merge(List2);
    List1.displayList();
    
    cout << "Get new List3 by concatenating List3 and List4:\n";
    List3.concatenate(List4);
    List3.displayList();

    if(List5.equal(List6))
    {
        cout << "List5 == List6\n";
    }
    else
    {
        cout << "List5 != List6\n";
    }

    cout << "Sorted List3:\n";
    List3.sort();
    List3.displayList();
    return 0;
}
