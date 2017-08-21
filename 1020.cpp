#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define LEFT 0
#define RIGHT 1

void findOrder(int n, int *post, int *in, int max);
int buildTree(int n, int* a, int* b, int** node);
int findSubTree(int t, int* in, int size);
void print(int root, int** node);

int main() {
	int i, n, max = -1;
	cin >> n;
	int * post, *in;
	vector<int> r;
	post = new int[n];
	in = new int[n];
	for (i = 0; i < n; i++) {
		cin >> post[i];
		if (post[i] > max)
			max = post[i];
	}
	for (i = 0; i < n; i++)
		cin >> in[i];
	findOrder(n, post, in, max);

	return 0;
}

void findOrder(int n, int *post, int *in, int max) {
	int **node;
	int i;
	node = new int*[max + 1];
	for (i = 0; i <= max; i++) {
		node[i] = new int[2];
		node[i][0] = -1;	// left
		node[i][1] = -1;	// right
	}
	int root = buildTree(n, post, in, node);
	print(root, node);
}

int buildTree(int n, int* a, int* b, int** node) {
	if (n <= 0) return -1;
	int root = a[n - 1];
	int i = findSubTree(root, b, n);
	node[root][LEFT] = buildTree(i, a, b, node);
	node[root][RIGHT] = buildTree(n - i - 1, a + i, b + i + 1, node);
	return root;
}

int findSubTree(int t, int* in, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (in[i] == t)
			return i;
	}
}

void print(int root, int** node) {
	queue<int> q;
	int i;
	q.push(root);
	cout << root;
	while (!q.empty()) {
		i = q.front();
		q.pop();
		if (node[i][LEFT] != -1) {
			q.push(node[i][LEFT]);
			cout << " " << node[i][LEFT];
		}
		if (node[i][RIGHT] != -1) {
			q.push(node[i][RIGHT]);
			cout << " " << node[i][RIGHT];
		}
	}
}