#include<bits/stdc++.h>
using namespace std;

string atoi(int n){
    if(n == 0){
        return "0";
    }
    string ans = "";
    while(n){
        int rem = n%10;
        char ch = '0';
        ch += rem;
        ans += ch;
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
string add(string& s1, string& s2){
    int l1 = s1.length(), l2 = s2.length();
    if(l1 > l2){
        string pad = "";
        for(int i = 1; i <= l1 - l2; i++)
            pad += "0";
        string temp = pad + s2;
        return add(s1, temp);
    }
    else if(l2 > l1)
        return add(s2, s1);

    cout << "Adding " << s1 << " and " << s2 << " | Length: " << l1 << endl;
    int carry = 0;
    string ans = "";
    int i = l1-1;
    while(i >= 0){
        string val = atoi((s1[i] - '0') + (s2[i] - '0') + carry);
        cout << s1[i] << " + " << s2[i] << " + " << carry << " = " << val << endl;
        carry = 0;
        if(val.length() > 1)
            carry = std::stoi(val.substr(0, val.length()-1));
        cout << "Carry upto " << (l1 - i) << " is " << carry << endl;
        ans = val.substr(val.length()-1, 1) + ans;
        i--;
    }
    if(carry != 0)
        ans = atoi(carry) + ans;
    cout << "Returning " << ans << endl;
    return ans;
}
string karatsuba(string& s1, string& s2, int n1, int n2){
    if(n1 < n2){
        cout << "Padding" << endl;
        string pad = "";
        for(int i = 1; i <= n2 - n1; i++)
            pad += "0";
        string temp = pad + s1;
        return karatsuba(temp, s2, n2, n2);
    }
    else if(n1 > n2){
        return karatsuba(s2, s1, n2, n1);
    }
    if(n1 == 0 || n2 == 0){
        string val = atoi(0);
        return val;
    }
    if(n1 == 1 && n2 == 1){
        int mul = (s1[0] - '0') * (s2[0] - '0');
        string digit = atoi(mul);
        return digit;
    }
    cout << s1 << " x " << s2 << " : " << endl;
    int n = s1.length();
    int half = n/2;
    string a = s1.substr(0, half);
    string b = s1.substr(half, n1);
    string c = s2.substr(0, half);
    string d = s2.substr(half, n);

    string ac = karatsuba(a, c, half, half);
    string bd = karatsuba(b, d, half, half);
    string bc = karatsuba(b, c, half, half);
    string ad = karatsuba(a, d, half, half);

    cout << "ac : " << ac << " bd : " << bd << endl;
    cout << "ad : " << ad << " bc : " <<bc << endl;

    string abcd = add(ad, bc);

    cout << "ad + bc : " << abcd << endl;

    string carry = "";
    if(bd.length() > half){
        carry = bd.substr(0, bd.length() - half);
        bd = bd.substr(bd.length()-half, bd.length());
    }

    cout << "Carry and Rem after bd: " << carry << " " << bd << endl;

    abcd = add(abcd, carry);
    cout << "Carry + ad + bc: " << abcd << endl;
    
    if(abcd.length() > half){
        carry = abcd.substr(0, abcd.length() - half);
        abcd = abcd.substr(abcd.length()-half, abcd.length());
    }

    cout << "Carry and Rem after ad + bc: " << carry << " " << abcd << endl;

    ac = add(ac, carry);

    cout << "Carry + ac + abcd + bd: " << (ac + abcd + bd) << endl;
    return (ac + abcd + bd);
}
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.length();
    int n2 = s2.length();
    string ans = karatsuba(s1, s2, n1, n2);
    cout << ans << endl;
    return 0;
}