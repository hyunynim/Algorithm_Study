#include<cstdio>
#include<deque>
#include<string>
#include<stack>

using namespace std;


int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		char msg[1234];
		string strTmp;
		deque<string> seq;
		bool isAlpha = 0;
		scanf("%d", &n);
		for (int j = 0; j < n; ++j) {
			scanf("%s", msg);
			if (isAlpha)
				printf("%s ", msg);
			if (msg[0] == '#');
			else {
				isAlpha = 1;
				strTmp = msg;
				seq.push_back(strTmp);
			}
			if(isAlpha != 1) {
				strTmp = msg;
				seq.push_back(strTmp);
			}
		}
		if (isAlpha) {
			printf("%s ", seq.back().c_str());
			seq.pop_back();
		}
		while (seq.size()) {
			printf("%s ", seq.front().c_str());
			seq.pop_front();
		}
		printf("\n");
		seq.clear();
	}
}

/*comment*/
//왜틀린지 모르겠어서 그냥 갈아엎음