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
			--tr;
			train[tr] |= (1 << x);
			break;
		case 2:
			scanf("%d %d", &tr, &x);
			--tr;
			train[tr] &= (~(1 << x));
			break;
		case 3:
			scanf("%d", &tr);
			--tr;
			if (train[tr] & (1 << 20))
				train[tr] = train[tr]^(1 << 20);
			train[tr] = train[tr] << 1;
			break;
		case 4:
			scanf("%d", &tr);
			--tr;
			if (train[tr] & (1 << 1))
				train[tr] ^= (1 << 1);
			train[tr] = train[tr] >> 1;
			break;
		}
	}
	sort(train.begin(), train.end());
	train.erase(unique(train.begin(), train.end()), train.end());
	printf("%d", train.size());
}

/*comment*/
//�׳� shift -> Ȯ�� �� ���������� xor�� ���� shift
//Ʋ��
//1. Ȥ�� ������ �ǵ��� ������ ������� �������Ƿ� i��° ������ ���������� i+1��° ���ʹ� ����������?
//0��¥�� �����ؼ� �ߺ� �����ε�
//shift������ ���길�ϰ� ������ ���س�����
//�ٵ� ��Ʋ��
//�ٽ� 1��ó�� Ǯ���
//Ʋ�� ���ڲ� Ʋ���°�
//�ߺ����Ű� �´ٰ� �����ϰ� ���� Ʋ���� ã�ƺ���
//�ߺ� ���Ÿ� Ʋ���� ���°� ������
//���� ��ȣ�� 1~N��;; tr-1 �ؾ��ϳ�
//���� ��ȣ ������ �������� ��...