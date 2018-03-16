#include <stdio.h>

int main() {
	bool mine[750][750] = { 0 }, cnt_one = 0, isContinue = 1;
	int r, c, max = 0, cur_pos[3] = { 0 };
	scanf("%d %d", &r, &c);
	
	//input
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%1d", &mine[i][j]);
			if (cnt_one == 0 && mine[i][j] == 1)
				cnt_one = 1;
		}
	}

	//calc
	if (cnt_one == 0) {
		printf("0");
		return 0;
	}

	else {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (i - max <= 0)
					break;
				else {
					cur_pos[0] = 1;
					//넓어질때
					while (i - cur_pos[0] >= 0 && j + cur_pos[0] < c && i + cur_pos[0] < r && j + cur_pos[0] < c) {
						if (mine[i - cur_pos[0]][j + cur_pos[0]] == 0
							|| mine[i + cur_pos[0]][j + cur_pos[0]] == 0
							|| i - cur_pos[0] == 0
							|| i + cur_pos[0] == r - 1
							|| j + cur_pos[0] == c - 1)
							break;
						cur_pos[0]++;
					}

					cur_pos[2] = cur_pos[0];
					cur_pos[1] = cur_pos[0];
					cur_pos[0] = 1;
					//줄어들때
					while (cur_pos[0] != 0 && j + cur_pos[1] + cur_pos[0] < c)
					{
						if (mine[i + cur_pos[1] - cur_pos[0]][j + cur_pos[1] + cur_pos[0]] == 0
							|| mine[i - cur_pos[1] + cur_pos[0]][j + cur_pos[1] + cur_pos[0]] == 0
							|| j + cur_pos[0] == c - 1)
							break;
						else if (cur_pos[0] == cur_pos[2]) {
							if(cur_pos[0] > max)
								max = cur_pos[0];
							break;
						}
						cur_pos[0]++;
					}
				} //else 끝
			}
		}
	}
	printf("%d", max+1);
}
