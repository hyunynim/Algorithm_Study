#include<cstdio>
#include<algorithm>
#include<deque>
#define pb(a) push_back((a))
#define mp(a,b) make_pair((a),(b))
using namespace std;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long lld;
typedef unsigned long long ulld;

const int INF = 987654321;

char op[100005];
char arr[500005];
int N;
bool isdigit(char a) {
	return '0' <= a && a <= '9';
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s ", op);
		scanf("%d", &N);
		scanf("%s", arr);
		N = 0;
		int idx = 0;
		deque<int> dq;
		while (arr[idx]) {
			if (isdigit(arr[idx])) {
				int x = 0;
				while (arr[idx] && isdigit(arr[idx])) {
					x *= 10;
					x += arr[idx] - '0';
					++idx;
				}
				++N;
				dq.push_back(x);
			}
			else ++idx;
		}
		int fr = 1;
		bool valid = true;
		for (int i = 0; op[i]; ++i) {
			if (op[i] == 'R')fr ^= 1;
			else {
				if (!dq.empty() && !fr) {
					dq.pop_back();
				}
				else if (!dq.empty() && fr) {
					dq.pop_front();
				}
				else valid = false;
			}
		}
		if (valid) {
			printf("[");
			while (!dq.empty()) {
				if (fr) {
					printf("%d", dq.front());
					dq.pop_front();
				}
				else {
					printf("%d", dq.back());
					dq.pop_back();
				}
				if (!dq.empty())printf(",");
			}
			printf("]");
		}
		else {
			printf("error");
		}
		printf("\n");
	}
}



/*commnet*/
//deque를 안쓰고 풀어보려고 했지만 사이즈 0 체크가 제대로 안되는듯
//갈아엎음
//숫자 입력받는 과정에서 개고생함
//근데 틀림 왜?
//다시 갈아엎음