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
//큐/스택 이용해봤는데 안됨 틀림뜸 왜?
//n*n번이 아니라 n번 출력
//틀림
//자리수 고려 안하고 출력함
//맞음