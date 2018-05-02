#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int cnt[8001] = { 0 };
	int sum = 0;
	vector <int> data;
	for (int i = 0; i<n; ++i) {
		int tmp;
		scanf("%d", &tmp);
		data.push_back(tmp);
		cnt[tmp + 4000]++;
		sum += tmp;
	}
	int avg;
	if (sum > 0)
		avg = (int)((double)sum / n + 0.5);
	else
		avg = (int)((double)sum / n - 0.5);
	int max = 1;
	vector <int> chkMax;
	for (int i = 0; i < 8001; ++i) {
		if (max < cnt[i]) {
			max = cnt[i];
			chkMax.clear();
			chkMax.push_back(i - 4000);
			continue;
		}
		if (max == cnt[i])
			chkMax.push_back(i - 4000);
	}

	printf("%d\n", avg);

	sort(data.begin(), data.end());
	printf("%d\n", data[n / 2]);

	if (chkMax.size() == 1)
		printf("%d\n", chkMax[0]);
	else {
		sort(chkMax.begin(), chkMax.end());
		printf("%d\n", chkMax[1]);
	}
	printf("%d", *(data.end() - 1) - data[0]);
}

/*commnet*/
//왜틀렸는지 모르겠음 걍 갈아엎음
//음수에 대한 반올림 평균과 max = cnt[i]를 안함