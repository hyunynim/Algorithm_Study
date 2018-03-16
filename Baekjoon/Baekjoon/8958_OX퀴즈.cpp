#include <stdio.h>

int main()
{
	int t, score, res;
	char msg[80];
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		res = 0;
		score = 0;
		scanf("%s", msg);
		int j = 0;
		while (*(msg + j) != '\0')
		{
			if (*(msg + j) == 'O') {
				score++;
				res += score;
			}
			else
				score = 0;
			j++;
		}
		printf("%d\n", res);
	}
}