#ifndef NUMBERLINKEDLIST_H
#define NUMBERLINKEDLIST_H
#include <iostream>
#include <cstdlib>
using namespace std;

class NumberLinkedList
{
private:
    struct ListNode
    {
        int value;
        struct ListNode *next;
    };

    ListNode *head;

public:
    /////////////////////////// PROBLEM_1 ///////////////////////////////
    NumberLinkedList()
    {
        head = NULL;
    }

    // ~NumberLinkedList()
    // {
    //     while(head != NULL)
    //     {
    //         deleteAt(0);
    //     }

    //     cout << "List has been deleted!!! (DESTRUCTOR)\n";
    //     delete head;
    // }

    void insertFirst(int item)
    {
        ListNode *newNode = new ListNode;
        newNode->value = item;

        newNode->next = head;
        head = newNode;
    }

    void insertLast(int item)
    {
        ListNode *newNode = new ListNode;
        newNode->value = item;
        if(head == NULL)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        ListNode *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFirst()
    {
        if(head == NULL)
        {
            cout << "Empty List!!!\n";
            return;
        }

        ListNode *temp = head;
        head = temp->next;
        delete temp;
    }

    void deleteLast()
    {
        if(head == NULL)
        {
            cout << "Empty List!!!\n";
            return;
        }

        ListNode *temp = head;
        if(temp->next == NULL)
        {
            head = temp->next;
            delete temp;
            return;
        }

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        ListNode *temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
    }

    int length()
    {
        if(head == NULL)
        {
            return 0;
        }
        
        int num_element = 0;
        ListNode *temp = head;
        while(temp != NULL)
        {
            num_element++;
            temp = temp->next;
        }

        return num_element;
    }

    void deleteAt(int index)
    {
        if(head == NULL)
        {
            cout << "Empty List!!!\n";
            return;
        }

        if(index > length() - 1)
        {
            cout << "Index out of range!!!\n";
            exit(EXIT_FAILURE);
        }

        ListNode *temp = head;
        if(index == 0)
        {
            head = temp->next;
            delete temp;
            return;
        }

        for(int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        
        ListNode *temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;    
    }

    void displayList() const
    {
        if(head == NULL)
        {
            cout << "Empty List!!!\n";
            return;
        }

        ListNode *temp = head;
        while(temp != NULL)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    /////////////////////////// END_PROBLEM_1 ///////////////////////////


    /////////////////////////// PROBLEM_2 //////////////////////////////
    // Choose the second way!!!
    void merge(NumberLinkedList List)
    {
        NumberLinkedList merged_List;
        ListNode *temp = head;
        ListNode *temp1 = List.head;

        while((temp != NULL) && (temp1 != NULL))
        {
            if(temp->value <= temp1->value)
            {
                merged_List.insertLast(temp->value);
                temp = temp->next;
            }
            else
            {
                merged_List.insertLast(temp1->value);
                temp1 = temp1->next;
            }
        }

        while(temp1 != NULL)
        {
            merged_List.insertLast(temp1->value);
            temp1 = temp1->next;
        }

        while(temp != NULL)
        {
            merged_List.insertLast(temp->value);
            temp = temp->next;
        }

        while(head != NULL)
        {
            deleteLast();
        }

        head = merged_List.head;
    }

    void concatenate(NumberLinkedList List)
    {
        if(head == NULL)
        {
            cout << "Empty list!!!\n";
            return;
        }

        ListNode *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = List.head;
    }

    bool equal(NumberLinkedList List)
    {
        if(head == NULL)
        {
            return false;
        }

        if(length() != List.length())
        {
            return false;
        }

        ListNode *temp = head;
        ListNode *temp1 = List.head;
        while((temp != NULL) && (temp1 != NULL))
        {
            if(temp->value != temp1->value)
            {
                return false;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }

        return true;
    }
    /////////////////////////// END_PROBLEM_2 ///////////////////////////

    /////////////////////////// PROBLEM_3 ///////////////////////////////
    void merge_sort(int a[], int length)
    {
        merge_sort_recursion(a, 0, length - 1);
    }

    void merge_sort_recursion(int a[], int l, int r)
    {
        if(l < r)
        {
        int m = l + (r - l) / 2;

        merge_sort_recursion(a, l, m);
        merge_sort_recursion(a, m + 1, r);

        merge_sorted_arrays(a, l, m, r);
        }
    }

    void merge_sorted_arrays(int a[], int l, int m, int r)
    {
        int left_length = m - l + 1;
        int right_length = r - m;

        int temp_left[left_length];
        int temp_right[right_length];

        int i, j, k;

        for (int i = 0; i < left_length; i++)
            temp_left[i] = a[l + i];

        for (int i = 0; i < right_length; i++)
            temp_right[i] = a[m + 1 + i];

        for(i = 0, j = 0, k = l; k <= r; k++)
        {
            if((i < left_length) && 
                ((j >= right_length) || (temp_left[i] <= temp_right[j])))
            {
                a[k] = temp_left[i];
                i++;
            }
            else
            {
                a[k] = temp_right[j];
                j++;
            }
        }
    }
    void sort()
    {
        int arr[length()];
        ListNode *temp = head;
        ListNode *temp1 = head;
        int i = 0;
        while(temp != NULL)
        {
            arr[i] = temp->value;
            temp = temp->next;
            i++;
        }
        merge_sort(arr, length());
        
        i = 0;
        while(temp1 != NULL)
        {
            temp1->value = arr[i];
            temp1 = temp1->next;
            i++;
        }
    }

    void insertSorted(int item)
    {
        if(head == NULL)
        {
            cout << "Empty List!!!\n";
            return;
        }

        insertLast(item);
        sort();
    }
    /////////////////////////// END_PROBLEM_3 ///////////////////////////

    /////////////////////////// PROBLEM_4 ///////////////////////////////
    bool isSet()
    {
        if((head == NULL))
        {
            return true;
        }

        if(length() == 1)
        {
            return true;
        }

        ListNode *temp = head;
        // int item = 0;
        while(temp != NULL)
        {
            ListNode *temp1 = temp->next;
            // item = temp->value;
            while(temp1 != NULL)
            {
                if(temp->value == temp1->value)
                {
                    return false;
                }
                temp1 = temp1->next;
            }
            temp = temp->next;
        }

        return true;
    }

    bool isSubset(NumberLinkedList List)
    {
        if(List.length() == 0)
        {
            return true;
        }

        if(!List.isSet())
        {
            return false;
        }

        ListNode *temp;
        ListNode *temp1 = List.head;
        int num_matched_elements = 0;
        while(temp1 != NULL)
        {
            temp = head;
            while(temp != NULL)
            {
                if(temp1->value == temp->value)
                {
                    num_matched_elements++;
                    break;
                }
                temp = temp->next;
            }
            temp1 = temp1->next;
        }

        if(num_matched_elements == List.length())
        {
            return true;
        }

        return false;
    }

    void unionSet(NumberLinkedList List)
    {
        ListNode *temp;
        ListNode *temp1 = List.head;
        bool check = false;
        while(temp1 != NULL)
        {   
            temp = head;
            check = false;
            while(temp != NULL)
            {
                if(temp1->value == temp->value)
                {
                    break;
                }

                if(temp->next == NULL)
                {
                    check = true;
                }
                temp = temp->next;
            }

            if(check)
            {
                insertLast(temp1->value);
            }
            temp1 = temp1->next;
        }
    }

    void intersetSet(NumberLinkedList List)
    {
        NumberLinkedList temp_List;
        int index = 0;
        ListNode *temp = head;
        ListNode *temp1;
        while(temp != NULL)
        {
            temp1 = List.head;
            while(temp1 != NULL)
            {
                if(temp1->value == temp->value)
                {
                    temp_List.insertLast(temp1->value);
                }
                temp1 = temp1->next;
            }
            temp = temp->next;
        }

        while(head != NULL)
        {
            deleteLast();
        }

        head = temp_List.head;
        temp_List.head = NULL;
        delete temp_List.head;
    }
};

#endif