#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll a, b;
    cin >> a >> b;
    if(((a + b) % 2) || (a - b <= 0 && b > 0))
        cout << -1;
    else
        cout << (a + b) / 2 << ' ' << (a - b) / 2 ;
}
