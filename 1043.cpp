#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct treeNode* node;

struct treeNode {
	int e;
	node left, right;
};

int N, flag = 0, mirror = 0;
int *num;
node T = NULL; // root

node buildTree(node root, int *e, int n);
void printTree(node root);

int main() {
	//freopen("1.txt", "r", stdin);
	cin >> N;
	num = new int[N];
	int i;
	for (i = 0; i < N; i++)
		cin >> num[i];
	T = buildTree(T, num, N);
	if (flag == 1) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	if(T->left != NULL)
		printTree(T->left);
	if (T->right != NULL)
		printTree(T->right);
	cout << T->e;
	//fclose(stdin);
	return 0;
}

node buildTree(node root, int *e, int n) {
	if (n == 0)
		return NULL;
	root = (node)malloc(sizeof(struct treeNode));
	root->left = root->right = NULL;
	root->e = e[0];
	if (n == 1)
		return root;
	int i = 1, j;
	if (e[1] < e[0]) {
		while (i < n && e[i] < e[0]) i++;
		j = i;
		while (j < n && e[j] >= e[0]) j++;
		if (j != n) {
			flag = 1;
			return NULL;
		}
		if (i < n) {
			if(mirror == 0)
				mirror = -1;
			else if (mirror == 1) {
				flag = 1;
				return NULL;
			}
		}
	}
	else {
		while (i < n && e[i] >= e[0]) i++;
		j = i;
		while (j < n && e[j] < e[0]) j++;
		if (j != n) {
			flag = 1;
			return NULL;
		}
			if(i < n){
				if (mirror == 0)
					mirror = 1;
				else if (mirror == -1) {
					flag = 1;
					return NULL;
				}
		}
	}
	root->left = buildTree(root->left, e + 1, i - 1);
	if(flag == 0)
		root -> right = buildTree(root->right, e + i, n - i);
	return root;
}

void printTree(node root) {
	if (root->left == NULL && root->right == NULL)
		cout << root->e << " ";
	else {
		if (root->left != NULL)
			printTree(root->left);
		if (root->right != NULL)
			printTree(root->right);
		cout << root->e << " ";
	}
}
