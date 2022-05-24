#include <iostream>
#include "LinkedList.h"
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(){

    int array[100]={0};
    
    string input;
    int size=0;
    int num1, num2;

    while(cin>>input){
        if(isdigit(input[0])){
            //convert the string to int and store into 
            array[size]=atoi(input.c_str());

            //increment the size of array
            size++;
        }
        else if(cin.get()=='\n'){
            break;
        }
        else{
            //if is not integer, exit
            break;
        }
    }


    //pass the array and size of array into the linkedlist constructor
    LinkedList linklist(array,size);
    //cout<<"Print 5"<<endl;
    //linklist.printItems();
    if(input=="AF"){
        cin>>num1;
        linklist.addFront(num1);
    }
    else if(input=="AE"){
        cin>>num1;
        linklist.addEnd(num1);
    
    }
    else if(input== "AP"){
        cin>>num1>>num2;
        linklist.addAtPosition(num1,num2);

    }
    else if(input == "S"){
        cin>>num1;
        linklist.search(num1);
    }
    else if(input == "DF"){
        linklist.deleteFront();
    }
    else if(input=="DE"){
        linklist.deleteEnd();
    }
    else if(input == "DP"){
        cin>>num1;
        linklist.deletePosition(num1);
    }
    else if(input == "GI"){
        cin>>num1;
        linklist.getItem(num1);
    }
    else{
        return -1;
    }

    linklist.printItems();
    //delete linklist;
    return 0;
}

//5 2 7 10 AF 3 0