#include<cstdio>

int main() {
	int pos[2][2] = { 0 };
	char msg[2][4];
	int n;
	scanf("%s %s", msg[0], msg[1], n);
	pos[0][0] = msg[0][0] - 'A';
	pos[0][1] = msg[0][1] - '1';
	pos[1][0] = msg[1][0] - 'A';
	pos[1][1] = msg[1][1] - '1';
}