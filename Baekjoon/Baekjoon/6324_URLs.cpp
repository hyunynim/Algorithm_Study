#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int n;
	string str;
	char  url[70];
	printf("%%");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", url);
		int j = 0;
		printf("URL #%d\n", i + 1);
		printf("%-9s= ", "Protocol");

		while (url[j] != ':') {
			printf("%c", url[j]);
			j++;
		}
		j += 3;
		printf("\n");
		printf("%-9s= ", "Host");

		while (url[j] != ':' && url[j] != '/' && url[j] != '\0') {
			printf("%c", url[j]);
			j++;
		}
		printf("\n");
		if (url[j] == ':')
		{
			j += 1;
			printf("%-9s= ", "Port");
			while (url[j] != '/' && url[j] != '\0') {
				printf("%c", url[j]);
				j++;
			}

		}
		else
		{
			printf("%-9s= <default>", "Port");
		}
		printf("\n");
		printf("%-9s= ", "Path");
		if (url[j] == '\0') {
			printf("<default>");
		}
		else {
			j += 1;
			while (url[j] != '\0')
				printf("%c", url[j++]);
		}
		printf("\n\n");
	}
}