#include<cstdio>
#include<deque>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	deque<int> seq;
	for (int i = 1; i <= n; ++i)
		seq.push_back(i);
	while (seq.size() != 1) {
		seq.pop_front();
		seq.push_back(seq.front());
		seq.pop_front();
	}
	printf("%d", seq.front());
}