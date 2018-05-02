#include <stdio.h>
#include <string>

int main() {
	char msg[3][10000] = { {"1110"}, {"0111"} };
	for (int i = 0; i < 4; i++) {
		msg[2][i] = msg[1][i] & msg[0][i];
		printf("%c", msg[2][i]);
	}
}