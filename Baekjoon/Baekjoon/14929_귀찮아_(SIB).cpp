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
//�ð��ʰ� ���ƾ��� �� loop��
//�ð��ʰ�
//overflow �����̿��� �Ѥ�...