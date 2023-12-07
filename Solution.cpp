#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int lastInd(int *arr, int &n, int &target){
        if(n==0)
            return -1;
        if(n==1 && arr[n-1]==target)
            return n-1;
        else if(n==1 && arr[n-1]!=target)
            return -1;
    
        if(*(arr+n-1)==target)
            return (n-1);
        else {
            return lastInd(arr, --n, target);
        }
    }
    void printAllPos(int *arr, int &n, int &target, int index = 0){
        if(n==0)
            return;
        if(*(arr+index) == target){
            cout << index << " ";
            printAllPos(arr, --n, target, ++index);
        }
        else{
            printAllPos(arr, --n, target, ++index);
        }
    }
    void lenCharArr(char input[], int &len){
        if(input[0]=='\0')
            return;
        len++;
        lenCharArr(input+1, len);
    }
    void replaceCharArray(char *input, char &targ, char &repl){
        if(*input == '\0')
            return;
        if(input[0] == targ){
            cout << "compare success!" << endl;
            input[0] = repl;
        }
        replaceCharArray(++input, targ, repl);
    }
    void printCharArr(char input[]){
        if(input[0]=='\0'){
            cout << endl;
            return;
        }
        cout << input[0] << " ";
        printCharArr(input+1);
    }
    int stringToInt(string s){
        int n = s.length();
        if(s.length()==0)
            return 0;
        return (s[n-1] - '0') + stringToInt(s.substr(0, n-1))*10;
    }
    void permutationsOfString(string s, int i){
        if(s.length()<=i){
            cout << s << endl;
            return;
        }
        for(int j = i; j< s.length(); j++){
            swap(s[i], s[j]);
            permutationsOfString(s, i+1);
            swap(s[i], s[j]);
        }
    }
    int numberOfJumps(int n){
        if(n==0)
            return 0;
        else if(n==1)
            return 1;
        else if(n==2)
            return 2;
        else if(n==3)
            return 4;
        else{
            return numberOfJumps(n-1) + numberOfJumps(n-2) + numberOfJumps(n-3);
        }
    }
    int stepsHanoi(int plates){
        if(plates == 0 || plates == 1)
            return plates;
        return 2*stepsHanoi(plates-1)+1;
    }
    void movesHanoi(string plate, int i, int j, int k){
        int n = plate.length();
        if(n==0)
            return;
        if(n==1){
            cout << "Move " << plate[n-1] << " from " << i << " tower to " << k << " tower." << endl;
            return;
        } 
    
        string newStr = plate.substr(0, n-1);
        movesHanoi(newStr, i, k, j);
        cout << "Move " << plate[n-1] << " from " << i << " tower to " << k << " tower." << endl;
        movesHanoi(newStr, j, i, k);  
    }
    bool check(vector<int>& nums) {
        if(nums.size()==1)
            return true;
        int n = nums.size(), count = 0;
        if(nums[0]>=nums[n-1]){
            for(int i = 1; i< n; i++){
                if(count>1){
                    return false;
                }
                if(nums[i-1]<=nums[i])
                    continue;
                else{
                    ++count;
                }
            }
            if(count==2){
                return false;
            }
            return true;
        }
        else{
            for(int i = 1; i< n; i++){
                if(nums[i-1]>nums[i])
                    return false;
            }
            return true;
        }
    }
    bool brackets(string s, int &cnt){
        stack<char> stk;
        cnt = 0;
        for(int i = 0; i< s.length(); i++){
            if(s[i]=='{'){
                stk.push('{');
                cnt++;
            }
            if(s[i]=='}'){
                stk.pop();
                cnt--;
            }
            if(stk.empty() && s[i] == '}'){
                return false;
            }
        }
        if(cnt==0){
            return true;
        }
        return false;
    }
    string removeDuplicates(string s) {
        if(s.length()==1)
            return s;
        stack<char> stk;
        stk.push(s[0]);
        int i = 1, n = s.length();
        for(; i< n; i++){
            if(stk.empty() || s[i]!=stk.top()){
                stk.push(s[i]);
            }
            else{
                stk.pop();
            }
        }
        string ret = "";
        while(!stk.empty()){
            ret += stk.top();
            stk.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};