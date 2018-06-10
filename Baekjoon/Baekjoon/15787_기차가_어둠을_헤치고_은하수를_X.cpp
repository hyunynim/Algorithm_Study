#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, m, command, tr, x;
	scanf("%d %d", &n, &m);
	vector<int> train(n, 0);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &command);
		switch (command) {
		case 1:
			scanf("%d %d", &tr, &x);
			train[tr] |= (1 << x);
			break;
		case 2:
			scanf("%d %d", &tr, &x);
			train[tr] &= (~(1 << x));
			break;
		case 3:
			scanf("%d", &tr);
			if (train[tr] & (1 << 20))
				train[tr] ^= (1 << 20);
			train[tr] <<= 1;
			break;
		case 4:
			scanf("%d", &tr);
			if (train[tr] & (1 << 1))
				train[tr] ^= (1 << 1);
			train[tr] >>= 1;
			break;
		}
	}
	vector<int> res;
	int j = 0;
	while (1) {
		for (int i = 0; i < res.size(); ++i) {
			if (res[i] == train[j]) {
				printf("%d", res.size());
				return 0;
			}
		}
		res.push_back(train[j++]);
		if (res.size() == train.size()) {
			printf("%d", res.size());
			return 0;
		}
	}
}

/*comment*/
//�׳� shift -> Ȯ�� �� ���������� xor�� �Ѱ� shift
//Ʋ��
//1. Ȥ�� ������ �ǵ��� ������ ������� �������Ƿ� i��° ������ ���������� i+1��° ���ʹ� ����������?
//0��¥�� �����ؼ� �ߺ� �����ε�
//shift������ ���길�ϰ� ������ ���س�����
//�ٵ� ��Ʋ��
//�ٽ� 1��ó�� Ǯ���
//Ʋ�� ���ڲ� Ʋ���°�
//�ߺ����Ű� �´ٰ� �����ϰ� ���� Ʋ���� ã�ƺ���
//�ߺ� ���Ÿ� Ʋ���� ���°� ������