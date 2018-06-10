#include<cstdio>
#include<deque>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int c;
		scanf("%d", &c);
		char ch;
		deque<char> seq;
		getchar();
		for (int j = 0; j < c; ++j) {
			ch = getchar(); getchar();
			if (j == 0)
				seq.push_back(ch);
			else {
				if (seq.front() < ch)
					seq.push_back(ch);
				else
					seq.push_front(ch);
			}
		}
		while (seq.size()) {
			printf("%c", seq.front());
			seq.pop_front();
		}
		printf("\n");
	}
}