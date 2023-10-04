#include "NumberLinkedList.h"

int main()
{
    NumberLinkedList List;
    
    cout << "Original List: \n";
    for(int i = 0; i < 5; i++)
    {
        List.insertLast(i);
        List.insertFirst(i);
    }

    List.displayList();
    cout << "List Length: " << List.length() << endl;
    cout << "List after deleteFirst():\n";
    List.deleteFirst();
    List.displayList();
    cout << "List after deleteLast():\n";
    List.deleteLast();
    List.displayList();
    cout << "List after deleteAt index 4:\n";
    List.deleteAt(4);
    List.displayList();
    cout << "List after deleteAt index 0:\n";
    List.deleteAt(0);
    List.displayList();
     
    return 0;
}