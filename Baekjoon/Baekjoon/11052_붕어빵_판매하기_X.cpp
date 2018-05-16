#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

vector <pair<double, int>> price;
int n, maxPrice = 0;

int Sell(int toPick, int pick, int totPrice) {
	if (toPick == 0) {
		return totPrice;
	}
	else {
		for (int i = pick - 1; i >= 1; --i) {
			if (toPick >= i) {
				return Sell(toPick - (toPick/i)*i, (toPick / i)*i, totPrice + (toPick / i)* i * price[i].second);
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	int * res = new int[n + 1];
	double tmp;
	price.push_back(make_pair(0.0, 0));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &res[i]);
		tmp = (double)res[i] / (double)(i + 1);
		price.push_back(make_pair(tmp, res[i]));
	}
	sort(price.begin(), price.end());
	int ans = 0;
	for (int i = 1; i < price.size(); ++i)
		printf("%lf %d\n", price[i].first, price[i].second);
}

/*comment*/
//DP 필요없을 줄 알았는데 몇몇 반례가 생김
//5 1 4 15 20 1 등
//DP 적용했으나 시간초과
//DP를 어떤식으로 해야 효율적으로 적용할 수 있을지 잘 모르겠음..