#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    deque<int> q;
    for(int i = 1; i<=n; ++i) q.push_back(i);
    vector<int> seq(n);
    for(int i = 0; i<n; ++i) scanf("%d", &seq[i]);
    while(q.size()){
        int cur = q.front(); q.pop_front();
        printf("%d ", cur); cur = seq[cur - 1];
        while(1){
            if(cur == 1 || cur == 0) break;
            if(cur > 0){
                q.push_back(q.front());
                q.pop_front();
                --cur;
            }
            else if(cur < 0){
                q.push_front(q.back());
                q.pop_back();
                ++cur;
            }
        }
    }
}
