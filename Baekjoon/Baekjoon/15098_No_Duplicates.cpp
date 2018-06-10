#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int main() {
	char msg[1234];
	vector<string> seq;
	string tmp;
	while (~scanf("%s", msg)) {
		tmp = msg;
		for (int i = 0; i < seq.size(); ++i) {
			if (seq[i] == tmp) {
				printf("no");
				return 0;
			}
		}
		seq.push_back(tmp);
	}
	printf("yes");
}