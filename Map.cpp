#include<bits/stdc++.h>
using namespace std;

template<typename S>
class Node {
public:
    string key;
    S val;
    Node<S>* next;

    Node() : next(nullptr) {

    }
    Node(string key, S val){
        this->key = key;
        this->val = val;
        next = nullptr;
    }
    ~Node(){
        delete next;
    }
};
template<typename S>
class hashMap {
    //code here
    int size = 10, base = 37;
    Node<S>** bucket;

    int hashFun(string s){
        if(s.length()==0){
            return -1;
        }
        int hash = 0, p = 1;
        for(int i = s.length()-1; i>=0; i--){
            hash = hash*p + ((int) s[i]);
            hash %= size;
            p = (p*base)%size; 
        }
        return hash;
    }
public:
    hashMap(){
        bucket = new Node<S>*[size];
        for(int i = 0; i< size; i++){
            bucket[i] = NULL;
        }
    }
    hashMap(int sz){
        size = sz;
        bucket = new Node<S>*[size];
        for(int i = 0; i< size; i++){
            bucket[i] = NULL;
        }
    }
    hashMap(int sz, int bs){
        size = sz;
        base = bs;
        bucket = new Node<S>*[size];
        for(int i = 0; i< size; i++){
            bucket[i] = NULL;
        }
    }
    // S find(string key){
    //     int index = hashFun(key);
    //     if(index==-1){
    //         cout << "Enter a valid non-null key." << endl;
    //         return NULL;
    //     }

    // }
    void insert(string key, S val){
        int index = hashFun(key);
        if(index==-1){
            cout << "Enter a valid non-null key." << endl;
            return;
        }
        if(bucket[index]==NULL){
            Node<S>* node = new Node<S>(key, val);
            node->next = NULL;
            bucket[index] = node;
        }
        else{
            Node<S>* iter = bucket[index];
            while(iter!=NULL){
                if(iter->key == key){
                    cout << "Key exists : Proceed to update? [Y/N]" << endl;
                    string in;
                    cin >> in;
                    if(in=="Y"){
                        iter->val = val;
                        return;
                    }
                    else{
                        return;
                    }
                }
                iter = iter->next;
            }
            Node<S>* node = new Node<S>(key, val);
            node->next = bucket[index];
            bucket[index] = node;
            return;
        }
    }
    void deleteMapEle(string key){
        int index = hashFun(key);
        if(index == -1 || bucket[index]==NULL){
            cout << "No key found." << endl;
            return;
        }
        if(bucket[index]->key == key){
            if(bucket[index]->next == NULL){
                delete bucket[index];
                bucket[index] = NULL;
                cout<<"Deleted key." << endl;
                return;
            }
            else{
                Node<S>* temp = bucket[index]->next;
                bucket[index]->next = NULL;
                delete bucket[index];
                bucket[index] = temp;
                return;
            }
        }
        Node<S>* iter = bucket[index];
        while(iter->next!=NULL){
            if(iter->next->key == key){
                Node<S>* temp = iter->next;
                iter->next = temp->next;
                temp->next = NULL;
                delete temp;
                cout<<"Deleted key." << endl;
                return;
            }
            iter = iter->next;
        }
        cout << "No key found!" << endl;
        return;
    }
    void printMap() const{
        for(int i = 0; i< size; i++){
            Node<S>* iter = bucket[i]; 
            cout << i+1 << " : ";
            while(iter!=NULL){
                cout << "(" << iter->key << ", " << iter->val << ")" << " ";
                iter = iter->next;
            }
            cout << endl;
        }
        return;
    }
    S const getValue(string key){
        int index = hashFun(key);
        if(index == -1 || bucket[index]==NULL){
            cout << "No key found." << endl;
            return -1;
        }
        Node<S>* iter = bucket[index];
        while(iter!=NULL){
            if(iter->key == key){
                return iter->val;
            }
            iter = iter->next;
        }
        return -1;
    }
};

int main(){
    int n;
    cin >> n;
    hashMap<int> mp(n);
    for(int i = 0; i< n; i++){
        string s;
        cout << "Enter key" << endl;
        cin >> s;
        mp.insert(s, i+1);
    }
    mp.printMap();
    cout << "Enter key to delete : " << endl;
    string key;
    cin >> key;
    cout << mp.getValue(key) << endl;
    mp.deleteMapEle(key);
    mp.printMap();
    return 0;
}
