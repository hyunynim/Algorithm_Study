#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> price;
int cache[1234];

int maxPrice(int n) {
	if (n < 0)
		return 0;
	else {
		int & ans = cache[n];
		int res = 0;
		if (ans != 0)
			return ans;

		for (int i = 1; i <= n; ++i) {
			res = max(res, maxPrice(n - i) + price[i]);
		}
		ans = res;
		return res;
	}
}

int main() {
	int n, tmp;
	scanf("%d", &n);
	price.push_back(0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		price.push_back(tmp);
	}
	printf("%d", maxPrice(n));

}

/*comment*/
//DP 필요없을 줄 알았는데 몇몇 반례가 생김
//5 1 4 15 20 1 등
//DP 적용했으나 시간초과
//DP를 어떤식으로 해야 효율적으로 적용할 수 있을지 잘 모르겠음..