#include<iostream>
using namespace std;
typedef struct AVL_Tree * Node;
//typedef struct AVL_Tree *
struct AVL_Tree {
	int key, height;
	Node left, right;
};
int N;
Node T;

int Height(Node t) {
	if (t == NULL)
		return -1;
	else
		return t->height;
}

Node RotateLL(Node t) {
	Node p1;
	p1 = t->left;
	t->left = p1->right;
	p1->right = t;
	t->height = Height(t->left) > Height(t->right) ? Height(t->left) : Height(t->right) + 1;
	p1->height = Height(p1->left) > Height(p1->right) ? Height(p1->left) : Height(p1->right) + 1;
	return p1;
}

Node RotateRR(Node t) {
	Node p1;
	p1 = t->right;
	t->right = p1->left;
	p1->left = t;
	t->height = (Height(t->left) > Height(t->right) ? Height(t->left) : Height(t->right)) + 1;
	p1->height = (Height(p1->left) > Height(p1->right) ? Height(p1->left) : Height(p1->right)) + 1;
	return p1;
}

Node RotateRL(Node t) {
	t->right = RotateLL(t->right);
	t = RotateRR(t);
	return t;
}

Node RotateLR(Node t) {
	t->left = RotateRR(t->left);
	return RotateLL(t);
}

Node insert(int key, Node t) {
	if (t == NULL) {
		t = (Node)malloc(sizeof(*t));
		t->left = t->right = NULL;
		t->height = 0;
		t->key = key;
	}
	else if (t->key > key) {
		t->left = insert(key, t->left);
		if (Height(t->left) - Height(t->right) > 1 ) {
			if (key < t->left->key)
				t = RotateLL(t);
			else
				t = RotateLR(t);
		}

	}
	else if (t->key < key) {
		t->right = insert(key, t->right);
		if (Height(t->right) - Height(t->left) > 1) {
			if (key > t->right->key)
				t = RotateRR(t);
			else
				t = RotateRL(t);
		}
	}
	t->height = (Height(t->left) > Height(t->right) ? Height(t->left) : Height(t->right)) + 1;
	return t;
}

int main() {
	//freopen("1", "r", stdin);
	int i, key;
	T = NULL;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &key);
		T = insert(key, T);
	}
	printf("%d\n", T->key);
	//fclose(stdin);
	return 0;
}