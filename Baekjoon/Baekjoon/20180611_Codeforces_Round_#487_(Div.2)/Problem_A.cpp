#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<utility>
#include<functional>

typedef long long ll;

using namespace std;

int main() {
	char msg[1234];
	scanf("%s", msg);
	string str = msg;
	if (str.find("ABC") != string::npos
		|| str.find("ACB") != string::npos
		|| str.find("BAC") != string::npos
		|| str.find("BCA") != string::npos
		|| str.find("CAB") != string::npos
		|| str.find("CBA") != string::npos)
		printf("Yes");
	else
		printf("No");
}