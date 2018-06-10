#include<cstdio>
#include<string>
#include<string.h>

using namespace std;

int main() {
	char msg[1234];
	string nemo[] = { "nemo", "nemO", "neMo", "neMO", "nEmo", "nEmO", "nEMo", 
		"nEMO", "Nemo", "NemO", "NeMo", "NeMO", "NEmo", "NEmO", "NEMo", "NEMO" };
	string tmp;
	fgets(msg, 123, stdin);
	tmp = msg;
	while (tmp != "EOI") {
		bool isEx = 0;
		for (int i = 0; i < 16; ++i) {
			if (tmp.find(nemo[i]) != string::npos) {
				printf("Found\n");
				isEx = 1;
				break;
			}
		}
		if (isEx);
		else
			printf("Missing\n");
		fgets(msg, 123, stdin);
		if (strcmp(msg, "EOI") == 0)
			return 0;
		tmp = msg;
	}

}