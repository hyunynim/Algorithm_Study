#include<cstdio>
#include <stack>

using namespace std;

int main() {
	int n, m;
	stack <char> res;
	scanf("%d %d", &m, &n);
	if (m == 0) {
		printf("0");
		return 0;
	}
	while (m > 0) {
		if (m % n < 10)
			res.push(m%n + '0');
		else 
			res.push(m%n - 10 + 'A');
		m /= n;
	}
	while (res.size()) {
		printf("%c", res.top());
		res.pop();
	}
}

/*comment*/
//0을 고려 안함