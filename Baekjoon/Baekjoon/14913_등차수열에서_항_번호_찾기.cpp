#include<cstdio>

int main() {
	int a, d, k, res;
	scanf("%d %d %d", &a, &d, &k);
	res = (k - a) / d + 1;
	if ((k - a) % d != 0 || res <= 0)
		printf("X");
	else
		printf("%d", res);
}
/*comment*/
//초항이 0인경우 -> 생각할 필요 없었음
//항번호가 음수로 나오는경우 -> 존재하지 않는 케이스 이므로 따로 빼야함