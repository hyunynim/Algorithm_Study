#include<cstdio>
#include<string.h>
char res[5][1234];

int main() {
	char msg[1234];
	scanf("%s", msg);
	int len = strlen(msg);
	char line = '#';
	for(int i = 0; i<len; ++i){
		if (i % 3 == 2)
			line = '*';
		else
			line = '#';
		for (int k = 0; k<5; ++k) {
			for (int j = 0; j < 5; ++j) {
					if (k == 0 || k == 4) {
						if (j % 5 == 2)
							res[k][4 * i + j] = line;
						else
							res[k][4 * i + j] = '.';
					}
					else if (k == 1 || k == 3)
					{
						if (j % 5 == 1 || j % 5 == 3)
							res[k][4 * i + j] = line;
						else
							res[k][4 * i + j] = '.';
					}
					else if (k == 2)
					{
						if (j % 5 == 0 || j % 5 == 4) {
							if (res[k][4 * i + j] == '*');
							else
								res[k][4 * i + j] = line;
						}
						else if (j % 5 == 2)
							res[k][4 * i + j] = msg[i];
						else
							res[k][4 * i + j] = '.';
					}
				
			}
		}
	}
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j <= len * 4; ++j) {
			printf("%c", res[i][j]);
		}
		printf("\n");
	}
}

/*comment*/
//���ڰ� �׻� 3�ǹ���� �ԷµǴ°� �ƴѵ�
//������ �ʹ� ���� ��������
//�߸��� ������ ����ϰ� �־���