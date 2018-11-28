#include<bits/stdc++.h>

using namespace std;

int main(){
        int n;
        scanf("%d", &n);
        stack<int> s;
        while(n){
                s.push(n % 9);
                n /= 9;
        }
        while(s.size()){
                printf("%d", s.top());
                s.pop();
        }
}
