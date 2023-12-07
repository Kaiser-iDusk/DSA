#include<bits/stdc++.h>
using namespace std;
template<typename T> class Node{
    public:
        T data;
        Node<T>* prev;

        Node(T data){
            this->data = data;
        }
};
template<typename T> class StackLL{
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;
    public:
        StackLL(){
            head = NULL;
            tail = NULL;
            size = 0;
        }
        int len(){
            return size;
        }
        void push(T data){
            Node<T>* node = new Node<T>(data);
            if(size==0){
                node->prev = NULL;
                tail = node;
            }
            else{
                node->prev = tail;
                tail = node;
            }
            size++;
        }
        void pop(){
            if(size == 0){
                cout << "Cannot pop from empty stack." << endl;
                return;
            }
            Node<T>* curr = tail;
            tail = tail->prev;
            delete curr;
            size--;
        }
        int length(){
            return size;
        }
        T top(){
            if(!tail){
                cout << "Cannot return top element of empty stack" << endl;
                return -1;
            }
            return tail->data;
        }
        void print(){
            if(!tail){
                cout << endl;
                return;
            }
            Node<T>* it = tail;
            while(it){
                cout << it->data << " <| ";
                it = it->prev;
            }
            cout << endl;
        }
};