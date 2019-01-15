#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
const ll m = (1e9) + 7;
ll pow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b%2){
            res *= (__int128)a;
            res %= m;
        }
        a *= (__int128)a;
        a %= m;
        b /= 2;
    }
    return res;
}

int main(){
    ll a, x;
    cin >> a >> x;
    a %= m;
    cout << pow(a, x);
}
