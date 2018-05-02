#include <iostream>

int cache[501][501];
int max(int a, int b);
int maxSum(int ** triangle, int x, int y, int n);
int main() {
	int n;
	scanf("%d", &n);
	int ** triangle = new int * [n];
	for (int i = 0; i < n; i++) {
		triangle[i] = new int[i + 1];
		for (int j = 0; j < i + 1; j++)
			scanf("%d", &triangle[i][j]);
	}
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++)
			cache[i][j] = -1;
	}
	printf("%d", maxSum(triangle, 0, 0, n-1));
}

int maxSum(int ** triangle, int y, int x, int n) {
	if (y == n)
		cache[y][x] = triangle[y][x];
	else if (cache[y][x] != -1) {
		return cache[y][x];
	}
	else {
		cache[y][x] = max(maxSum(triangle, y + 1, x, n), maxSum(triangle, y + 1, x + 1, n)) + triangle[y][x];
	}
	return cache[y][x];
	
}

int max(int a, int b) {
	return a > b ? a : b;
}