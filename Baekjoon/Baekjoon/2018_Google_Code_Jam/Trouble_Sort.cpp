#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> * TroubleSort(vector <int> num);
void ChangeNum(int * a, int * b);
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i<t; ++i) {
		int n;
		vector <int> num;
		scanf("%d", &n);
		for (int j = 0; j<n; ++j) {
			int tmp;
			scanf("%d", &tmp);
			num.push_back(tmp);
		}
		printf("Case #%d: ", i + 1);
		vector <int> * troubleSort = new vector<int>;
		troubleSort = TroubleSort(num);

		sort(num.begin(), num.end());

		int chk = -1;
		for (int i = 0; num.begin() + i != num.end(); ++i) {
			if (num[i] != (*troubleSort)[i]) {
				chk = i;
				break;
			}
		}
		if (chk == -1)
			printf("OK\n");
		else
			printf("%d\n", chk);
	}
}

vector <int> * TroubleSort(vector <int> num) {
	vector <int> * res = new vector <int>;

	for (int i = 0; num.begin() + i != num.end(); ++i)
		res->push_back(num[i]);

	for (int j = 0; j < res->size(); ++j) {
		for (int i = 0; res->begin() + i + 2 != res->end(); ++i) {
			if (*(res->begin() + i) > *(res->begin() + i + 2)) {
				int a = *(res->begin() + i);
				int b = *(res->begin() + i + 2);
				*(res->begin() + i) = b;
				*(res->begin() + i + 2) = a;
			}
		}
	}
		return res;
}

void ChangeNum(int * a, int * b) {
	int c = *a;
	*a = *b;
	*b = c;
}