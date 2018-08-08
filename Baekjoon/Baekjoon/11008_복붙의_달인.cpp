#include<cstdio>
#include<string>

using namespace std;
#define for(x) for(int i = 0; i<x; ++i)

int main() {
	char msg[12345];
	int t;
	scanf("%d", &t);
	for (t) {
		string str1, str2;
		int res = 0;
		scanf("%s", msg);
		str1 = msg;
		scanf("%s", msg);
		str2 = msg;
		while (1) {
			long long index = str1.find(str2);
			if (index == string::npos)
				break;
			str1.erase(index, str2.length());
			res++;
		}
		printf("%d\n", res + str1.size());
	}
}