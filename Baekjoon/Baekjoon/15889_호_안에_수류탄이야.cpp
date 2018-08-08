#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<string.h>

using namespace std;
vector<int> pos;
int power[1000010];
int cache[30101];
int n;


int DFS(int start) {
	if (pos[start] == pos.back())
		return 1;
	else {
		int & ans = cache[start];
		if (ans != -1)
			return ans;
		int cur = pos[start];
		for (int i = start + 1; i < pos.size(); ++i) {
			if (cur + power[cur] >= pos[i]) {
				if (DFS(i)) {
					ans = 1;  return ans;
				}
			}
		}
		ans = 0;
		return ans;
	}
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	pos.resize(n);
	int tmp;
	int posMax = 0;
	for (int i = 0; i < n; ++i) 
		scanf("%d", &pos[i]);
	
	if (n > 1) {
		for (int i = 0; i < n - 1; ++i) {
			scanf("%d", &tmp);
			power[pos[i]] = max(tmp, power[pos[i]]);
		}
		sort(pos.begin(), pos.end());
	}
		if (DFS(0)) printf("권병장님, 중대장님이 찾으십니다");
		else printf("엄마 나 전역 늦어질 것 같아");
}

/*comment*/
//data를 pair로 처리하고 sort 시킴
//틀림
//n == 1 일 때 따로 처리
//정렬은 속도를 높이는데 사용될 정도 일 듯
//i번 좌표에 있는 power를 power[i]에 저장하고 항상 최댓값만 저장하게 끔 만듦
// -> 어차피 사거리 0안에 던질 수 있을테니
//그다음 pos만 정렬 + 중복제거 해서 power에서 부터 끌어와서 쓰면?
//틀림
//정렬 + 중복제거 없앰 power만 pos별로 저장
//왜 틀리는걸까 하...
//욱제의 좌표가 0인데 이게 과연 항상 맨 처음에 저장될까? 맞나봄/
//마지막에 들어오는 좌표는 항상 n번째 전우? 맞는듯
//배열의 마지막이 아니어도 N번째 전우와 같은 곳에 있는 전우가 있을 수 있음
//틀림
//cache 사이즈가 1만으로 되어있었음;;;;
//내생각엔 cache 사이즈 때문에 계속 틀렸습니다 뜬듯