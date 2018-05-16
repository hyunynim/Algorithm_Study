#include<cstdio>

int tree[26][2] = { 0 };

void PostOrder(int start) {	//LRD
	if (tree[start][0] != -1)
		PostOrder(tree[start][0]);

	if (tree[start][1] != -1)
		PostOrder(tree[start][1]);

	printf("%c", start + 'A');
}

void InOrder(int start) { //LDR
	if (tree[start][0] != -1)
		InOrder(tree[start][0]);

	printf("%c", start + 'A');

	if (tree[start][1] != -1)
		InOrder(tree[start][1]);
}

void PreOrder(int start) {//DLR
	printf("%c", start + 'A');

	if (tree[start][0] != -1)
		PreOrder(tree[start][0]);

	if (tree[start][1] != -1)
		PreOrder(tree[start][1]);
}

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; ++i) {
		char msg[10], p, lc, rc;
		fgets(msg, 9, stdin);
		p = msg[0];
		lc = msg[2];
		rc = msg[4];
		if (lc != '.')
			tree[p - 'A'][0] = lc - 'A';
		else
			tree[p - 'A'][0] = -1;

		if (rc != '.')
			tree[p - 'A'][1] = rc - 'A';
		else
			tree[p - 'A'][1] = -1;
		
	}
	PreOrder(0);
	printf("\n");
	InOrder(0);
	printf("\n");
	PostOrder(0);

}