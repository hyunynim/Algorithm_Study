#include<bits/stdc++.h>

using namespace std;
const int ne = -12345678;
typedef long long ll;
void init(vector<int> & tree, vector<int> & seq, int node, int s, int e){
        if(s == e)
                tree[node] = seq[s];
        else{
        init(tree, seq, node * 2, s, (s + e) / 2);
        init(tree, seq, node * 2 + 1, (s + e) / 2 + 1, e);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
        }
}
int query(vector<int> & tree, int node, int s, int e, int i, int j){
        if(i > e || s > j) return ne;
        if(i <= s && e <= j) return tree[node];
        
        int res1 = query(tree, node * 2, s, (s + e) / 2, i, j);
        int res2 = query(tree, node * 2 + 1, (s + e) / 2 + 1, e, i, j);
        if(res1 == ne) return res2;
        else if(res2 == ne) return res1;
        else return min(res1, res2);
}

void update(vector<int> & tree, int node, int s, int e, int idx, int v){
        if(e < idx || s > idx) return;
        if(s == e) tree[node] = v;
        else{
                update(tree, node * 2, s, (s + e) / 2, idx, v);
                update(tree, node * 2 + 1, (s + e) / 2 + 1, e, idx, v);
                tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
        }
}

int main(){
        int n; scanf("%d", &n);
        vector<int> seq(n + 1);
        for(int i = 1; i<=n; ++i)
                scanf("%d", &seq[i]);
        int h = (int)ceil(log2(n)) + 1;
        vector<int> tree((1 << h));
        init(tree, seq, 1, 1, n);
        int m; scanf("%d", &m);
        for(int i = 0; i<m; ++i){
                int a,b,c;
                scanf("%d %d %d", &a, &b, &c);
                if(a == 1)
                        update(tree, 1, 1, n, b, c); 
                if(a == 2)
                        printf("%d\n", query(tree, 1, 1, n, b, c));
        }
}
