#include <iostream>
#include <string.h>

int main() {
	int memA, memB, goal;
	scanf("%d %d %d", &memA, &memB, &goal);
	char ** teamA = new char * [memA];
	char ** teamB = new char * [memB];
	for (int i = 0; i < memA; ++i) {
		teamA[i] = new char[30];
		scanf("%s", teamA[i]);
	}

	for (int i = 0; i < memB; ++i) {
		teamB[i] = new char[30];
		scanf("%s", teamB[i]);
	}
	int scoreA = 0, scoreB = 0;
	for (int i = 0; i < goal; ++i) {
		bool winner = 1;
		char goalName[30];
		scanf("%s", goalName);
		for (int i = 0; i < memA; ++i) {
			if (strcmp(goalName, teamA[i]) == 0) {
				winner = 0;
				break;
			}
		}
		if (winner)
			scoreB++;
		else
			scoreA++;
	}
	if (scoreA > scoreB)
		printf("A");
	else if (scoreA < scoreB)
		printf("B");
	else
		printf("TIE");
}