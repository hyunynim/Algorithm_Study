#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int m[1010101];
void init(vector<int> & tree, vector<int> & seq, int node, int s, int e){
        if(s == e)
                tree[node] = seq[s];
        else{
                init(tree, seq, node * 2, s, (s + e) / 2);
                init(tree, seq, node * 2 + 1, (s + e) / 2 + 1, e);
                tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
}
int query(vector<int> & tree, int node, int s, int e, int i, int j){
        if(i > e || s > j) return 0;
        if(i <= s && e <= j) return tree[node];
        
        int res1 = query(tree, node * 2, s, (s + e) / 2, i, j);
        int res2 = query(tree, node * 2 + 1, (s + e) / 2 + 1, e, i, j);
        return res1 + res2;
}

void update(vector<int> & tree, int node, int s, int e, int idx, int v){
        if(e < idx || s > idx) return;
        if(s == e) tree[node] = v;
        else{
                update(tree, node * 2, s, (s + e) / 2, idx, v);
                update(tree, node * 2 + 1, (s + e) / 2 + 1, e, idx, v);
                tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
}

int main(){
        int n; scanf("%d", &n);
        vector<int> s1(n), s2(n);
        for(int i = 0; i<n; ++i)
                scanf("%d", &s1[i]);
        for(int i = 0; i<n; ++i){
                scanf("%d", &s2[i]);
                m[s2[i]] = i + 1;
        }
        int h = (int)ceil(log2(n)) + 1;
        vector<int> tree((1 << h));
        ll ans = 0;
        for(int i = 0; i<n; ++i){
                update(tree, 1, 1, n, m[s1[i]], 1); 
                ans += query(tree, 1, 1, n, m[s1[i]] + 1, n);
        }
        printf("%lld", ans);
}
