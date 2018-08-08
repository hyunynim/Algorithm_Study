#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

#define INF -1e9
int cache[321][3];
int score[321];
int n;

int up(int start, int cnt) {
	if (start >= n)
		return INF;
	if (start == n - 1)
		return score[n - 1];
	else {
		int & ans = cache[start][cnt];
		if (ans != -1)
			return ans;
		
		ans = score[start];
		if (cnt < 2)
			ans = max({ up(start + 1, cnt + 1) + ans, up(start + 2, 1) + ans });
		else
			ans += up(start + 2, 1);
		return ans;
	}
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &score[i]);
	printf("%d", max(up(0, 1), up(1, 1)));
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
//맨 처음에 첫번째 계단을 밟는 경우 vs 두번째 계단을 밟는 경우