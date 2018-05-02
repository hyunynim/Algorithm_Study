#include <stdio.h>
int main() {
	int n, r;
	scanf("%d", &n);
	for (int i = 1; i <= n; i *= 10)
		r += n - i + 1;
	printf("%d", r);
	return 0;
}

/*comment*/
//½ß if¹®¿¡¼­ Á¶±Ý ÀÌ»Ú°Ô ¹Ù²Þ
//Æ²¸²
//°¥¾Æ¾þÀ½