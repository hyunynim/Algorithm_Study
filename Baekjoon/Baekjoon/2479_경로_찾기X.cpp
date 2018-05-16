#include<cstdio>
#include<vector>

using namespace std;
int n, k;
int num[1 << 10] = { 0 }, code[1 << 10] = { 0 };//num : 1���� // code : 0101010
vector<int> haming[1 << 5];

int HamingDistance(int a, int b) {
	int res = 0;
	int c = a ^ b;
	for (int i = 0; i < k; ++i) {
		if (c & (1 << i))
			res++;
	}
	return res;
}



int main() {
	scanf("%d %d", &n, &k);
	int tmp;
	for (int i = 0; i < n; ++i) {
		for (int j = k - 1; j >= 0; --j) {
			scanf("%1d", &tmp);
			if (tmp) {
				code[i] |= (1 << j);
				num[i]++;
			}
		}
		haming[num[i]].push_back(i);
	}
	int a, b;
	
	scanf("%d %d", &a, &b);

	bool reverse = 0;
	if (a > b) {
		int tmp = a;
		a = b;
		b = a;
		reverse = 1;
	}
	--a;
	--b;

	for (int i = a; i <= b; ++i) {
		if (haming[i].size() == 0) {
			printf("-1");
			return 0;
		}
	}

	
}


/*comment*/
//code�� ���̰� �þ�� ��츸 ��������
//code�� ���� ���̰� �پ����ٰ� �þ�� �� �ʿ䵵 ���� �� ����
//-> iteration ���� recursion���� �ٽ� ���� �ϴ� �ڵ��� ������ �ٽ� �����غ���