#include<cstdio>
#include<functional>
#include<queue>

using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int>> seq;
	int n, tmp;
		scanf("%d", &n);
		for (int j = 0; j < n; ++j) {
			scanf("%d", &tmp);
			seq.push(tmp);
		}

		int res = 0;
		tmp = 0;

		while (seq.size() != 1) {
			tmp += seq.top();
			seq.pop();
			tmp += seq.top();
			seq.pop();
			seq.push(tmp);
			res += tmp;
			tmp = 0;
		}
		printf("%d\n", res);
		seq.pop();
		tmp = 0;
	
}


/*comment*/