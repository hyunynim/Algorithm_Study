#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	char msg[1234];
	scanf("%s", msg);
	string str = msg;
	vector<string> seq;
	seq.push_back(str);
	int strLen = str.length();
	for (int i = 0; i < strLen - 1; ++i) 
		seq.push_back(str.substr(strLen - 1 - i, strLen - 1));
	
	sort(seq.begin(), seq.end());
	for (int i = 0; i < seq.size(); ++i)
		printf("%s\n", seq[i].c_str());
	
}