#include<iostream>
#include<memory.h>
using namespace std;
#define MAXK 100001
#define MAXN 100000
typedef struct listNode Node;
int N, key[MAXN], list[MAXN];
Node *ret;

struct listNode {
	int addr, key;
};

int cmp(const void* a, const void* b) {
	return (*(Node *)a).key - (*(Node *)b).key;
}

int main() {
	//freopen("1.txt", "r", stdin);
	int i, addr, j;
	scanf("%d%d", &N, &addr);
	for (i = 0; i < MAXN; i++) {
		key[i] = MAXK;
		list[i] = -1;
	}
	ret = (Node *)malloc(sizeof(Node) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &j);
		scanf("%d%d", &key[j], &list[j]);
	}
	i = 0;
	while (addr != -1) {
		ret[i].addr = addr;
		ret[i].key = key[addr];
		addr = list[addr];
		i++;
	}
	N = i;
	if (N == 0) {
		printf("0 -1");
		return 0;
	}
	qsort(ret, N, sizeof(Node), cmp);
	addr = ret[0].addr;
	printf("%d %05d\n", N, addr);
	for (i = 0; i < N; i++) {
		if (i == N - 1)
			printf("%05d %d -1\n", ret[i].addr, ret[i].key);
		else
			printf("%05d %d %05d\n", ret[i].addr, ret[i].key, ret[i + 1].addr);
	}
	//fclose(stdin);
	return 0;
}