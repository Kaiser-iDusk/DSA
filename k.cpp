#include<bits/stdc++.h>
#include "Solution.cpp"
#include "SortingAlgos.cpp"
//#include "Stack.cpp"
#include "StackLL.cpp"
using namespace std;
int transform(int n, int k){
    return (int) ((int) n/(k))*(k-1) + (n%(k));
}
bool isLucky(int n) {
    // code here
    int k = n, t = 2;
    while(k>=t){
        if(k%t == 0){
            return false;
        }
        k = transform(k, t);
        t++;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    cout << isLucky(n) << endl;

    // Solution s;
    // string str;
    // //int cnt;
    // cin >> str;
    // // cout << s.brackets(str, cnt) << " | " << cnt << endl;
    // string ans = s.removeDuplicates(str);
    // cout << ans << endl;

    // int n;
    // cin >> n;
    // StackLL<int>* s = new StackLL<int>;
    // int x;
    // cin >> x;
    // while(x!=-1){
    //     s->push(x);
    //     cin >> x;
    // }
    // s->print();
    // s->pop();
    // s->print();
    // cout << s->top() << endl;
    // cout << s->len() << endl;

    // Stack s;
    // int x;
    // cin >> x;
    // while(x!=-1){
    //     s.push(x);
    //     cin >> x;
    // }
    // s.print();
    // s.pop();
    // s.print();

    // Solution s;
    // Sorting sa;
    // int n;
    // cin >> n;
    // vector<int> v;
    // for(int i =0 ; i< n; i++){
    //     int x;
    //     cin >> x;
    //     v.push_back(x);
    // }
    // cout << s.check(v) << endl;

    // int arr[n];
    // for(int i = 0; i< n; i++){
    //     cin >> arr[i];
    // }
    // sa.quickSort(arr, 0, n-1);
    // /// sa.partition(arr, 0, n-1);
    // sa.printArray(arr, 0, n-1);

    // sa.mergeSort(arr, 0, n-1);
    // sa.printArray(arr, 0, n-1);

    // Solution s;
    // string plates;
    // cin >> plates;
    // s.movesHanoi(plates, 1, 2, 3);

    // int n;
    // cin >> n;
    // cout << s.stepsHanoi(n) << endl;

    // string str1, out; 
    // cin >> str1;
    // out = "";
    // s.permutationsOfString(str1, 0);

    // char targ = 'a', repl = 'x';
    // s.replaceCharArray(arr, targ, repl);
    // s.printCharArr(arr);
    return 0;
} 