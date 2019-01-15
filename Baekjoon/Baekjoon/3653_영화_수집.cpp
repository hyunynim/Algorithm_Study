#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
struct Segment {
        vector<ll> tree;
        vector<ll> seq;
        Segment(int n) {
                seq.resize(n + 1);
                int log = ceil(log2(n));
                int t = (1 << (log + 1));
                tree.resize(t);
    }

        void init(int node, int s, int e) {
                if (s == e) {
                        tree[node] = seq[s];
            }
                else {
                        init(node * 2, s, (s + e) / 2);
                        init(node * 2 + 1, (s + e) / 2 + 1, e);
                        tree[node] = tree[node * 2] + tree[node * 2 + 1];
                }
        }

        ll query(int node, int s, int e, int i, int j) {
                if (e < i || s > j) return 0;
                if (i <= s && e <= j) return tree[node];
                return query(node * 2, s, (s + e) / 2, i, j) + query(node * 2 + 1, (s + e) / 2 + 1, e, i, j);
        }

        void update(int node, int s, int e, int i, ll u2) {
                if(i < s || i > e) return;
                if(s == e){
                        tree[node] = u2;
                        return;
                }
                update(node * 2, s, (s + e) / 2, i, u2);
                update(node * 2 + 1, (s + e) / 2 + 1, e, i, u2);
                tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
};

int main() {
        int n, m, t;
        vector<int> h;
        scanf("%d", &t);
        while(t--){
                scanf("%d %d", &n, &m);
                h.resize(n + 1);
                Segment s(n + m);
                for(int i = 1; i<=n; ++i){
                        s.seq[i] = 1;
                        h[i] = n - i + 1;
                }
                s.init(1, 1, n + m);
                for(int i = 0; i<m; ++i){
                        int num;
                        scanf("%d", &num);
                        s.update(1, 1, n + m, h[num], 0);       
                        printf("%lld ", s.query(1, 1, n + m, h[num], n + m));
                        h[num] = n + i + 1;
                        s.update(1, 1, n + m, h[num], 1);       
                }
                puts("");
                s.tree.clear(); s.seq.clear();
                h.clear();
        }
}
