#include <iostream>
#include "NumberLinkedList.h"
using namespace std;

int main()
{
    NumberLinkedList List;
    
    for(int i = 0; i < 5; i++)
    {
        List.insertLast(i);
    }

    List.insertSorted(3);
    List.displayList();
    
    return 0;
}