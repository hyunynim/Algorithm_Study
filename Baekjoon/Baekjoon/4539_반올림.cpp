#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        ll num, k = 10;
        scanf("%lld", &num);
        while(num > k){
            num += k / 2;
            num /= k;
            num *= k;
            k *= 10;
        }
        printf("%lld\n", num);
    }
}
