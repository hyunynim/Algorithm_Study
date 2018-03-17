#include <stdio.h>
#include <math.h>

int main() {
	unsigned int  x, y, t;
	unsigned int length, calc, ans, v_sqrt;
	scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		scanf("%d %d", &x, &y);
		length = y - x;
		calc = 0;
		v_sqrt = (int)sqrt(length);
		if (v_sqrt*v_sqrt == length || v_sqrt > 10)
			v_sqrt--;
		while (1) {
			if ((v_sqrt - 1)*(v_sqrt - 1) < length && length <= (v_sqrt)*(v_sqrt + 1)) {
				ans = 2 * v_sqrt;
				break;
			}
			if ((v_sqrt)*(v_sqrt + 1) < length && length <= (v_sqrt+1)*(v_sqrt+1))
			{
				ans = 2 * v_sqrt + 1;
				break;
			}
			v_sqrt++;
		}
		printf("%d\n", ans);
	}
}

/*comment*/
// Test case를 고려 안하여 틀림
// 개행문자가 빠져서 틀림
// 답을 하나만 출력하고 끝나서 틀림
// 갈아엎음
// 속도를 높여봤으나 시간초과

// 갈아엎음
// a_(2n+1) = a_(2n-1) + (2n+1) // a_(2n+1) = n^2		a_(2n)+1 ~ a_(2n+1)항 까지는 2n+1
// a_(2n) = a_(2n-2) + 2n // a_(2n) = n(n+1)			a_(2n-1)+1 ~ a_(2n)항 까지는 2n
// 시간초과
// length = 2^31 일때 overflow가 생겼던것 같음
// 정답