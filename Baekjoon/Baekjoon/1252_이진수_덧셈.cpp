#include<cstdio>
#include<stack>

using namespace std;
int main() {
	stack <int> num1, num2, res;
	char msg[2][1230];
	scanf("%s %s", msg[0], msg[1]);
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; msg[i][j] != '\0'; ++j) {
			if (i == 0)
				num1.push(msg[i][j] - '0');
			else
				num2.push(msg[i][j] - '0');
		}
	}
	int isUp = 0;
	while (num1.size() && num2.size()) {
		res.push((num1.top() + num2.top() + isUp) % 2);
		isUp = (num1.top() + num2.top() + isUp) / 2;
		num1.pop();
		num2.pop();
	}
	while (num1.size()) {
		res.push((num1.top() + isUp) % 2);
		isUp = (num1.top() + isUp) / 2;
		num1.pop();
	}
	while (num2.size()) {
		res.push((num2.top() + isUp) % 2);
		isUp = (num2.top() + isUp) / 2;
		num2.pop();
	}

	if (isUp)
		res.push(1);

	int cnt = 0;
	while (res.size()) {
		if (res.top() == 0 && cnt == 0 && res.size() != 1) {
			res.pop();
			continue;
		}
		printf("%d", res.top());
		++cnt;
		res.pop();
	}
}

/*comment*/
//오타있는채로 계속 넣었음