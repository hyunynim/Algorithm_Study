#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
#define pos(y, x) (y*10)+(x)

int board[11][11];
vector<int> chk;
vector<int> canDo[101];
void printBoard();
bool checkBoard(int pos, int num);
int findBlock(int pos);


pair<int, int> startPos[9] = { {1, 1}, {1, 4}, {1, 7}, {4, 1}, {4, 4}, {4, 7}, {7, 1}, {7, 4}, {7, 7} };//y,x
int nx[9] = { 0, 1, 2, 0, 1, 2, 0, 1, 2 };
int ny[9] = { 0, 0, 0, 1, 1, 1, 2, 2, 2 };

int zeroCnt() {
	chk.clear();
	int res = 0;
	for (int i = 1; i < 10; ++i) {
		for (int j = 1; j < 10; ++j) {
			if (board[i][j] == 0) {
				++res;
				chk.push_back(pos(i, j));
			}
		}
	}
	return res;
}

bool checkBoard(int pos, int num) {
	int y = pos / 10;
	int x = pos % 10;
	//H
	for (int i = 1; i < 9; ++i) {
		if (x - i >= 1 && board[y][x - i] == num)
			return 0;
		if (x + i <= 9 && board[y][x + i] == num)
			return 0;
	}
	//V
	for (int i = 1; i < 9; ++i) {
		if (y - i >= 1 && board[y - i][x] == num)
			return 0;
		if (y + i <= 9 && board[y + i][x] == num)
			return 0;
	}
	//block
	int block = findBlock(pos);
	int sx = startPos[block].second;
	int sy = startPos[block].first;
	for (int i = 0; i < 9; ++i) {
		if (sy + ny[i] == y && sx + nx[i] == x)
			continue;
		if (board[sy + ny[i]][sx + nx[i]] == num)
			return 0;
	}
	return 1;
}
/*
bool DFS(int pos, int prev) {
	int x = pos % 10;
	int y = pos / 10;
	for (int i = 1; i < 10; ++i) {
		board[y][x] = i;
		if (checkBoard(pos, i) && (chk.size() - 1 == prev || DFS(chk[prev + 1], prev + 1)))
			return 1;
		board[y][x] = 0;
		
	}
}*/

void printBoard() {
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			printf("%d ", board[i][j]);
		}
		puts("");
	}
}

int findBlock(int pos) {
	int block;
	if (pos == 11 || pos == 12 || pos == 13
		|| pos == 21 || pos == 22 || pos == 23
		|| pos == 31 || pos == 32 || pos == 33) block = 0;
	if (pos == 14 || pos == 15 || pos == 16
		|| pos == 24 || pos == 25 || pos == 26
		|| pos == 34 || pos == 35 || pos == 36) block = 1;
	if (pos == 17 || pos == 18 || pos == 19
		|| pos == 27 || pos == 28 || pos == 29
		|| pos == 37 || pos == 38 || pos == 39) block = 2;
	if (pos == 41 || pos == 42 || pos == 43
		|| pos == 51 || pos == 52 || pos == 53
		|| pos == 61 || pos == 62 || pos == 63) block = 3;
	if (pos == 44 || pos == 45 || pos == 46
		|| pos == 54 || pos == 55 || pos == 56
		|| pos == 64 || pos == 65 || pos == 66) block = 4;
	if (pos == 47 || pos == 48 || pos == 49
		|| pos == 57 || pos == 58 || pos == 59
		|| pos == 67 || pos == 68 || pos == 69) block = 5;
	if (pos == 71 || pos == 72 || pos == 73
		|| pos == 81 || pos == 82 || pos == 83
		|| pos == 91 || pos == 92 || pos == 93) block = 6;
	if (pos == 74 || pos == 75 || pos == 76
		|| pos == 84 || pos == 85 || pos == 86
		|| pos == 94 || pos == 95 || pos == 96) block = 7;
	if (pos == 77 || pos == 78 || pos == 79
		|| pos == 87 || pos == 88 || pos == 89
		|| pos == 97 || pos == 98 || pos == 99) block = 8;
	return block;
}

void makeCanDo(int pos) {
		bool numChk[10] = { 0 };
		int block = findBlock(pos);
		numChk[board[pos / 10][pos % 10]] = 1;
		//H
		for (int i = 1; i < 9; ++i) {
			if (pos % 10 - i >= 1)
				numChk[board[pos / 10][pos % 10 - i]] = 1;
			if (pos % 10 + i <= 9)
				numChk[board[pos / 10][pos % 10 + i]] = 1;
		}
		//V
		for (int i = 1; i < 9; ++i) {
			if (pos / 10 - i >= 1)
				numChk[board[pos / 10 - i][pos % 10]] = 1;
			if (pos / 10 + i <= 9)
				numChk[board[pos / 10 + i][pos % 10]] = 1;
		}
		//block
		int sx = startPos[block].second;
		int sy = startPos[block].first;
		for (int i = 0; i < 9; ++i) {
			numChk[board[sy + ny[i]][sx + nx[i]]] = 1;
		}
		for (int i = 1; i < 10; ++i)
			if(!numChk[i])
				canDo[pos].push_back(i);
}

bool FindAns(int toPick, int cur) {
	if (toPick == 0) {
		for (int i = 1; i < 10; ++i) {
			for (int j = 1; j < 10; ++j) {
				if (!checkBoard(pos(i, j), board[i][j]))
					return 0;
			}
		}
		printBoard();
		return 1;
	}
	int x = chk[cur] % 10;
	int y = chk[cur] / 10;
	for (int i = 1; i < 10; ++i) {
		if (checkBoard(chk[cur], i)) {
			board[y][x] = i;
			if (FindAns(toPick - 1, cur + 1))
				return 1;
			board[y][x] = 0;
		}
	}
	return 0;
}


int main() {
	int a;
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j <= 9; ++j) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 0)
				chk.push_back(pos(i, j));
		}
	}
	for (int asdf = 0; asdf < 4; ++asdf) {
		for (int i = 1; i < 10; ++i) {
			for (int j = 1; j < 10; ++j) {
				if (board[i][j] == 0) {
					canDo[pos(i, j)].clear();
					makeCanDo(pos(i, j));
				}
			}
		}

		for (int i = 1; i < 10; ++i) {
			for (int j = 1; j < 10; ++j) {
				if (canDo[pos(i, j)].size() == 1) {
					board[i][j] = canDo[pos(i, j)][0];
					canDo[pos(i, j)].pop_back();
				}
			}
		}
	}
	for (int i = 1; i < 10; ++i) {
		for (int j = 1; j < 10; ++j) {
			if (board[i][j] == 0) {
				canDo[pos(i, j)].clear();
				makeCanDo(pos(i, j));
			}
		}
	}
	FindAns(zeroCnt(), 0);
	return 0;
}