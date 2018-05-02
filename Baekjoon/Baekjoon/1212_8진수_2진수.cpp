#include <cstdio>
#include <stack>

using namespace std;

int main() {
	char msg[340000];
	scanf("%s", msg);
	if (msg[0] == '0' && msg[1] == '\0') {
		printf("0");
		return 0;
	}
	int i = 0;
	while (msg[i] != '\0') {
		int tmp = msg[i] - '0';
		if (i == 0) {
			stack <int> num;
			while (tmp > 0) {
				num.push(tmp % 2);
				tmp /= 2;
			}
			while (num.size()) {
				printf("%d", num.top());
				num.pop();
			}
		}
		else {
			switch (tmp) {
			case 0:
				printf("000");
				break;
			case 1:
				printf("001");
				break;
			case 2:
				printf("010");
				break;
			case 3:
				printf("011");
				break;
			case 4:
				printf("100");
				break;
			case 5:
				printf("101");
				break;
			case 6:
				printf("110");
				break;
			case 7:
				printf("111");
				break;
			}
		}
		++i;
	}
}

/*comment*/
//0을 제대로 출력 안해줌