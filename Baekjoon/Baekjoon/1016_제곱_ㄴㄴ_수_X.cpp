#include <iostream>
#include <math.h>
#include <vector>
typedef long long ll;
using namespace std;

bool chkSq[5000000] = { 0 };
int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	
	for(int i = 2; i <= (int)sqrt(b); ++i){
		ll k = i*i;
		ll start = ((a - 1) / k + 1)*k;
		for (ll j = start; j <= b; j += k)
			chkSq[(int)(j - a)] = 1;
	}
	int sz = (int)(b - a + 1);
	int ans = 0;
	for (int i = 0; i<sz; ++i)
		ans += chkSq[i];
	printf("%d", sz - ans);
}
/*commnet*/
//�ð��ʰ�
//�Ҽ��� ������ üũ�ϵ��� �ٲ�
//�ð��ʰ�