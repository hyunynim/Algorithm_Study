#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

#define INF -1e9
int cache[321][3];
int score[321];
int n;

int up(int start, int cnt) {
	if (start >= n)
		return INF;
	if (start == n - 1)
		return score[n - 1];
	else {
		int & ans = cache[start][cnt];
		if (ans != -1)
			return ans;
		
		ans = score[start];
		if (cnt < 2)
			ans = max({ up(start + 1, cnt + 1) + ans, up(start + 2, 1) + ans });
		else
			ans += up(start + 2, 1);
		return ans;
	}
}

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &score[i]);
	printf("%d", max(up(0, 1), up(1, 1)));
}

/*comment*/
//�� ���� Ʋ���� ���������� �𸣰���
//����Լ� ���ƾ���
//�ð��ʰ�
//�޸������̼� �����غ�
//Ʋ�� -> �ߺ� case�� �����µ�
//0 -> 2 �� 1 -> 2 �ϸ� �Ѵ� n==2 �� ���·� �����
//�ߺ�case ���� �ʿ�
//�ΰ� �Լ�, �ΰ� cache �̿�
//�ð��ʰ�
//�� ó���� ù��° ����� ��� ��� vs �ι�° ����� ��� ���