#include<cstdio>
#include<cmath>
#define INT_INF 987654321
int main() {
	int n, l;
	scanf("%d %d", &n, &l);
	int i, j, cnt1 = 0, cnt2 = 0;
	double dtmp;
	dtmp = (1 + sqrt(1 + 8 * n)) / 2.0;
	if (dtmp != (int)dtmp)
		cnt1 = INT_INF;
	else
		cnt1 = (int)dtmp;

	for (i = l; i < 102; ++i) {
		if ((n - (i)*(i + 1) / 2) % i == 0 && i>=l && i <= 100) {
			break;
		}
	}
	cnt2 = (n - (i)*(i + 1) / 2) / i;
	if (cnt1 <= i && cnt1 >= l && cnt1 <= 100) {
		for (int i = 0; i < cnt1; ++i)
			printf("%d ", i);
	}
	else {
		if (cnt2 < 0 || i > 100)
			printf("-1");
		else {
			for (j = 0; j < i; ++j)
				printf("%d ", cnt2 + j + 1);
		}
	}
}


/*comment*/
//어디가 틀린걸까
//출력 개수에 대한 case 분류