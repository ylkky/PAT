#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;
#define PUSH 0
#define POP 1

//typedef struct treeNodes* Node;
struct treeNodes {
	int l, r;
}T[31];
typedef struct treeNodes tNode;
int N;
//Node T;
stack<int> s;
int ins[31], pre[31];

int buildTree(int *in, int *p, int num) {
	int i, root;
	if (num == 0)
		return -1;
	else if (num == 1)
		return p[0];
	else {
		root = p[0];
		for (i = 0; i < num; i++)
			if (in[i] == root)
				break;
		T[root].l = buildTree(in, p + 1, i);
		T[root].r = buildTree(in + i + 1, p + i + 1, num - i - 1);
		return root;
	}
}

void printTree(int root) {
	if (T[root].l != -1) {
		printTree(T[root].l);
	}
	if (T[root].r != -1)
		printTree(T[root].r);
	printf("%d ", root);
}

int main() {
	//freopen("1", "r", stdin);
	int i, j, k, key, root;
	char cmd[5];
	//Node p, t;
	//T = NULL;
	cin >> N;
	N = 2 * N;
	j = 0;
	k = 0;
	for (i = 0; i < 31; i++) {
		ins[i] = ins[i] = -1;
		T[i].l = T[i].r = -1;
	}
	for(i = 0; i < N; i++) {
		scanf("%s", cmd);
		if (!strcmp(cmd, "Push")) {
			scanf("%d", &key);
			pre[j++] = key;
			s.push(key);
		}
		else if (!strcmp(cmd, "Pop")) {
			ins[k++] = s.top();
			s.pop();
		}
	}
	N = N / 2;
	root = buildTree(ins, pre, N);
	if (T[root].l != -1) {
		printTree(T[root].l);
	}
	if (T[root].r != -1)
		printTree(T[root].r);
	printf("%d", root);
	//fclose(stdin);
	return 0;
}