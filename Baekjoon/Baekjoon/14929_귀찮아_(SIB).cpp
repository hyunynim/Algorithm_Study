#include <cstdio>
#include <vector>
typedef long long ll;
using namespace std;

ll res = 0, n;
vector <ll> tmp;

int main(){
	scanf("%lld", &n);
	ll itmp;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &itmp);
		tmp.push_back(itmp);
		sum += itmp;
	}
	for (int i = 0; i < n; ++i) {
		sum -= tmp[i];
		res += sum*tmp[i];
	}
	printf("%lld", res);
}

/*comment*/
//시간초과 갈아엎고 걍 loop로
//시간초과
//overflow 때문이였음 ㅡㅡ...