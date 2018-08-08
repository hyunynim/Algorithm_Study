#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int cache[10010];
vector<int> price;
int n, k, tmp;

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 0; i<10005; ++i)
		cache[i] = 987654321;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		price.push_back(tmp);
		if(tmp <= 10000)
			cache[tmp] = 1;
	}
	sort(price.begin(), price.end());
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < n && price[j] <= i; ++j) {
				cache[i] = min(cache[i], cache[i - price[j]] + 1);
		}
	}
	printf("%d", cache[k] == 987654321 ? -1 : cache[k]);
}

/*comment*/
//시간초과
//동전을 한번에 여러 개 고르면?
//틀림
//갈아엎고 bottom-up ㄱㄱ
//초기화 잘못함
//동전이 오름차순으로 들어온다는 보장이 없음