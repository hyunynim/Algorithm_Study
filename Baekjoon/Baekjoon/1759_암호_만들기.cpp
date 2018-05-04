#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;
int l, c;
vector<char> seq;

void PrintPassword(vector<char> &picked) {
	int k = 0;
	for (int i = 0; i < picked.size(); ++i) {
		if (picked[i] == 'a' ||
			picked[i] == 'e' ||
			picked[i] == 'i' ||
			picked[i] == 'o' ||
			picked[i] == 'u')
			++k;
	}
	int e = l - k;
	if (k<1 || picked.size() - k<2) return;
	else {
		for (int i = 0; i < picked.size(); ++i)
			printf("%c", picked[i]);
		printf("\n");
	}
}

void FindPassword(vector<char> &picked, int toPick, int prev) {
	if (toPick == 0)
		PrintPassword(picked);
	else {
		int next = picked.empty() ? 0 : prev + 1;
		for (int i = next; i < c; ++i) {
			picked.push_back(seq[i]);
			FindPassword(picked, toPick - 1, i);
			picked.pop_back();
		}
	}
}

int main() {
	scanf("%d %d", &l, &c);
	char msg[1000];
	getchar();
	fgets(msg, 999, stdin);
	int i = 0;
	while (msg[i] != '\0') {
		if ('a' <= msg[i] && msg[i] <= 'z')
			seq.push_back(msg[i]);
		++i;
	}
	sort(seq.begin(), seq.end());
	vector<char> vtmp;
	FindPassword(vtmp, l, 0);
}

/*comment*/
//모음 / 자음 조건 안맞춤