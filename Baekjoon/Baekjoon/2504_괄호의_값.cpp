#include<cstdio>
#include<stack>

using namespace std;

int main() {
	char msg[40];
	stack<char> braket;
	bool isOpen = 0;
	scanf("%s", msg);
	long long mul = 1;
	long long i = 0, res = 0, inner = 0;
	while (msg[i] != '\0') {
		if (msg[i] == '(') {
			if (!isOpen)
				isOpen = 1;
			braket.push(msg[i]);
			mul *= 2;
		}
		else if (msg[i] == '[') {
			if (!isOpen)
				isOpen = 1;
			braket.push(msg[i]);
			mul *= 3;
		}
		else {
			if (braket.empty()) {
				printf("0");
				return 0;
			}
			if (msg[i] == ')' && braket.top() == '(') {
				if (isOpen) {
					isOpen = 0;
					res += mul;
				}
				mul /= 2;
				braket.pop();
			}
			else if(msg[i] == ']' && braket.top() == '[') {
				if (isOpen) {
					isOpen = 0;
					res += mul;
				}
				mul /= 3;
				braket.pop();
			}
			else {
				printf("0");
				return 0;
			}
		}
		++i;
	}
	if(braket.size()) {
		printf("0");
		return 0;
	}
	printf("%d", res);
}

/*comment*/
//´ÝÈ÷´Â °ýÈ£ Á¦´ë·Î check ¾ÈÇÔ