#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> seq(n);
    for(int i = 0; i<n; ++i)
        scanf("%d", &seq[i]);
    
    vector<int> ans;
    ans.push_back(seq[0]);
    
    for(int i = 1; i<n; ++i){
        auto it = lower_bound(ans.begin(), ans.end(), seq[i]);
        if(it == ans.end())
            ans.push_back(seq[i]);
        else if(*it > seq[i])
            *it = seq[i];
    }
    printf("%d", n - ans.size());
}
