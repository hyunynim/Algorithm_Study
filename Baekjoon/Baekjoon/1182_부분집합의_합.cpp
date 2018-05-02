#include <stdio.h>
#include <vector>

using namespace std;
int n, s, tmp, res = 0;
vector <int> seq;

void CheckSum(vector <int> &picked) {
	int sum = 0;
	for (int i = 0; i < picked.size(); ++i)
		sum += picked[i];
	if (s == sum)
		res++;
}

void Pick(vector <int> &picked, int toPick, int prev) {
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
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	
	vector <int> tmp;
	for (int i = 1; i <= n; ++i) {
		Pick(tmp, i, 0);
		tmp.clear();
	}
	printf("%d", res);
}