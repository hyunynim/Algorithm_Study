#include <stdio.h>

int pow10(int n) {
	if (n == 0)
		return 1;
	else if (n == 1)
		return 10;
	else
		return pow10(n - 1) * 10;
}

int main()
{
	char msg[8];
	int res = 0;

	scanf("%c %c %c %c %c %c %c %c", &msg[0], &msg[1], &msg[2], &msg[3], &msg[4], &msg[5], &msg[6], &msg[7]);
	for (int i = 0; i < 8; i++) 
		res += (*(msg + i) - 48) * pow10(7 - i);
		
	if (res == 12345678)
		printf("ascending");
	else if (res == 87654321)
		printf("descending");
	else
		printf("mixed");

	return 0;

}