#include<cstdio>

int board[9];
enum { X, O };
bool checkWinner() {
	if (board[0] == X && board[1] == X && board[2] == X) return 1;
	if (board[3] == X && board[4] == X && board[5] == X) return 1;
	if (board[6] == X && board[7] == X && board[8] == X) return 1;
	if (board[0] == X && board[3] == X && board[6] == X) return 1;
	if (board[1] == X && board[4] == X && board[7] == X) return 1;
	if (board[2] == X && board[5] == X && board[8] == X) return 1;
	if (board[0] == X && board[4] == X && board[8] == X) return 1;
	if (board[2] == X && board[4] == X && board[6] == X) return 1;
	if (board[0] == O && board[1] == O && board[2] == O) return 1;
	if (board[3] == O && board[4] == O && board[5] == O) return 1;
	if (board[6] == O && board[7] == O && board[8] == O) return 1;
	if (board[0] == O && board[3] == O && board[6] == O) return 1;
	if (board[1] == O && board[4] == O && board[7] == O) return 1;
	if (board[2] == O && board[5] == O && board[8] == O) return 1;
	if (board[0] == O && board[4] == O && board[8] == O) return 1;
	if (board[2] == O && board[4] == O && board[6] == O) return 1;
	return 0;
}

int main() {
	char tmp;
	for (int i = 0; i < 9; ++i) {
			scanf("%1c", &tmp);
			if (tmp == 'X')
				board[i] = X;
			else if (tmp == 'O')
				board[i] = O;
			else
				board[i] = -1;
			if (i % 3 == 2)
				getchar();
		}
		
	printf("%s", checkWinner() ? "YES" : "NO");
}