#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	char msg[5001];
	int cnt['z' - 'a' + 1] = { 0 };
	while (fgets(msg, 5000, stdin) != NULL) {
		int i = 0;
		while (msg[i] != '\0') {
			if ('a' <= msg[i] && msg[i] <= 'z')
				cnt[msg[i] - 'a']++;
			++i;
		}
	}
	int max = -1;
	vector <char> res;
	for (int i = 0; i < 26; ++i) {
		if (max < cnt[i]) {
			max = cnt[i];
			res.clear();
			res.push_back(i + 'a');
		}
		else if (max == cnt[i])
			res.push_back(i + 'a');
	}
	for (int i = 0; i < res.size(); ++i)
		printf("%c", res[i]);
}