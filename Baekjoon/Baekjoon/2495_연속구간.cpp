#include<cstdio>

int main() {
	int a;
	for (int i = 0; i < 3; ++i) {
		int cnt = 1, max = 0, tmp = 0;
		
		for (int j = 0; j < 8; ++j) {
			scanf("%1d", &a);
			if (a != tmp) {
				if (max < cnt)
					max = cnt;
				cnt = 1;
				tmp = a;
			}
			else
				cnt++;
		}
		if(cnt > max)
			max = cnt;
		printf("%d\n", max);

	}
}