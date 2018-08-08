#include<cstdio>
#include<stack>

using namespace std;
char msg[1000010];
int n, strLen;
stack<char> left, right;
char ans[623456];

int main() {
	scanf("%s %d", msg, &n);
	getchar();
	for (int i = 0; msg[i] != '\0'; ++i) {
		left.push(msg[i]);
		++strLen;
	}
	char opt[123];
	for (int i = 0; i < n; ++i) {
		fgets(opt, 12, stdin);
		if (opt[0] == 'L' && left.size()) {
			right.push(left.top());
			left.pop();
		}
		else if (opt[0] == 'D' && right.size()) {
			left.push(right.top());
			right.pop();
		}
		else if (opt[0] == 'B' && left.size())
			left.pop();
		
		else if(opt[0] == 'P'){
			left.push(opt[2]);
	
		}
	}
	while (left.size()) {
		right.push(left.top());
		left.pop();
	}
	int i;
	for (i = 0; right.size(); ++i) {
		ans[i] = right.top();
		right.pop();
	}
	ans[i+1] = '\0';
	printf("%s", ans);
}