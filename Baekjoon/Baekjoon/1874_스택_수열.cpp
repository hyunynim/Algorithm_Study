#include<stack>
#include<vector>
#include<cstdio>
#include<queue>

using namespace std;

int main() {
	stack<int> st;
	queue<int> num;
	vector<int> seq;
	vector<bool> res;
	int n, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
		num.push(i + 1);
	}
	
	int i = 0;
	while (i != seq.size()) {
		if (st.empty()) {
			while (num.front() != seq[i]) {
				st.push(num.front());
				num.pop();
				res.push_back(1);
			}
			st.push(num.front());
			num.pop();
			res.push_back(1);
		}
		else {
			if (st.top() == seq[i]) {

			}
			else if (st.top() > seq[i]) {
				printf("NO");
				return 0;
			}
			else {
				while (num.front() != seq[i]) {
					st.push(num.front());
					num.pop();
					res.push_back(1);
				}
				st.push(num.front());
				num.pop();
				res.push_back(1);
			}
		}
		st.pop();
		res.push_back(0);
		++i;
	}
	for (int i = 0; i < res.size(); ++i) {
		if (res[i])
			printf("+\n");
		else
			printf("-\n");
	}
}