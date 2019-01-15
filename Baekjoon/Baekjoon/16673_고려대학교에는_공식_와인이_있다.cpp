#include<bits/stdc++.h>

using namespace std;

int main(){
    long long c, k, p, ans = 0;
    scanf("%lld %lld %lld", &c, &k, &p);
    for(int i = 0; i<c; ++i)
        ans += ((i + 1) * (i + 1) * p + (i + 1) * k);
    printf("%lld", ans);
}
