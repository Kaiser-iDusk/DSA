#include<bits/stdc++.h>
using namespace std;
class Stack{
private:
    int nextInd = 0;
    int maxSize = 10;
    int *arr = new int[maxSize];
public:
    void push(int data){
        if(nextInd >= maxSize){
            cout << "Stack Overflow." << endl;
            return;
        }
        arr[nextInd] = data;
        nextInd++;
    }
    void pop(){
        if(nextInd == 0){
            cout << "Stack Underflow." << endl;
            return;
        }
        nextInd--;
    }
    bool isEmpty(){
        if(nextInd == 0)
            return true;
        else
            return false;
    }
    int top(){
        if(nextInd){
            return arr[nextInd-1];
        }
        else{
            return -1;
        }
    }
    void print(){
        for(int i = 0; i< nextInd; i++){
            cout << arr[i] << " >> ";
        }
        cout << endl;
    }
};