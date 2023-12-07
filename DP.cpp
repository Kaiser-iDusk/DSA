#include<bits/stdc++.h>
using namespace std;

class DynamicProgramming{
    //code here
public:
    /*Operations-
    1. n -= 1;
    2. if(n%2==0) n/=2;
    3. if(n%3==0) n/=3; 
    */ 
    int minStepsToOne(int n, int *arr){
        if(n==1 || n==2 || n==3){
            arr[1] = 1;
            arr[2] = 1;
            arr[3] = 1;
            return 1;
        }
        int One = 1;
        if(arr[n-1]!=0){
            One += arr[n-1];
            arr[n] = One;
        }
        else{
            arr[n-1] = minStepsToOne(n-1, arr);
            One += arr[n-1];
        }
        if(n%3==0){
            int Three = 1;
            if(arr[n/3]!=0){
                Three += arr[n/3];
                arr[n] = Three;
            }
            else{
                arr[n/3] = minStepsToOne(n/3, arr);
                Three += arr[n/3];
            }
            return min(One, Three);
        }
        if(n%2==0){
            int Two = 1;
            if(arr[n/2]!=0){
                Two += arr[n/2];
                arr[n] = Two;
            }
            else{
                arr[n/2] = minStepsToOne(n/2, arr);
                Two += arr[n/2];
            }
            return min(One, Two);
        }
        return One;
    }
    int minKStepsToOne(int n, int *arr){
        
    }
};
 
int main(){
    //complete main here
    DynamicProgramming dp;
    int x;
    cin >> x;
    int arr[x+1] = {0};
    cout << "Minimum steps to get 1 from " << x << " : " << dp.minStepsToOne(x, arr) << endl;
    return 0;
}