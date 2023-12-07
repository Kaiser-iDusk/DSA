#include<bits/stdc++.h>
using namespace std;
 
//template<typename T>
class MinHeap{
    //code here
    vector<int> bucket;
    int nextInd;

    void HeapifyUp(int index){
        if(index == 0){
            return;
        }
        int pInd = index/2;
        if(bucket[pInd]>bucket[index]){
            swap(bucket[pInd], bucket[index]);
            HeapifyUp(pInd);
        }
        else{
            return;
        } 
    }
    void HeapifyDown(int index){
        if(index>=nextInd || 2*index+1>=nextInd){
            return;
        }
        //printHeap();
        int cIndL = 2*index+1, cIndR = 2*index + 2;
        if(bucket[index] >bucket[cIndL] || bucket[index] >bucket[cIndR]){
            if(bucket[cIndL]>bucket[cIndR]){
                swap(bucket[index], bucket[cIndR]);
                HeapifyDown(cIndR);
            }
            else{
                swap(bucket[index], bucket[cIndL]);
                HeapifyDown(cIndL);
            }
            //printHeap();
        } 
        else{
            return;
        }
        return;
    }
public:
    MinHeap(){
        nextInd = 0;
    }
    void insert(int data){
        bucket.push_back(data);
        HeapifyUp(nextInd);
        nextInd++;
        return;
    }
    void del(int data){
        if(nextInd == 0){
            cout << "Empty heap!" << endl;
            return;
        }
        int index = -1;
        for(int i = 0; i< nextInd; i++){
            if(bucket[i]==data){
                index = i;
                break;
            }
            if(i==nextInd-1){
                cout << "No entry " << data << " found!"<< endl;
                return;
            }
        }
        //cout << "Swapping " << bucket[index] << " and " << bucket[nextInd-1] << endl;
        swap(bucket[index], bucket[nextInd-1]);
        //printHeap();
        bucket.pop_back();
        nextInd--;
        HeapifyDown(index);
        return;
    }
    void printHeap(){
        for(int i = 0; i< nextInd; i++){
            cout << bucket[i] << " ";
        } 
        cout << endl;
    }
    int getNextInd(){
        return nextInd;
    }
    int getMin(){
        if(nextInd == 0){
            return -1;
        }
        return bucket[0];
    }
};

class MaxHeap{
    //code here
    vector<int> bucket;
    int nextInd;

    void HeapifyUp(int index){
        if(index == 0){
            return;
        }
        int pInd = index/2;
        if(bucket[pInd]<bucket[index]){
            swap(bucket[pInd], bucket[index]);
            HeapifyUp(pInd);
        }
        else{
            return;
        } 
    }
    void HeapifyDown(int index){
        if(index>=nextInd || 2*index+1>=nextInd){
            return;
        }
        //printHeap();
        int cIndL = 2*index+1, cIndR = 2*index + 2;
        //cout << bucket[cIndL] << " || " << bucket[cIndR] << endl;
        if(bucket[index] <bucket[cIndL] || bucket[index] <bucket[cIndR]){
            if(bucket[cIndL]>bucket[cIndR]){
                //cout << "Swapping " << bucket[index] << " and " << bucket[cIndL] << endl;
                swap(bucket[index], bucket[cIndL]);
                HeapifyDown(cIndL);
            }
            else{
                //cout << "Swapping " << bucket[index] << " and " << bucket[cIndR] << endl;
                swap(bucket[index], bucket[cIndR]);
                HeapifyDown(cIndR);
            }
            //printHeap();
        } 
        else{
            return;
        }
        return;
    }
public:
    MaxHeap(){
        nextInd = 0;
    }
    void insert(int data){
        bucket.push_back(data);
        HeapifyUp(nextInd);
        nextInd++;
        return;
    }
    void del(int data){
        if(nextInd == 0){
            cout << "Empty heap!" << endl;
            return;
        }
        int index = -1;
        for(int i = 0; i< nextInd; i++){
            if(bucket[i]==data){
                index = i;
                break;
            }
            if(i==nextInd-1){
                cout << "No entry " << data << " found!"<< endl;
                return;
            }
        }
        //cout << "Swapping " << bucket[index] << " and " << bucket[nextInd-1] << endl;
        swap(bucket[index], bucket[nextInd-1]);
        bucket.pop_back();
        //printHeap();
        nextInd--;
        HeapifyDown(index);
        return;
    }
    void printHeap(){
        for(int i = 0; i< nextInd; i++){
            cout << bucket[i] << " ";
        } 
        cout << endl;
    }
    int getNextInd(){
        return nextInd;
    }
    int getMax(){
        if(nextInd == 0){
            return -1;
        }
        return bucket[0];
    }
};

int main(){
    MaxHeap hp;
    int x;
    cin >> x;
    while(x!=-1){
        hp.insert(x);
        cin >> x;
    }
    hp.printHeap();
    cout << hp.getNextInd() << endl;
    cout << "Enter data to delete: ";
    cin >> x;
    hp.del(x);
    hp.printHeap();
    cout << "Enter data to delete: ";
    cin >> x;
    hp.del(x);
    hp.printHeap();
    //complete main here
    // MinHeap hp;
    // int x;
    // cin >> x;
    // while(x!=-1){
    //     hp.insert(x);
    //     cin >> x;
    // }
    // hp.printHeap();
    // cout << hp.getNextInd() << endl;
    // cout << "Enter data to delete: ";
    // cin >> x;
    // hp.del(x);
    // hp.printHeap();
    // cout << "Enter data to delete: ";
    // cin >> x;
    // hp.del(x);
    // hp.printHeap();
    return 0;
}

