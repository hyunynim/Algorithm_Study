#include <iostream>
#include <vector>

using namespace std;
void maxSum(int ** card, int * resCard, int ind);

int main() {
	int n;
	scanf("%d", &n);
	int ** card = new int*[n];
	for (int i = 0; i < n; ++i) {
		card[i] = new int[7];
		for (int j = 0; j < 5; ++j) {
				scanf("%d", &card[i][j]);
				if (j == 4) 
					maxSum(card, &card[i][5], i);
		}
	}

	vector <int> winner;
	vector <int> winnerSum;

	int max = -10;
	for (int i = 0; i < n; ++i) {
		if (max < card[i][5]) {
			max = card[i][5];
			winner.clear();
			winnerSum.clear();
			winner.push_back(i);
			winnerSum.push_back(card[i][6]);
		}
		else if (max == card[i][5]) {
			winner.push_back(i);
			winnerSum.push_back(card[i][6]);
		}
	}
	if (winner.size() == 1)
		printf("%d", winner[0] + 1);
	
	else 
		printf("%d", *(winner.end()-1) + 1);
	
			
}

void maxSum(int ** card, int * resCard, int ind) {
	int max = -1;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				if (max < (card[ind][i] + card[ind][j] + card[ind][k]) % 10) {
					max = (card[ind][i] + card[ind][j] + card[ind][k]) % 10;
					*resCard = (card[ind][i] + card[ind][j] + card[ind][k]) % 10;
				}
			}
		}
	}
}

/*comment*/
//5자리수를 다 더해서 틀림
//3자리수연산을 했는데 나머지 연산에 괄호가 빠짐
//또 틀림
//합이 제일 큰사람이 아닌 번호가 제일 큰사람을 출력하는 거였음...