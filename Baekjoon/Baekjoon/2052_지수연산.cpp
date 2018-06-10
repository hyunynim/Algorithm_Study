#include<cstdio>
#include<stack>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	stack<char> res[2];
	if (n == 1) {
		printf("0.5");
		return 0;
	}
	else {
		res[1].push(5);
		int top;
		for (int i = 1; i < n; ++i) {
			while (res[1].size()) {
				top = res[1].top();
				res[1].pop();
				if (top % 2) {
					if (res[1].size()) {
						int tmp = res[1].top();
						res[1].pop();
						tmp += 10;
						res[1].push(tmp);
					}
					else
						res[1].push(10);
				}
				res[0].push(top / 2);
			}
			while (res[0].size()) {
				res[1].push(res[0].top());
				res[0].pop();
			}
		}
	}
	printf("0.");
	while (res[1].size()) {
		printf("%d", res[1].top());
		res[1].pop();
	}
}