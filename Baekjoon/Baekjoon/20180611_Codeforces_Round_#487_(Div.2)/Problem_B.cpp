#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
#include<functional>

typedef long long ll;

using namespace std;

int n, p;

int main() {
	scanf("%d %d", &n, &p);
	char msg[2345];
	scanf("%s", msg);
	if (n == p) {
		printf("No");
		return 0;
	}
	int j = 0;
	for (int i = 0; i < n - p; ++i) {
		if (msg[i] == msg[i + p])
			continue;
		else {
			j = 1;
			if (msg[i] == '.' && msg[i + p] == '1') {
				msg[i] = '0';
				break;
			}
			else if (msg[i] == '.' && msg[i + p] == '0') {
				msg[i] = '1';
				break;
			}
			else if (msg[i] == '0' && msg[i + p] == '.') {
				msg[i + p] = '1';
				break;
			}
			else if (msg[i] == '1' && msg[i + p] == '.') {
				msg[i + p] = '0';
				break;
			}
			
		}
	}
	if (j) {
		for (int i = 0; msg[i] != '\0'; ++i) {
			if (msg[i] == '.')
				msg[i] = '0';
		}
		printf("%s", msg);
		return 0;
	}
	printf("No");
}

/*comment*/
//문제를 아예 잘못이해했네; 하나라도 다른게 있으면 되는듯
//period 1 일때 잘못 출력
//n == p 인 경우 No처리하는게 맞는듯
//또 잘못 이해한듯 다시 해보자;
//미친 진짜 잘못이해함 말도안돼..
//애초에 다른게 있을경우 처리 안해줌
//테스트 통과 말도안됨 진짜 아 오바다... 영어좀 많이 읽자 