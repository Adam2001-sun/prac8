#include <iostream>
#include "LinkedList.h"
#include <limits.h>
using namespace std;

LinkedList::LinkedList(int arr[], int size){

    head = new Node();

    Node* temp=head;

    temp->setData(arr[0]);
    temp->setNext(nullptr);

    for(int i=1; i<size;i++){
        Node* newNode=new Node();
        newNode->setData(arr[i]);
        //if at last element
        newNode->setNext(nullptr);

        temp->setNext(newNode);
        temp=newNode;
    }

}

LinkedList::LinkedList(){
    head=nullptr;
}
LinkedList::~LinkedList(){

    if(head==nullptr){
        return;
    }
    Node* temp = head;
    Node* next = head;
    //clean
    while(temp!=nullptr){

        next = temp->getNext();

        delete temp;

        temp = next;
    }
}
// newHead_next_ptr==newNode_next_ptr then SET   newHead->setNext(newNode)
void LinkedList::add(int item,Node* newNode_next_ptr,Node* newHead, Node* newHead_next_ptr,bool newHead_next_as_newNode){


    Node *newNode = new Node();
    newNode->setData(item);
    newNode->setNext(newNode_next_ptr);
    if (newHead_next_as_newNode){
        newHead->setNext(newNode);
    } else{
        newHead->setNext(newHead_next_ptr);/*
        if (newHead_next_ptr== nullptr)
        {

            //newHead->setNext(newNode);
        } else{
            newHead->setNext(newHead_next_ptr);
        }*/
    }





}
void LinkedList::addFront(int newItem){

    add(newItem,head, head, nullptr, true);
/*    Node* newNode = new Node();
    newNode->setData(newItem);
    //newnode(node1) (node2)head
    newNode->setNext(head);
    head=newNode;
    //head(node1) node2*/


}

void LinkedList::addEnd(int newItem){


    //First item
    if (head == nullptr)
    {

        add(newItem, nullptr, head, nullptr);
        /*head=new Node();
        head->setData(newItem);*/
    }
    Node* currentNode=head;

/*
    Node* newNode=new Node();

    newNode->setData(newItem);

    //leave to nullptr for the next element of newNode
    newNode->setNext(nullptr);
*/


    //loop to the end of list

    while(currentNode->getNext() != nullptr){
        //move next
        currentNode=currentNode->getNext();
    }

    //currentNode:last element, append element
    //currentNode->setNext(newNode);
    add(newItem, nullptr, currentNode, nullptr, true);
}

void LinkedList::addAtPosition(int position, int newItem) {
    if (position < 1) {
        addFront(newItem);
    } else {
        Node *temp = head;
        //counting will start from first element
              int i = 1;
              //loop until the position-th
              while(temp->getNext()!=nullptr && i<position-1){
                  //cout<<"current data is = "<<temp->getData()<<endl;
                  temp=temp->getNext();
                  i++;
              }



        //call addEnd function
        if (temp->getNext() == nullptr) {
            addEnd(newItem);
        }
            //reach middle
        else {

            /* Node* newNode= new Node();
             newNode->setData(newItem);
             newNode->setNext(temp->getNext());
             temp->setNext(newNode);*/
            add(newItem, temp->getNext(), temp, nullptr, true);
        }

    }


}
int LinkedList::search(int item){
    //start from the first element of the list
    int position=1;
    Node* temp = head;

    //loop until the whole list has been searched
    while(temp!=nullptr){
        //if  found
        if(temp->getData()==item){

            return position;
        }
        //increment  position
        position++;
        //goto next node
        temp=temp->getNext();
    }
    //after searched the whole list
    //if item not found
    //cout<<"0"<<" ";
    return 0;

}
void LinkedList::deleteFront(){
    
    if(head == nullptr){
        return;
    }
    else{
        
        //store the first node
        Node* temp=head;
        //move the head pointer from first node to the second node
        head=head->getNext();
        
        //delete the first node
        delete temp;
    }
}

void LinkedList::deleteEnd(){
    
    if(head==nullptr){
        return;
    }
    else{


        Node* secondLastNode=head;
        Node* lastNode=head;
        //get last and second last node
        while(lastNode->getNext() != nullptr){
            secondLastNode=lastNode;

            lastNode=lastNode->getNext();
        }

        delete lastNode;
        //set the pointer of second last node to NULL
        secondLastNode->setNext(nullptr);
    }
    
}

void LinkedList::deletePosition(int position){
    
    if(head!=nullptr){

        if(position<1){
            cout<<"out of range"<<endl;
        }

        Node* secondLastNode=head;
        Node* lastNode=head;


        int count = 0;
        int i =1;
        //cout<<position<<endl;
        //loop util given position
        while(secondLastNode!=nullptr && i<position){
            count++;

            //store the previous address
            lastNode=secondLastNode;
            //get the next address
            secondLastNode=secondLastNode->getNext();


            //increase the counter
            i++;


        }
        //if to delete the first node
        if(position==1){
            deleteFront();
        }

        else if(secondLastNode!=nullptr){
            lastNode->setNext(secondLastNode->getNext());

            delete secondLastNode;
        }
        else{


        }
    }

}

int LinkedList::getItem(int position){

    if(head!=nullptr){
        int i =1;
        Node* temp=head;
        while(temp!=nullptr&&i<position){
            temp=temp->getNext();
            i++;
        }

        //beyond the size of array

        if(temp==nullptr){
            cout<<numeric_limits<int>::max()<<" ";
            return numeric_limits<int>::max();
        }
        else{
            
            cout<<temp->getData()<<" ";
            return temp->getData();
        }
    }
}

void LinkedList::printItems(){
    if(head!=nullptr){
        Node* current=head;
        //boundary case
        while(current->getNext() != nullptr){
            cout << current->getData() << " ";
            current=current->getNext();
        }
        cout << current->getData() << " ";
        cout<<endl;
    }  

}

