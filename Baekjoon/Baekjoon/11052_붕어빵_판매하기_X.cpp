#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int calcMax(int n, int * price) {
	if (n == 0)
		return 0;
	vector <int> tmp, tmpMax;
	int max = 0;
	for (int i = 0; i < n; ++i) {
		if (price[i] > max) {
			max = price[i];
			tmpMax.clear();
			tmpMax.push_back(i);
		}
		else if (price[i] == max)
			tmpMax.push_back(i);
	}
	max = 0;
	for (int i = 0; i < tmpMax.size(); i++) {
		tmp.push_back(n / (tmpMax[i] + 1)*price[tmpMax[i]] + calcMax(n % (tmpMax[i] + 1), price));
	}
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] > max)
			max = tmp[i];
	}
	return max;
}

int main() {
	int n;
	scanf("%d", &n);
	int * price = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &price[i]);
	printf("%d", calcMax(n, price));
}

/*comment*/
//DP �ʿ���� �� �˾Ҵµ� ��� �ݷʰ� ����
//5 1 4 15 20 1 ��
//DP ���������� �ð��ʰ�
//DP�� ������� �ؾ� ȿ�������� ������ �� ������ �� �𸣰���..