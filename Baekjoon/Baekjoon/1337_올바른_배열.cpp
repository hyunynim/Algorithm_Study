#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	sort(seq.begin(), seq.end());


	int maxCnt = 0;
	int cnt = 0;
	string str;
	for (int i = 1; i < seq.size(); ++i)
		str.insert(str.end(), '0' + seq[i] - seq[i - 1]);
	if (str.find("1111") != string::npos)
		printf("0");
	else if (str.find("112") != string::npos
		|| str.find("121") != string::npos
		|| str.find("211") != string::npos
		|| str.find("111") != string::npos)
		printf("1");
	else if (str.find("11") != string::npos
		|| str.find("12") != string::npos
		|| str.find("21") != string::npos
		|| str.find("22") != string::npos
		|| str.find("13") != string::npos
		|| str.find("31") != string::npos)
		printf("2");
	else if (str.find("1") != string::npos
		|| str.find("2") != string::npos
		|| str.find("3") != string::npos
		|| str.find("4") != string::npos)
		printf("3");
	else
		printf("4");
}
/*comment*/
//중간이 비어있는 경우
//string 이용해서 검색