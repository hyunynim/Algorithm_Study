#include<cstdio>
#include<queue>
#include<stack>
using namespace std;

int main() {
	priority_queue<double> seventh;
	int n;
	double score;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &score);
		if (seventh.size() != 7)
			seventh.push(score);
		else {
			if (seventh.top() > score) {
				seventh.pop();
				seventh.push(score);
			}
		}
	}
	stack<double> res;
	while (seventh.size()) {
		res.push(seventh.top());
		seventh.pop();
	}
	while (res.size()) {
		printf("%.3lf\n", res.top());
		res.pop();
	}
}

/*comment*/
//������ �ְ� ���� ����
//�������� �ƴ϶� �ִ� ���ؼ� ������ ����