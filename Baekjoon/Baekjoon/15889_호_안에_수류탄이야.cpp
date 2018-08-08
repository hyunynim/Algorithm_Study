#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<string.h>

using namespace std;
vector<int> pos;
int power[1000010];
int cache[30101];
int n;


int DFS(int start) {
	if (pos[start] == pos.back())
		return 1;
	else {
		int & ans = cache[start];
		if (ans != -1)
			return ans;
		int cur = pos[start];
		for (int i = start + 1; i < pos.size(); ++i) {
			if (cur + power[cur] >= pos[i]) {
				if (DFS(i)) {
					ans = 1;  return ans;
				}
			}
		}
		ans = 0;
		return ans;
	}
}
int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	pos.resize(n);
	int tmp;
	int posMax = 0;
	for (int i = 0; i < n; ++i) 
		scanf("%d", &pos[i]);
	
	if (n > 1) {
		for (int i = 0; i < n - 1; ++i) {
			scanf("%d", &tmp);
			power[pos[i]] = max(tmp, power[pos[i]]);
		}
		sort(pos.begin(), pos.end());
	}
		if (DFS(0)) printf("�Ǻ����, �ߴ������ ã���ʴϴ�");
		else printf("���� �� ���� �ʾ��� �� ����");
}

/*comment*/
//data�� pair�� ó���ϰ� sort ��Ŵ
//Ʋ��
//n == 1 �� �� ���� ó��
//������ �ӵ��� ���̴µ� ���� ���� �� ��
//i�� ��ǥ�� �ִ� power�� power[i]�� �����ϰ� �׻� �ִ񰪸� �����ϰ� �� ����
// -> ������ ��Ÿ� 0�ȿ� ���� �� �����״�
//�״��� pos�� ���� + �ߺ����� �ؼ� power���� ���� ����ͼ� ����?
//Ʋ��
//���� + �ߺ����� ���� power�� pos���� ����
//�� Ʋ���°ɱ� ��...
//������ ��ǥ�� 0�ε� �̰� ���� �׻� �� ó���� ����ɱ�? �³���/
//�������� ������ ��ǥ�� �׻� n��° ����? �´µ�
//�迭�� �������� �ƴϾ N��° ����� ���� ���� �ִ� ���찡 ���� �� ����
//Ʋ��
//cache ����� 1������ �Ǿ��־���;;;;
//�������� cache ������ ������ ��� Ʋ�Ƚ��ϴ� ���