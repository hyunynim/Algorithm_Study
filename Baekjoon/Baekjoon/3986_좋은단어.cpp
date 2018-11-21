#include<bits/stdc++.h>
using namespace std;

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
                string s;
                stack<char> st;
                cin >> s;
                bool hasAns = 1;
                for (int j = 0; j < s.size(); ++j) {
                        if(st.empty() || st.top() != s[j])
                                st.push(s[j]);
                        else
                                st.pop();
                }
                if(st.empty()) ++ans;
                else while(st.size()) st.pop();
        }
        cout << ans;
}
