#include <iostream>

enum {R, G, B};

int min(int a, int b) {
	return a > b ? b : a;
}

int cache[1000][3];

int RgbPrice(int postColor, int totNum, int ** price){
	if (totNum == 1) {
		switch (postColor) {
		case R:
			if (cache[0][R] == -1)
				cache[0][R] = min(price[0][G], price[0][B]);
			return cache[0][R];
			break;
		case G:
			if (cache[0][G] == -1)
				cache[0][G] = min(price[0][R], price[0][B]);
			return cache[0][G];
			break;
		case B:
			if (cache[0][B] == -1)
				cache[0][B] = min(price[0][G], price[0][R]);
			return cache[0][B];
			break;
		}
	}
	else {
		switch (postColor) {
		case R:
			if (cache[totNum - 1][R] == -1)
				cache[totNum-1][R] = min(RgbPrice(G, totNum-1, price) + price[totNum - 1][G] , RgbPrice(B, totNum-1, price) + price[totNum - 1][B]);
			return cache[totNum - 1][R];
			break;
		case G:
			if (cache[totNum - 1][G] == -1)
				cache[totNum - 1][G] = min(RgbPrice(R, totNum - 1, price) + price[totNum - 1][R], RgbPrice(B, totNum - 1, price) + price[totNum - 1][B]);
			return cache[totNum - 1][G];
			break;
		case B:
			if (cache[totNum - 1][B] == -1)
				cache[totNum - 1][B] = min(RgbPrice(G, totNum - 1, price) + price[totNum - 1][G], RgbPrice(R, totNum - 1, price) + price[totNum - 1][R]);
			return cache[totNum - 1][B];
			break;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	
	int ** price = new int *[n];
	
	for (int i = 0; i < n; ++i) {
		price[i] = new int[3];
		for (int j = 0; j < 3; ++j) {
			scanf("%d", &price[i][j]);
			cache[i][j] = -1;
		}
	}

	int res = min(min(RgbPrice(R, n, price), RgbPrice(G, n, price)), RgbPrice(B, n, price));
	printf("%d", res);
}

/*commnet*/
//전수조사가 아니라 일부만 조사하던것 수정
//시간초과
//어떻게 해야 시간을 줄일 수 있을까?
//memoization?
//맞음