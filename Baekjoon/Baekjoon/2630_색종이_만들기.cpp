#include<cstdio>

bool paper[200][200] = { 0 };

int res[2] = { 0 };

bool CheckPaper(int sx, int sy, int size) {
	bool tmp = paper[sy][sx];
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (tmp == paper[sy + i][sx + j]);
			else
				return 0;
		}
	}
	res[tmp]++;
	return 1;
}

void Div(int sx, int sy, int size) {
	if (size == 1) 
		res[paper[sy][sx]]++;
	else if (!CheckPaper(sx, sy, size)){
		Div(sx, sy, size / 2);
		Div(sx + size/2, sy, size / 2);
		Div(sx, sy + size / 2, size / 2);
		Div(sx + size / 2, sy + size / 2, size / 2);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &paper[i][j]);
		}
	}
	Div(0, 0, n);
	printf("%d\n%d", res[0], res[1]);
}