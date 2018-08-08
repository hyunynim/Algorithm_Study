#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	while (1) {
		char msg[1234];
		fgets(msg, 1232, stdin);
		str = msg;
		if (str == "***\n" || str == "***")
			return 0;
		for (int i = str.size() - 2; i >= 0; --i)
			cout << str[i];
		cout << '\n';
	}
}