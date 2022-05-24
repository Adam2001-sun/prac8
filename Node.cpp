#include <iostream>
#include "Node.h"

Node::Node(){
    //init
    data =0;
    next = nullptr;
}


void Node::setNext(Node* next_ptr){
    next = next_ptr;
}
void Node::setData(int data){
    this->data=data;
}
Node* Node::getNext(){
    return next;
}

int Node::getData(){
    return data;
}

