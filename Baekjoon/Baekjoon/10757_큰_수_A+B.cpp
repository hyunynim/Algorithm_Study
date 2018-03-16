#include <stdio.h>
#include <string.h>
void sort_c(char *msg, int len);
void c_plus(char *a, int lena, char *b, int lenb, char *res);
void print_res(char *res);
int main()
{
	char a[10001] = {}, b[10001] = {}, res[10001] = {};//'1' = 49
	scanf("%s %s", a, b);
	sort_c(a, strlen(a));
	sort_c(b, strlen(b));
	c_plus(a, strlen(a), b, strlen(b), res);
	print_res(res);
	return 0;
}
void sort_c(char *msg, int len) {
	for (int i = 0; i < len; i++)
		*(msg + i) = *(msg + i + 1);
	*(msg + len) = '\0';
}

void c_plus(char *a, int lena, char *b, int lenb, char *res) {
	int r = 0, d = 0, i = 10000;
	*(res + 10000) = '\0';
	while ((lena >= 0 || lenb >= 0) && i >= 0) {
		r = 0;
		if (lena < 0 && lenb < 0) {
			*(res + i) = '0';
			continue;
		}

		if (lena > 0)
			r += (*(a + (lena - 1)) - 48);
		if (lenb > 0)
			r += (*(b + (lenb - 1)) - 48);
		r += d;
		d = r / 10;
		*(res + i) = r % 10 + 48;
		i--;
		lena--;
		lenb--;
	}
}

void print_res(char *res) {
	int nzero = 0, i = 0;
	while (*(res + i) != '\0') {
		if ((*(res + i) <= 48 || *(res + i) > 57) && nzero == 0);
		else {
			printf("%c", *(res + i));
			nzero++;
		}
		i++;
	}
}