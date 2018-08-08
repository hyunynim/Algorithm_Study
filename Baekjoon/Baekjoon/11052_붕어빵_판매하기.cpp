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
//DP �ʿ���� �� �˾Ҵµ� ��� �ݷʰ� ����
//5 1 4 15 20 1 ��
//DP ���������� �ð��ʰ�
//DP�� ������� �ؾ� ȿ�������� ������ �� ������ �� �𸣰���..