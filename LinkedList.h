#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <limits>
#include <array>
class LinkedList{
public:
    LinkedList();
    LinkedList(int arr[],int size);
    void addFront(int newItem);
    void addEnd(int newItem);
    void addAtPosition(int position,int newItem);
    int search(int item);
    void deleteFront();
    void deleteEnd();
    void deletePosition(int position);
    int getItem(int position);

    void printItems();

    ~LinkedList();
private:
    void add(int item,Node* newNode_next_ptr,Node* newHead, Node* newHead_next_ptr,bool newHead_next_as_newNode= false);
    
    Node* head= nullptr;
};

#endif //END OF LINKEDLIST