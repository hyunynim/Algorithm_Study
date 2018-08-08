#include<cstdio>
#include<queue>
#include<utility>
#include<tuple>
#include<vector>
#include<algorithm>

using namespace std;
bool chk[201][201][201];
queue<tuple<int, int, int>> q;
vector<int> ans;
int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	ans.push_back(C);

	q.push({ 0,0,C });
	chk[0][0][C] = 1;
	while (q.size()) {
		int a, b, c;
		tie( a, b, c ) = q.front();
		if (a == 0 && b == 8 && c == 2)
			int qwe = 1;
		if (a == 0)
			ans.push_back(c);
		q.pop();
		if (a) {
			//a b
			if (b != B) {
				if (a + b > B && !chk[a + b - B][B][c]) {
					q.push({ a + b - B, B, c });
					chk[a + b - B][B][c] = 1;
				}
				else if(a + b <= B){
					if (!chk[0][a + b][c]) {
						q.push({ 0, a + b, c });
						chk[0][a + b][c] = 1;
					}
				}
			}
			//a c
			if (c != C) {
				if (a + c > C && !chk[a + c - C][b][C]) {
					q.push({ a + c - C, b, C });
					chk[a + c - C][b][C] = 1;
				}
				else if(a + c <= C){
					if(!chk[0][b][a + c])
					q.push({ 0, b, a + c });
					chk[0][b][a + c] = 1;
				}
			}
		}
		if (b) {
			//b c
			if (c != C) {
				if (b + c > C && !chk[a][b + c - C][C]) {
					q.push({ a, b + c - C, C });
					chk[a][b + c - C][C] = 1;
				}
				else if(b + c <= C){
					if (!chk[a][0][b + c]) {
						q.push({ a, 0, b + c });
						chk[a][0][b + c];
					}
				}
			}
			//b a
			if (a != A) {
				if (b + a > A && !chk[A][b + a - A][c]) {
					q.push({ A, b + a - A, c });
					chk[A][b + a - A][c] = 1;
				}
				else if(b + a <= A){
					if (!chk[b + a][0][c]) {
						q.push({ b + a, 0, c });
						chk[b + a][0][c] = 1;
					}
				}
			}
		}
		if (c) {
			//c a
			if (a != A) {
				if (c + a > A && !chk[A][b][c + a - A]) {
					q.push({ A, b, c + a - A });
					chk[A][b][c + a - A] = 1;
				}
				else if(c + a <= A){
					if (!chk[c + a][b][0]) {
						q.push({ c + a, b, 0 });
						chk[c + a][b][0] = 1;
					}
				}
			}
			//c b
			if (b != B) {
				if (c + b > B && !chk[a][B][c + b - B]) {
					q.push({ a, B, c + b - B });
					chk[a][B][c + b - B] = 1;
				}
				else if(c + b <= B){
					if (!chk[a][c + b][0]) {
						q.push({ a, c + b, 0 });
						chk[a][c + b][0] = 1;
					}
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i : ans)
		printf("%d ", i);
}