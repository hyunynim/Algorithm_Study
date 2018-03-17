#include <stdio.h>
#include <string.h>
#include <iostream>

int main() {
	char msg[11];
	char start[] = "START";
	char end[] = "END";
	char endofinput[] = "ENDOFINPUT";
	char chipher;
	while (1) {
		char ans[300];
		scanf("%s", msg);
		if (strcmp(msg, endofinput) == 0)
			return 0;
		else{
			int i = 0;
			gets_s(ans);
			while (ans[i] != '\0') {
				if (70 <= ans[i] && ans[i] <= 90)
					ans[i] -= 5;
				else if (65 <= ans[i] && ans[i] < 70)
					ans[i] += 21;
				i++;
			}
			scanf("%s", msg);
		}
		printf("%s\n", ans);
	}
}

/*comment*/
//한줄씩 읽는 함수써서 ans 받기