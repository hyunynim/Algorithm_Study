#include<bits/stdc++.h>

using namespace std;
int d[31] = {1};

int main(){
    for(int i = 1; i<31; ++i)
        d[i] = d[i-1] * 2;
    int n;
    scanf("%d", &n);
    while(n--){
        int num; scanf("%d", &num);
        printf("%d\n", d[num] - 1);
    }
}
