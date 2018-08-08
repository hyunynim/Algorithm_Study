#include<cstdio>
#include<string>
#define for(x) for(int i = 0; i<x; ++i)
using namespace std;

int main() {
	char msg[1234];
	while (fgets(msg, 1233, stdin)) {
		string str = msg;
		while (1) {
			long long index = str.find("BUG");
			if (index == string::npos)
				break;
			str.erase(index, 3);
		}
		printf("%s", str.c_str());
	}
}
