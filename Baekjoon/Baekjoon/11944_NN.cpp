#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

int main() {
	int n, m;
	queue <int> num;
	stack <int> tmp;
	scanf("%d %d", &n, &m);
	
	int n_tmp = n;

	while (n_tmp > 0) {
		tmp.push(n_tmp % 10);
		n_tmp /= 10;
	}

	int num_size = tmp.size();

	while (tmp.size()) {
		num.push(tmp.top());
		tmp.pop();
	}

	int i = 0;
	while (i < (m < n*num_size ? m : n*num_size)) {
		printf("%d", num.front());
		num.push(num.front());
		num.pop();
		i++;
	}
}

/*commnet*/
//ť/���� �̿��غôµ� �ȵ� Ʋ���� ��?
//n*n���� �ƴ϶� n�� ���
//Ʋ��
//�ڸ��� ��� ���ϰ� �����
//����