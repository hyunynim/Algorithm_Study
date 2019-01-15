#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, sum = 0, maxx = 0;
    scanf("%d", &n);
    for(int i = 0; i<n; ++i){
        int num; scanf("%d", &num);
        maxx = max(maxx, num);
        sum += num;
    }
    printf("%d", sum - maxx);
}
