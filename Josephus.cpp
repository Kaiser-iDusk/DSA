#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    // bool swt;
    Node* next;

    Node(int data){
        next = NULL;
        this->data = data;
        // swt = true;
    }
};
class Josephus{
public:
    int n, k;
    Josephus(int n, int k){
        this->n = n;
        this->k = k;
    }
    Node* populate(){
        if(n==0)
            return NULL;
        Node* node = new Node(1);
        Node* head = node;
        int count = 1;
        while (count<n)
        {   
            count++;
            Node* temp = new Node(count);
            head->next = temp;
            head = temp;
        }
        head->next = node;
        return node;
    }
    Node* elimination(Node* node, int k){
        if(k==0)
            return node;
        else if(k==1)
            return NULL;
        int count = 0;
        Node* head = node;
        int cnt = 0;
        while(true){
            cnt++;
            if(cnt == k){
                Node* t = head->next;
                head->next = head->next->next;
                delete t;
                cnt = 1;
            }
            head = head->next;
            if(head->next == head){
                return head;
            }
        }    
    }
    void print(Node* node){
        if(!node){
            cout << "NULL" << endl;
        }
        Node* head = node->next;
        cout << head->data << " : ";
        while(head!=node){
            cout << head->data << " : ";
            head = head->next;
        }
        cout << endl;
        return;
    }
    void execute(){
        Node* node = this->populate();
        Node* nd = this->elimination(node, k); 
        if(nd)
            print(nd);
        else
            cout << 0 << endl;
        return;
    }
};