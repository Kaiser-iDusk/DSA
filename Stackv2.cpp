#include<bits/stdc++.h>
using namespace std;
template<typename T> class Stackv2{
    private:
        int nextInd;
        T* arr = NULL;
        int size = 3;
    public:
        Stackv2(){
            arr = new T[size];
        }
        Stackv2(int n){
            if(n<=0){
                cout << "Cannot create stack of size " << n << endl;
            }
            else{
                arr = new T[n];
                nextInd = 0;
                size = n;
            }
        }
        void push(T data){
            if(nextInd==size){
                cout << "Stack limit reached" << endl;
                return;
            }
            arr[nextInd] = data;
            nextInd++;
        }
        void pop(){
            if(nextInd == 0){
                cout << "Cannot pop from empty stack" << endl;
            }
            nextInd--;
        }
        int length(){
            if(arr){
                return nextInd;
            }
            else{
                return -1;
            }
        }
        T top(){
            if(nextInd==0){
                cout << "Cannot return top element of empty stack" << endl;
                return;
            }
            return arr[nextInd-1];
        }
        void print(){
            if(nextInd == 0){
                cout << endl;
                return;
            }
            for(int i = nextInd-1; i >=0; i--){
                cout << arr[i] << endl;
            }
        }
};