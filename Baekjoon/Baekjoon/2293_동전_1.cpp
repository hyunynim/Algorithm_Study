#include<cstdio>

int cache[10001];
int coin[101];

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);
	cache[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			cache[j] += cache[j - coin[i]];
		}
	}

	printf("%d", cache[k]);

}