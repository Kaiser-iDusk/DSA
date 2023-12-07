#include <bits/stdc++.h> 
using namespace std;
bool checkPalindrome(string s)
{
    // Write your code here.
    int i = 0, j = s.length()-1;
    string t = "";
    if(j==0)
        return true;
    while(i<=j){
        if(s[i]-'0'<0 || (s[i]-'0'>10 && s[i]-'A'<0) || (s[i]-'A'>26 && s[i]-'a'<0) || (s[i]-'a'>26) || s[i]=='-' || s[i]==' ' || s[i] =='+'){
            i++;
        }
        // if(s[j]-'0'<0 || (s[j]-'0'>10 && s[j]-'A'<0) || (s[j]-'A'>26 && s[j]-'a'<0) || (s[j]-'a'>26) || s[j]=='-' || s[i]==' ' || s[i]=='+'){
        //     j--;
        // }
        // if(s[i]==s[j] || (s[i]-'A') == (s[j]-'a') || s[i]-'a' == s[j]-'A'){
        //     i++;
        //     j--;
        // }
        else{
            t += s[i];
            i++;
        }
        
    }
    cout << t << endl;
    i = 0, j = t.length()-1;
    while(i<=j){
        if(t[i]-'0'==t[j]-'0' || t[i]-'a' == t[j]-'a' || t[i]-'A' == t[j]-'A' || (t[i]-'A') == (t[j]-'a') || t[i]-'a' == t[j]-'A'){
            i++;
            j--;
            //cout<<"Matched!"<<endl;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        getline(cin, s);
        if(checkPalindrome(s)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}