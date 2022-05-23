//
// Created by Sun Haoxian on 23/5/22.
//
#include "Node.h"
#include "LinkedList.h"
#include<vector>
#include<string>
#include<iostream>

enum class InputIndexEnun {
    denotation = 4,
    firstArgument = 5,
    secondArgument = 6
};

int main(int argc, char **argv){

    shared_ptr<LinkedList> linkedList;

    vector<string> input;

    string input_value;

    for(int i = 0; i <7; ++i){
        try{
            cin>>input_value;
            input.push_back(input_value.substr(0,input_value.find(' ')));
        }catch(exception& e){
            cout <<e.what() <<endl;
        }
    }

    vector<int> constructionArray;
    for_each(input.begin(),input.begin()+4,[&constructionArray](const string& var){
        constructionArray.push_back(stoi(var));
    });




 int denoatationIndex = static_cast<unsigned long>(InputIndexEnun::denotation);
 int firstArgumentIndex = static_cast<unsigned long>(InputIndexEnun::firstArgument);
 int secondArgumentIndex = static_cast<unsigned long>(InputIndexEnun::secondArgument);

 if (input.at(denoatationIndex)=="AF"){
     linkedList->addFront(stoi(input.at(firstArgumentIndex)));
 }
    if (input.at(denoatationIndex)=="AE"){
        linkedList->addEnd(stoi(input.at(firstArgumentIndex)));
    }

    if (input.at(denoatationIndex)=="Ap"){
        linkedList->addAtPosition(stoi(input.at(firstArgumentIndex)), stoi(input.at(secondArgumentIndex)));

    }
    if (input.at(denoatationIndex)=="S"){
        linkedList->search(stoi(input.at(firstArgumentIndex)));

    }

    if (input.at(denoatationIndex)=="DF") {
        linkedList->deleteFront();
    }

        if (input.at(denoatationIndex)=="DE"){
            linkedList->deleteEnd();
        }

        if (input.at(denoatationIndex)=="DP"){
                linkedList->deletePosition(stoi(input.at(firstArgumentIndex)));
            }

            if (input.at(denoatationIndex)=="GI"){
                    linkedList->getItem(stoi(input.at(firstArgumentIndex)));
            }
            linkedList->printItems();

}