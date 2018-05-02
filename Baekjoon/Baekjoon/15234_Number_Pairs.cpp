#include <cstdio>
#include <vector>

using namespace std;

int n, k;
vector <int> seq;
int res = 0;

void CheckSum(vector<int> &picked) {
	int sum = 0;
	for (int i = 0; i < picked.size(); ++i)
		sum += picked[i];
	if (sum == k)
		res++;
}

void Pick(vector <int> & picked, int toPick, int prev) {
	if (toPick == 0)
		CheckSum(picked);
	else {
		int next = picked.empty() ? 0 : prev + 1;
		for (int i = next; i < n; ++i) {
			picked.push_back(seq[i]);
			Pick(picked, toPick - 1, i);
			picked.pop_back();
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	int tmp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	vector <int> v_tmp;
	Pick(v_tmp, 2, 0);
	printf("%d", res);
}