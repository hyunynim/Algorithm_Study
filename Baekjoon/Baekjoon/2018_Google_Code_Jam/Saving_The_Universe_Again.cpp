#include <iostream>
#include <string.h>

int calcDmg(char *msg, int * s, int * c);
int hackRobot(char *msg, int dmg);
int calcDmg(char *msg);
void changeChar(char * a, char * b, int * res);

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i<t; ++i) {
		int d;
		char msg[40];
		int cntShoot = 0;
		int cntCharge = 0;
		int dmg;
		std::cin >> d >> msg;
		std::cout << "Case #" << i + 1 << ": ";

		dmg = calcDmg(msg, &cntShoot, &cntCharge);

		if (cntShoot > d)
			std::cout << "IMPOSSIBLE";
		else if (dmg <= d)
			std::cout << 0;
		else {
			std::cout << hackRobot(msg, d);
		}

		std::cout << "\n";
	}
}

int calcDmg(char *msg, int * s, int * c) {
	int res = 0;
	int curDmg = 1;
	for (int i = 0; msg[i] != '\0'; ++i) {
		if (msg[i] == 'C') {
			curDmg *= 2;
			++(*c);
		}
		else {
			res += curDmg;
			++(*s);
		}
	}
	return res;
}

int calcDmg(char *msg) {
	int res = 0;
	int curDmg = 1;
	for (int i = 0; msg[i] != '\0'; ++i) {
		if (msg[i] == 'C') {
			curDmg *= 2;
		}
		else {
			res += curDmg;
		}
	}
	return res;
}

int hackRobot(char *msg, int dmg) {
	int res = 0;
	while (calcDmg(msg) > dmg) {
		int i = strlen(msg) - 1;
		while (msg[i] != 'S' || msg[i - 1] != 'C') {
			--i;
		}
		changeChar(&msg[i], &msg[i - 1], &res);
	}
	return res;
}

void changeChar(char * a, char * b, int * res) {
	char c;
	c = *a;
	*a = *b;
	*b = c;

	(*res)++;
}
