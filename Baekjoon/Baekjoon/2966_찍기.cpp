#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	char msg[1234];
	scanf("%s", msg);
	vector<string> vres;
	string name[3] = { "Adrian", "Bruno", "Goran" };
	int res[3] = { 0 };
	for (int i = 0; msg[i] != '\0'; ++i) {
		if (i % 3 == 0 && msg[i] == 'A')
			res[0]++;
		if (i % 3 == 1 && msg[i] == 'B')
			res[0]++;
		if (i % 3 == 2 && msg[i] == 'C')
			res[0]++;
		if ((i % 4 == 0 || i % 4 == 2) && msg[i] == 'B')
			res[1]++;
		if (i % 4 == 1 && msg[i] == 'A')
			res[1]++;
		if (i % 4 == 3 && msg[i] == 'C')
			res[1]++;
		if ((i % 6 == 0 || i % 6 == 1) && msg[i] == 'C')
			res[2]++;
		if ((i % 6 == 2 || i % 6 == 3) && msg[i] == 'A')
			res[2]++;
		if ((i % 6 == 4 || i % 6 == 5) && msg[i] == 'B')
			res[2]++;
	}
	int maxScore = res[0];
	int maxIndex = 0;
	vres.push_back(name[0]);
	for (int i = 1; i < 3; ++i) {
		if (maxScore < res[i]) {
			vres.clear();
			maxScore = res[i];
			maxIndex = i;
			vres.push_back(name[i]);
		}
		else if (maxScore == res[i]) {
			vres.push_back(name[i]);
		}
	}
	printf("%d\n", maxScore);
	for (int i = 0; i < vres.size(); ++i) {
		printf("%s\n", vres[i].c_str());
	}
}