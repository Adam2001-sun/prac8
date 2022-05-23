//
// Created by Sun Haoxian on 23/5/22.
//

#include "LinkedList.h"
#include <string>

LinkedList::LinkedList() = default;

LinkedList::~LinkedList() {
if (this->head == nullptr){
    return;
}
auto temp = this->head;
while (temp->right != nullptr){
    temp =temp->right;
    this->deleteFront();
 }
}

LinkedList::LinkedList(const vector<int> &input) {
    for_each(input.begin(),input.end(),[&](int item){
        this->addFront(item);
    });
}



void LinkedList::addFront(int newItem) {
        if (this->head == nullptr) {
            this->head = create_node(newItem);
            this->rear = this->head;
        } else {
            auto newNode = create_node(newItem);

            newNode->right = this->head;

            this->head->left = newNode;

            this->head = newNode;
        }
    }


    void LinkedList::printItems(){
    if(this->head == nullptr){
        return;
    }
    auto temp =this->head;
    cout << temp->data << " ";
    while (temp->right != nullptr){
        temp =temp->right;
        cout << temp->data <<" ";
    }
}

    shared_ptr<Node> LinkedList::create_node(int data) {
        return make_shared<Node>(data);
    }


void LinkedList::addEnd(int newItem) {
    if (this->head == nullptr) {
        this->head = create_node(newItem);
        this->rear = this->head;
    } else {
        auto newNode = create_node(newItem);

        newNode->left = this->rear;

        this->rear->right = newNode;

        this->rear= newNode;
    }
}

void LinkedList::addAtPosition(int position, int newItem){

    auto positionNode = getItemByposition(position);

    if(positionNode == this->head){
        this->addFront(newItem);
        return;
    }
    if(positionNode == this->rear){
        this->addEnd(newItem);
        return;
    }

    auto newNode = create_node(newItem);
    newNode ->left = positionNode->left;
    newNode->right =positionNode;
    positionNode->left->right = newNode;
    positionNode->left = newNode;

}

shared_ptr<Node> LinkedList::getItemByposition(int position){

    if (position < 1 ){
        return this->head;
    }

    if (position > size){
        return this->rear;
    }
        if(position>=size/2){
            return leftTraversal(this->rear, size, position);
        }else{
            return rightTraversal(this->head,1,position);
        }
}

shared_ptr<Node> LinkedList::leftTraversal(shared_ptr<Node> &node, int from, int to){

    if(from == to){
        return node;
    }
    return leftTraversal(node->left ,from-1,to);
}

shared_ptr<Node> LinkedList::rightTraversal(shared_ptr<Node> &node, int from, int to){

    if(from == to){
        return node;
    }
    return rightTraversal(node->right ,from+1,to);
}



int LinkedList::search(int item){
if(item == this->head->data){
    return 1;
}
if(item == this->rear->data){
    return size;
}
int position = 1;
return searchHelper(this->head,item,position);

}

void LinkedList::deleteEnd(){
    if(this->rear == nullptr){
        cerr <<"ERROR list is empty"<<endl;
        return;
    }else{
        auto secondNode = leftTraversal(this->rear, size, size-1);
        secondNode->right = nullptr;
        this ->rear =secondNode;
    }
    decreaseSize();

}

int LinkedList::searchHelper(shared_ptr<Node>&node, int item, int position){
    if(head == nullptr){
        if  (position == 1){
            cerr << "ERROR empty list"<<endl;
            return -1;
        }else{
            return  -1;
        }
    }

    if(head->data == item){
        return searchHelper(node->right,item,position+1);
    }
}

void LinkedList::decreaseSize(){
    size--;
}


void LinkedList::deleteFront() {

    if(this->head == nullptr){
        cerr << "ERROR empty list"<<endl;
        return;
    }else {
        auto secondNode = rightTraversal(this->head, 1, 2);
        secondNode->left = nullptr;
        this->head = secondNode;

    }
   decreaseSize();
}



void LinkedList::deletePosition(int position) {

auto positionNode = getItemByposition(position);


if(positionNode == this->head){
    this ->deleteFront();
    return;
}

if(positionNode == this->rear){
        this ->deleteEnd();
        return;
}

auto leftNode = positionNode->left;
auto rightNode = positionNode->right;
leftNode->right = rightNode;
rightNode->left = leftNode;
    decreaseSize();
}

int LinkedList::getItem(int position){
    return getItemByposition(position)->data;
}




