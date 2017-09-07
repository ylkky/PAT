#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;

struct treeNode {
	int left, right;
};
typedef struct treeNode Node;

int N;
Node T[2001];

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int findRoot(int *a, int n, int num) {
	int buttonN, idx, l, r;
	if (n == 1) {
		return 0;
	}
	buttonN = num  - 1 - n;
	buttonN = num / 2 - buttonN;
	if (buttonN == 0)
		idx = n / 2;
	else if (buttonN <= num / 4)
		idx = (n + buttonN) / 2;
	else
		idx = (n - buttonN) / 2 + num / 4;
	num /= 2;
	l = findRoot(a, idx, num);
	T[a[idx]].left = a[l];
	if (n > 2) {
		r = findRoot(a + idx + 1, n - idx - 1, num);
		T[a[idx]].right = a[idx + 1 + r];
	}	
	return idx;
}

int main() {
	//freopen("1", "r", stdin);
	int i, root, idx, v, flag = 0;
	queue<int> q;
	int *a;
	scanf("%d", &N);
	a = (int *)malloc(sizeof(int) * N);
	for (i = 0; i < N;i++)
		scanf("%d", &a[i]);
	for (i = 0; i < 2001; i++) {
		T[i].left = T[i].right = -1;
	}
	qsort(a, N, sizeof(int), cmp);
	int num = 2;
	while (num - 1 < N) {
		num *= 2;
	}
	idx = findRoot(a, N, num);
	root = a[idx];
	q.push(root);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		if (flag == 0) {
			printf("%d", v);
			flag = 1;
		}
		else
			printf(" %d", v);
		if (T[v].left != -1) {
			q.push(T[v].left);
			if (T[v].right != -1)
				q.push(T[v].right);
		}
	}
	//fclose(stdin);
	return 0;
}
