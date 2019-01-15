#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
const ll MOD = (1e9) + 7;
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
                        tree[node] = seq[s] %MOD;
            }
                else {
                        init(node * 2, s, (s + e) / 2);
                        init(node * 2 + 1, (s + e) / 2 + 1, e);
                tree[node] = ((tree[node * 2] % MOD) * (tree[node * 2 + 1]) % MOD) % MOD;
                }
        }

        ll query(int node, int s, int e, int i, int j) {
                if (e < i || s > j) return 1;
                if (i <= s && e <= j) return tree[node];
                return ((query(node * 2, s, (s + e) / 2, i, j) % MOD) * (query(node * 2 + 1, (s + e) / 2 + 1, e, i, j) % MOD)) % MOD;
        }

        void update(int node, int s, int e, int i, ll u1, ll u2) {
                if(i < s || i > e) return;
        if(s == e){
            tree[node] = u2;
            tree[node] %= MOD;
            return;
        }
                update(node * 2, s, (s + e) / 2, i, u1, u2);
                update(node * 2 + 1, (s + e) / 2 + 1, e, i, u1, u2);
                tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
        }
};

int main() {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        Segment s(n);
        for (int i = 1; i <= n; ++i)
                scanf("%lld", &s.seq[i]);

        s.init(1, 1, n);

        ll a, b, c;
        for (int i = 0; i < m + k; ++i) {
                scanf("%lld %lld %lld", &a, &b, &c);
                if (a == 1) 
                        s.update(1, 1, n, b, s.seq[b], c);
                
                else 
                        printf("%lld\n", s.query(1, 1, n, b, c));
        }

}
