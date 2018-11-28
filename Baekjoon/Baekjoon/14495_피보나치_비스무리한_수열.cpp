#include<bits/stdc++.h>

typedef long long ll;
ll d[123] = {0, 1, 1, 1};

int main(){
        for(int i = 4; i<=116; ++i)
                d[i] = d[i-1] + d[i-3];
        int n;
        scanf("%d", &n);
        printf("%lld", d[n]);
}
