#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int main() {
	int t, oper;
	char command[10];
	scanf("%d", &t);
	stack <int> q;

	for (int i = 0; i < t; i++) {
		scanf("%s", command);
		if (strcmp(command, "push") == 0) {
			scanf("%d", &oper);
			q.push(oper);
		}

		else if (strcmp(command, "pop") == 0) {
			if (q.size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", q.top());
				q.pop();
			}
		}

		else if (strcmp(command, "size") == 0)
			printf("%d\n", q.size());

		else if (strcmp(command, "empty") == 0)
			printf("%d\n", q.empty());

		else if (strcmp(command, "top") == 0) {
			if (q.size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", q.top());
			}
		}
	}
}