#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <afx.h>

int main() {
	int n, m;
	int i = 0, cnt = 0;
	CString msg;
	
	scanf_s("%d %d", &n, &m);
	while (i < 10)
	{
		if ((int)(n / (pow(10, i))) == 0)
			break;
		i++;
	}

	for (int j = 1; j <= n; j++) {
		printf("%d", n);
		cnt += i;
		if ((i*(j + 1) > m))
			break;
	}
	if (cnt != m && i*n > m)
		printf("%d", (int)(n / (pow(10, i - (m - cnt)))));
	system("pause");

	return 0;
}