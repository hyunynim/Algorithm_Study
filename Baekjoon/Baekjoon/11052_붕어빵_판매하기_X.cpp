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
//DP �ʿ���� �� �˾Ҵµ� ��� �ݷʰ� ����
//5 1 4 15 20 1 ��
//DP ���������� �ð��ʰ�
//DP�� ������� �ؾ� ȿ�������� ������ �� ������ �� �𸣰���..