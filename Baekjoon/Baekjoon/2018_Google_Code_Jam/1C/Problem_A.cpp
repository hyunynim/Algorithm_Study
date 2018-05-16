#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, l;
		int cnt['z' - 'a' + 1] = { 0 };
		vector<string> seq;
		string tmp;

		printf("Case #%d: ", i + 1);
		
		scanf("%d %d", &n, &l);
		
		for (int j = 0; j < n; ++j) {
			scanf("%s", tmp);
			seq.push_back(tmp);
			for (int k = 0; k < l; ++k)
				cnt[tmp.at(k) - 'A']++;
		}

		int useA = 0;
		for (int j = 0; j < 26; ++j) {
			if (cnt[j])
				useA++;
		}

		if (l == 1 || n == l * useA ) {
			printf("-\n");
			continue;
		}
		
		//새로운 문자열 추출에 문제
		

	}

}