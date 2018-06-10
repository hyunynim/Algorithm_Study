#include<cstdio>
#include<stack>

using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int tt = a / b;
	a %= b;
	a *= 10;
	stack<int> res[2];
		res[1].push(a);
		int top;
		while (res[0].size()< 2005 && res[1].size()) {
			top = res[1].top();
			res[1].pop();
			if (top % b) {
				if (res[1].size()) {
					int tmp = res[1].top();
					res[1].pop();
					tmp += top*10;
					res[1].push(tmp);
				}
				else
					res[1].push((top%b)*10);
			}
			res[0].push(top / b);
		}
		while (res[0].size()) {
			res[1].push(res[0].top());
			res[0].pop();
		}


	printf("%d", tt);
	if (res[1].size() == 1 && res[1].top() == 0)
		return 0;
	printf(".");
	int ccnt = 0;
	while (res[1].size() && ccnt <= 2000) {
		printf("%d", res[1].top());
		++ccnt;
		res[1].pop();
	}
}

/*comment*/
//vector의 자료형의 char였음