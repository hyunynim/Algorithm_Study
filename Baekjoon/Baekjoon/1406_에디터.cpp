#include<cstdio>
#include<list>
using namespace std;
int main() {
	char msg[1000000];
	scanf("%s", msg);
	list<char> str;
	for (int i = 0; msg[i] != '\0'; ++i)
		str.push_back(msg[i]);
	int n;
	scanf("%d", &n);
	getchar(); 
	list<char>::iterator it = str.end();
	for (int i = 0; i < n; ++i) {
		char command[10];
		fgets(command, 9, stdin);
		if (command[0] == 'L') {
			if (it != str.begin())
				--it;
		}
		else if (command[0] == 'D') {
			if(it != str.end())
				++it;
		}
		else if (command[0] == 'B') {
			if (it != str.begin()) {
				--it;
			}
			else continue;
			it = str.erase(it);
		}
		else {
			str.insert(it, command[2]);
		}
	}
	while(str.size()) {
		printf("%c", str.front());
		str.pop_front();
	}
}