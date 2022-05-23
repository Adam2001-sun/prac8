//
// Created by Sun Haoxian on 22/5/22.
//

#ifndef CMAKE_CLION_CONAN_TEMPLATE_NODE_H
#define CMAKE_CLION_CONAN_TEMPLATE_NODE_H


#include<vector>

using namespace std;

class Node {

public:
    int data;
    shared_ptr<Node> left;
    shared_ptr<Node> right;

    explicit Node (int data);
};


#endif //CMAKE_CLION_CONAN_TEMPLATE_NODE_H
