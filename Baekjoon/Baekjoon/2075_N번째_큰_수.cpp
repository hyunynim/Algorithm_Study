#include<cstdio>
#include<deque>
#include<algorithm>

using namespace std;

int main() {
	int n, tmp;
	scanf("%d", &n);
	deque<int> seq;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &tmp);
			seq.push_back(tmp);
		}
		if (i != 0) {
			sort(seq.begin(), seq.end());
			for (int j = 0; j < n; ++j)
				seq.pop_front();
		}
	}
	printf("%d", seq.front());
}

/*comment*/
//진짜 어렵게 생각했는데 그냥 슬라이딩 윈도우 기법의 일종이라고 보면 될듯