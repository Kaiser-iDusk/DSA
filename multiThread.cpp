#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll x = 0, y = 0;

void fibonacci(ll count){
    ll s = 0, e = 1;
    while(count > 0){
        y = s + e;
        s = e;
        e = y;
        count--;
    }
}

void fiboS(){

}

int main(){
    //complete main here
    ll count = 1e8;

    auto start1 = std::chrono::high_resolution_clock::now();
    fibonacci(count);
    auto end1 = std::chrono::high_resolution_clock::now();
    auto dur1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);

    cout << "y: " << y << endl;
    cout << "Duration by normal main program: " << dur1.count() << "ms" << endl; 

    return 0;
}