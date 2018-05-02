#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int dp[305][2];
int a[305];
int rec(int x, int y)
{
	if (x == 0) {
		if (y == 1) return a[x];
		return 0;
	}
	if (x == 1 && y == 1) return a[x];
	int& ret = dp[x][y];
	if (ret)return ret;
	if (y) {
		ret = a[x] + max(rec(x - 2, 1), rec(x - 2, 0));
	}
	else {
		ret = a[x] + rec(x - 1, 1);
	}
	return ret;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i<n; ++i)scanf("%d", &a[i]);
	printf("%d",max(rec(n-1,0),rec(n-1,1)));
}
/*comment*/
//왜 답이 틀리게 나오는지를 모르겠음
//재귀함수 갈아엎음
//시간초과
//메모이제이션 적용해봄
//틀림 -> 중복 case가 나오는듯
//0 -> 2 와 1 -> 2 하면 둘다 n==2 인 상태로 저장됨
//중복case 제거 필요
//두개 함수, 두개 cache 이용
//시간초과 