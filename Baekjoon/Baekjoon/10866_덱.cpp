#include <iostream>
#include <deque>
#include <string.h>

using namespace std;

int main() {
	int t, oper;
	char command[15];
	scanf("%d", &t);
	deque <int> q;

	for (int i = 0; i < t; i++) {
		scanf("%s", command);
		if (strcmp(command, "push_front") == 0) {
			scanf("%d", &oper);
			q.push_front(oper);
		}
		else if (strcmp(command, "push_back") == 0) {
			scanf("%d", &oper);
			q.push_back(oper);
		}

		else if (strcmp(command, "pop_front") == 0) {
			if (q.size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", q.front());
				q.pop_front();
			}
		}
		else if (strcmp(command, "pop_back") == 0) {
			if (q.size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", q.back());
				q.pop_back();
			}
		}
		else if (strcmp(command, "size") == 0)
			printf("%d\n", q.size());

		else if (strcmp(command, "empty") == 0)
			printf("%d\n", q.empty());

		else if (strcmp(command, "front") == 0) {
			if (q.size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", q.front());
			}
		}

		else if (strcmp(command, "back") == 0) {
			if (q.size() == 0)
				printf("-1\n");
			else {
				printf("%d\n", q.back());
			}
		}

	}
}