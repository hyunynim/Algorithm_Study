#include<cstdio>
#include<string>

using namespace std;

int main() {
	char msg[2][12345];
	fgets(msg[0], 12333, stdin);
	fgets(msg[1], 12333, stdin);
	
	string str1 = msg[0];
	if(str1.find('\n') != string::npos)
		str1.erase(str1.find('\n'));
	
	string str2 = msg[1];
	if(str2.find('\n') != string::npos)
		str2.erase(str2.find('\n'));

	int res = 0;
	while (1) {
		if (str1.find(str2) == string::npos)
			break;
		int index = str1.find(str2);
		string::iterator it = str1.begin() + index;
		str1.erase(index, str2.length());
		str1.insert(it, '#');
		res++;
	}
	printf("%d", res);
}