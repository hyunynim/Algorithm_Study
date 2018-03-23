#include <stdio.h>

int main() {
	int n;
	int tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int res = 0;
		int hp = 0, mp = 0, att = 0, def = 0;
		for (int j = 0; j < 8; j++) {
			scanf("%d", &tmp);
			switch (j % 8) {
			case 0:
				hp += tmp;
				break;
			case 1:
				mp += tmp;
				break;
			case 2:
				att += tmp;
				break;
			case 3:
				def += tmp;
				break;
			case 4:
				hp += tmp;
				if (hp <= 0)
					res += 1;
				else
					res += hp;
				break;
			case 5:
				mp += tmp;
				if (mp <= 0)
					res += 5;
				else
					res += 5*mp;
				break;
			case 6:
				att += tmp;
				if (att <= 0);
				else
					res += 2 * att;
				break;
			case 7:
				def += tmp;
				res += 2 * def;
				break;
			}
		}
		printf("%d\n", res);
	}
}