#include<cstdio>

int main(){
	int t;
	scanf("%d", &t);
	getchar();
	for(int i = 0; i<t; ++i){
		char msg[123456];
		int cnt[26] = {0};
		fgets(msg, 123450, stdin);
		for(int j = 0; msg[j]!='\0'; ++j){
			if('a' <= msg[j] && msg[j] <= 'z')
				cnt[msg[j]-'a']++;
			else if('A' <= msg[j] && msg[j] <= 'Z')
				cnt[msg[j]-'A']++;
		}
		int minCnt = 123456;
		for(int j=0; j<26; ++j){
			if(cnt[j] < minCnt)
				minCnt = cnt[j];
		}
		printf("Case %d: ", i+1);
		switch(minCnt){
			case 0:
				printf("Not a pangram\n");
				break;
			case 1:
				printf("Pangram!\n");
				break;
			case 2:
				printf("Double pangram!!\n");
				break;
		}
		if(minCnt>=3)
				printf("Triple pangram!!!\n");
		
	}
}

/*comment*/
//온갖 오타들의 향연..