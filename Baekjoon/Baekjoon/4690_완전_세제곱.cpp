#include <stdio.h>
int main() {
	int a, b, c, d;
	for (a = 2; a < 101; a++) {
		for (b = 2; b < a; b++) {
			for (c = b; c < a; c++) {
				for (d = c; d < a; d++) {
					if (a*a*a == b*b*b + c*c*c + d*d*d) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
					}
				}
			}
		}
	}
}

/*comment*/
//상한 69 -> a
//상한 a -> 100
//else if + break없앰 -> if안에 break
//왜틀린지를 모르겠음...
//상한 100 -> a// bcd는 절대 a보다 클 수 없음
//조건 1보다 큰 자연수를 적용 안함.. 하