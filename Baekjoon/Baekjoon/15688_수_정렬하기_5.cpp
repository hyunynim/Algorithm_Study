#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> seq;
	int n, tmp;
	scanf("%d", &n);
	for(int i = 0; i<n; ++i){
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	sort(seq.begin(), seq.end());
	for (int i = 0; i<n; ++i) 
		printf("%d\n", seq[i]);
}