#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	vector<int> l(4);
	for (int i = 0; i < 4; ++i)
		scanf("%d", &l[i]);
	sort(l.begin(), l.end());
	printf("%d", min(l[0], l[1]) * min(l[2], l[3]));
}