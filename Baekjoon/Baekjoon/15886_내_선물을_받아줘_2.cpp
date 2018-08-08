#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
typedef long long ll;
using namespace std;

int n; char msg[1234];
int cache[1010];


int main() {
	scanf("%d %s", &n, &msg);
	string str = msg;
	ll it = str.find("EW");;
	int ans = 0;
	while (it != string::npos) {
		++ans;
		str.erase(it, 2);
		str.insert(str.begin() + it, '#');
		it = str.find("EW");
	}

	printf("%d", ans ? ans : 1);
}