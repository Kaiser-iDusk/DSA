#include<bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wconversion-null"
using namespace std;
 
template<typename T>
class tuple<T>{
    //code here
    T* arr;
    int size, occupied = 0;
    
    public:
    tuple<T>(int n){
        size = n;
        arr = new T[size];
    }
    // ~tuple<T>(){
    //     cout << "Destructor called" << endl;
    //     delete arr;
    //     size = 0;
    //     occupied = 0;
    // }
    void insert(T x){
        if(occupied>= size){
            cout << size << "-tuple at max capacity." << endl;
            return;
        }
        arr[occupied] = x;
        occupied++; 
    }
    void disptup(){
        if(occupied < size){
            cout << "Error: Tuple not filled fully! (Filled only "<< occupied << " spaces out of " << size << " spaces)" << endl;
            cout << "Would you fill the tuple correctly? If yes (Y) then fill the remaining places, else if no (N) destructor will free the tuple." << endl;
            char ch;
            cin >> ch;
            if(ch == 'Y'){
                for(int i = occupied; i< size; i++){
                    T x;
                    cout << "Enter a element: ";
                    cin >> x;
                    arr[i] = x;
                    occupied++;
                }
                disptup();
                return;
            }
            else if(ch == 'N'){
                delete arr;
                size = 0;
                occupied = 0;
                cout << "Tuple destructed." << endl;
                return;
            }
            else{
                cout << "Not recognised input." << endl;
                return;
            }
        }
        for(int i = 0; i< size; i++){
            cout << element(i+1) << " ";
        }
        cout << endl;
        return;
    }
    const T element(int n){
        if(n > size || n < 1){
            cout << "Error: Index out of bounds (1 - " << size << ")" << endl;
            return NULL;
        }
        return arr[n-1];
    }
    void update(T val, int comp){
        if(comp-1 >= size){
            cout << "Error: No valid index." << endl;
            return;
        }
        arr[comp-1] = val;
        return;
    }
};