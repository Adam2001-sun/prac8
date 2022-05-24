#ifndef NODE_H
#define NODE_H

class Node{
    public:
        Node();
        int getData();
        void setData(int data);
        Node* getNext();
        void setNext(Node* next_ptr);
    
    private:
        int data;
        Node* next;
};

#endif