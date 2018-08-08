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
//������ �ƿ� �߸������߳�; �ϳ��� �ٸ��� ������ �Ǵµ�
//period 1 �϶� �߸� ���
//n == p �� ��� Noó���ϴ°� �´µ�
//�� �߸� �����ѵ� �ٽ� �غ���;
//��ģ ��¥ �߸������� �����ȵ�..
//���ʿ� �ٸ��� ������� ó�� ������
//�׽�Ʈ ��� �����ȵ� ��¥ �� ���ٴ�... ������ ���� ���� 