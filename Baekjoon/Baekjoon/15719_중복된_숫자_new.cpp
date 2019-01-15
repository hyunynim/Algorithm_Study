#include<cstdio>
typedef long long ll;

int main(){
    ll n; scanf("%lld", &n);
    ll sum = n * (n - 1) / 2, num;
    while(n--){
        scanf("%lld", &num); sum -= num;
    }
    printf("%lld", -sum);
}
