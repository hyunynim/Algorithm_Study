#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>

using namespace std;

int main() {
	int n, k, tmp;
	scanf("%d %d", &n, &k);
	vector<pair<int, queue<int>>> student(n);
	int cntEx = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		bool isEx = 1;
		for (int j = 0; student[j].second.size(); ++j) {
			if (student[j].first == tmp) 
			{
				student[j].second.push(i + 1);
				isEx = 0;
				break;
			}
		}
		if (isEx) {
			student[cntEx].first = tmp;
			student[cntEx].second.push(i + 1);
			++cntEx;
		}
	}
	if (cntEx < k) {
		printf("NO");
		return 0;
	}
	else {
		printf("YES\n");
		for (int i = 0; i < k; ++i) {
			printf("%d ", student[i].second.front());
		}
	}
	
}

/*comment*/
//YES 출력을 안함;;;