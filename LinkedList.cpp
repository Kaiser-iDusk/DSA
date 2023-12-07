#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next = NULL;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
Node* insert(){
    Node* head = NULL;
    Node* tail = NULL;
    int data;
    cin >> data;
    while(data != -1){
        Node *n = new Node(data);
        if(head == NULL){
            head = n;
            tail = n;
        }
        else{
            tail->next = n;
            tail = n;
        }
        tail->next = NULL;
        cin >> data;
    }
    return head;
}
Node* reverseInsert(){
    Node* head = NULL;
    Node* tail = NULL;
    int data;
    cin >> data;
    while(data != -1){
        Node *n = new Node(data);
        if(head == NULL){
            head = n;
            head->next = NULL;
            tail = n;
        }
        else{
            n->next = head;
            head = n;
        }
        cin >> data;
    }
    return head;
}
void print(Node* head){
    while(head != NULL){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int getAt(Node* head, int index){
    int count = 1;
    while(head!=NULL){
        if(count==index){
            cout << "Data retrieved!" << endl;
            return head->data;
        }
        ++count;
        head = head->next;
    }
    return -1;
}
void insertAt(Node* head, int index, int data){
    if(index<=0)
        return;
    int count = 1;
    Node* temp = NULL;
    while(head!=NULL){
        if(count==index){
            Node *node = new Node(data);
            temp = head->next;
            head->next = node;
            node->next = temp;
            return;
        }
        ++count;
        head = head->next;
    }
    cout << "Index not in list." << endl;
    return;
}
void push_back(Node* head, int data){
    Node* temp = head;
    while(temp){
        temp=temp->next;
        if(temp!=NULL){
            head=temp;
        }
    }
    Node *node = new Node(data);
    node->next = NULL;
    head->next = node;
}
void push_front(Node* &head, int data){
    Node *node = new Node(data);
    node->next = head;
    head = node;
}
void deleteAt(Node* &node, int index){
    Node* head = node;
    if(!head || index < 0){
        return;
    }
    if(index == 0){
        if(head->next){
            node = head->next;
        }
        else{
            node = NULL;
        }
        return;
    }
    int count = 1;
    while(head && count <= index-1){
        head = head->next;
        ++count;
    }
    if(head->next){
        head->next = head->next->next;
    }
}
int len(Node* head){
    int len = 0;
    while(head!=NULL){
        len++;
        head = head->next;
    }
    return len;
}
Node* kreverse(Node* head, int k){
    if(k==1){
        return head;
    }
    if(head->next == NULL){
        return head;
    }
    vector<Node*> v;
    int cnt = 1;
    Node* hd = head;
    Node* tl = hd;
    Node* gtail= tl;
    Node* nxt = head->next;
    int length = len(head);
    int stp = length / k;
    while(cnt<=stp*k){
        if(cnt%k!=0){
            //cout << "count = " << cnt << endl;
            hd = nxt;
            nxt = nxt->next;
            hd->next = tl;
            tl = hd;
            cnt++;
        }
        if(cnt%k==0){
            //cout << "count = " << cnt << endl;
            v.push_back(tl);
            v.push_back(gtail);
            //cout << "Pushing " << tl->data << " & " << gtail->data << endl; 
            hd = nxt;
            tl = hd;
            gtail = tl;
            if(nxt)
                nxt = nxt->next;
            cnt++;
        }
    }
    if(hd){
        //cout << "Head exists still! " << hd->data << endl;
        v.push_back(hd);
    }
    // else{
    //     cout << "Head doesnt exist" << endl;
    // }
    int n = v.size();
    //cout << "V size = " << n << endl;
    for(int i = 1; i< n; i+=2){
        if(i+1 == n){
            v[i]->next = NULL;
            break;
        }
        v[i]->next = v[i+1];
        //cout << "Connecting " << v[i]->data << " & " << v[i+1]->data << endl;     
    }
    return v[0];
}
int main(){
    Node *node = insert();
    print(node);

    cout << "KReverse : k : ";
    int k;
    cin >> k;
    Node* nhead = kreverse(node, k);
    print(nhead);

    // int ind;
    // cin >> ind;
    // deleteAt(node, ind);
    
    // int x, ind;
    // cin >> ind >> x;
    
    // // insertAt(node, ind, x);
    //cout << getAt(node, x) << endl;
    return 0;
}
