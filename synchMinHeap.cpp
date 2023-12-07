#include<bits/stdc++.h>
#include "tuple.cpp"
using namespace std;

class SMinHeap {
    //code here
    int size = 0, pos = 0, compInd;
    vector<tuple<int>> v;

    void HeapifyUp(int index){
        if(index == 0 || index > pos){
            return;
        }
        int pInd = min((index / 2), (index - 1) / 2);

        if(v[index].element(compInd) < v[pInd].element(compInd)){
            tuple<int> temp = v[index];
            v[index] = v[pInd];
            v[pInd] = temp;

            HeapifyUp(pInd);
        }
        else{
            return;
        }
        return;
    }

    void HeapifyDown(int index){
        if(pos == 0 || size == 0 || pos == 1){
            return;
        }
        if(2*index+1 >= pos || index >= pos){
            return;
        }

        int cIndL = 2*index + 1, cIndR = 2*index + 2;
        if(cIndR < pos){
            if(v[cIndL].element(compInd) < v[index].element(compInd) || v[cIndR].element(compInd) < v[index].element(compInd)){
                if(v[cIndL].element(compInd) > v[cIndR].element(compInd)){
                    tuple<int> temp = v[index];
                    v[index] = v[cIndR];
                    v[cIndR] = temp;

                    HeapifyDown(cIndR);
                }
                else{
                    tuple<int> temp = v[index];
                    v[index] = v[cIndL];
                    v[cIndL] = temp;

                    HeapifyDown(cIndL);
                }
            }
            else{
                return;
            }
        }
        else{
            if(v[cIndL].element(compInd) < v[index].element(compInd)){
                tuple<int> temp = v[index];
                v[index] = v[cIndL];
                v[cIndL] = temp;

                HeapifyDown(cIndL);
            }
            else{
                return;
            }
        }
        return;
    }

public:
    SMinHeap(int n, int ind){
        size = n;
        compInd = ind;
    }
    void push(tuple<int> tup){
        if(pos< size){
            v.push_back(tup);
            HeapifyUp(pos);
            pos++;
        }
        else{
            cout << "Error: Heap at max capacity." << endl;
            return;
        }
    }
    tuple<int> front(){
        if(pos==0 || size==0){
            return NULL;
        }
        //v[0].disptup();
        return v[0];
    }
    void pop_front(){
        if(pos==0 || size==0){
            return;
        }
        if(pos==1){
            v.pop_back();
            pos--;
            return;
        }
        v[0] = v[pos-1];
        v.pop_back();
        pos--;
        HeapifyDown(0);
        return; 
    }
    void display(){
        for(int i= 0; i< pos; i++){
            v[i].disptup();
        }
    }
    bool isEmpty(){
        //cout << pos << " | " << size << endl;
        if(pos == 0 || size == 0){
            return true;
        }
        return false;
    }
    bool change(int val, int newVal, int comp, bool s){
        if(val == newVal){
            return true;
        }
        int fInd = find(val, comp);
        
        if(fInd==-1){
            return false;
        }

        v[fInd].update(newVal, comp);
        if(compInd != comp){
            return true;
        }
        if(val > newVal){
            HeapifyDown(fInd);
            return true;
        }
        HeapifyUp(fInd);
        return true;        
    }

    void change(int index, int newVal, int comp){
        // cout << "Index = " << index << " | comp = " << comp << " | compInd " << compInd << endl;
        if(index >= pos){
            return;
        }
        if(v[index].element(comp) == newVal){
            // cout << "Comp and compInd vals are same." << endl;
            return;
        }
        if(comp == compInd){
            // cout << "Comp and compInd are same." << endl;
            int val = v[index].element(comp);
            // cout << "tuple at postion " << index << endl;
            v[index].disptup();
            v[index].update(newVal, comp);
            if(val > newVal){
                HeapifyUp(index);
                return;
            }
            HeapifyDown(index);
            return;    
        }  
        else{
            v[index].update(newVal, comp);
            return;
        }
    }

    int find(int val, int comp){
        if(pos==0 || size==0){
            return -1;
        }
        int index = -1;

        for(int i = 0; i< pos; i++){
            if(v[i].element(comp) == val){
                index = i;
                return index;
            }
        }
        return index;
    }

    tuple<int> elem(int ind){
        if(ind >= pos){
            cout << "Error: No such index." << endl;
            return NULL;
        }
        return v[ind];
    }
};
 
// int main(){
//     //complete main here
//     cout << "Enter tuple length: ";
//     int n, m, ind;
//     cin >> n;
//     cout << "Enter number of tuples to enter: ";
//     cin >> m;
//     cout << "Enter the comparison index for the tuples: ";
//     cin >> ind;

//     SMinHeap spq(m, ind);

//     while(m--){
//         cout << "Enter the tuple elements: " << endl;
//         tuple<int> tup(n);
//         for(int i = 0; i< n; i++){
//             int x;
//             cin >> x;
//             tup.insert(x);
//         }
//         spq.push(tup);
//         cout << "After push: " << endl;
//         spq.display();
//     }
//     cout << endl;
//     spq.display();

//     cout << "Front element: "<< endl;
//     spq.front().disptup();
//     cout << endl;

//     spq.pop_front();
//     spq.display();
//     return 0;
// }