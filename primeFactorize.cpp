#include<bits/stdc++.h>
using namespace std;

void sieve(vector<int>& primes, int n){
    primes[0] = primes[1] = 0;
    for(int i = 2; (i*i)<= n; i++){
        if(primes[i]){
            for(int j = i*i; j<= n; j+=i){
                primes[j] = 0;
            }
        }
    }
}
void factorize(int n, unordered_map<int, int>& mp, vector<int>& spf){
    if(n==1)
        return;
    int quo = n / spf[n];
    if(mp.find(spf[n]) != mp.end())
        mp[spf[n]]++;
    else    
        mp[spf[n]] = 1;
    factorize(quo, mp, spf);
}
int main(){
    int n;
    cin >> n;
    vector<int> primes(n+1, 1);
    vector<int> spf(n+1, 1);
    sieve(primes, n);

    // for(int i = 0; i*i<= n; i++){
    //     cout << i << " is Prime? " << ((primes[i])?true:false) << endl;
    // }

    for(int i = 0; i<= n; i++){
        spf[i] = i;

        if(primes[i] == 0 && i != 1){
            for(int k = 2; k*k <= i; k++){
                if(primes[k] && (i%k == 0)){
                    spf[i] = k;
                    break;
                }
            }
        }
    }

    for(int i = 0; i<= n; i++){
        cout << "spf["<<i<<"] = "<< spf[i] << endl;
    }

    unordered_map<int, int> mp;
    factorize(n, mp, spf);

    return 0;
}