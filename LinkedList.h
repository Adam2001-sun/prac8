//
// Created by Sun Haoxian on 23/5/22.
//

#ifndef CMAKE_CLION_CONAN_TEMPLATE_LINKEDLIST_H
#define CMAKE_CLION_CONAN_TEMPLATE_LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <string>

class LinkedList {

public:

    LinkedList();

    LinkedList(const vector<int> &input);



    void addFront(int newItem);

    void addEnd(int newItem);

    void addAtPosition(int position, int newItem);

    int search(int item);

    void deleteFront();

    void deleteEnd();

    void deletePosition(int position);

    int getItem(int position);

    void printItems();

    virtual ~LinkedList();

    void increaseSize();
    void decreaseSize();

private:
    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> rear = nullptr;

    int size = 0;

    shared_ptr<Node> create_node(int data);

    shared_ptr<Node> getItemByposition(int position);

    shared_ptr<Node> leftTraversal(shared_ptr<Node> &node, int from, int to);

    shared_ptr<Node> rightTraversal(shared_ptr<Node> &node, int from, int to);;

    int searchHelper(shared_ptr<Node>&node, int item, int position);
};
#endif //CMAKE_CLION_CONAN_TEMPLATE_LINKEDLIST_H
