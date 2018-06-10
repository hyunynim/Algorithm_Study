#include<cstdio>
#include<vector>

using namespace std;

vector<int> seq(20);

void Reverse(int a, int b) {
	int * tmp = new int[b - a + 1];
	for (int i = a; i <= b; ++i) {
		tmp[b - i] = seq[i];
	}
	for (int i = a; i <= b; ++i) {
		seq[i] = tmp[i - a];
	}
	delete[] tmp;
}

int main() {
	for (int i = 1; i <= 20; ++i)
		seq[i-1] = i;
	int a, b;
	for (int i = 0; i < 10; ++i) {
		scanf("%d %d", &a, &b);
		Reverse(a - 1, b - 1);
	}
	for (int i = 0; i < 20; ++i)
		printf("%d ", seq[i]);
}