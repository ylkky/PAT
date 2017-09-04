#include<iostream>
#include<cstdlib>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;
#define root 0
typedef struct treeNode Node;
typedef struct printRes Res;
//struct leafNode {
//	int id, w;
//};
struct treeNode {
	int n;
	int *leaf;
};

struct printRes {
	int n;
	int *res;
};

int N, M, W;
int *w, sum = 0;
Node *t;
vector<int> s;
vector<Res> res;

bool cmp(Res &r1, Res &r2) {
	int i, n;
	n = r1.n > r2.n ? r2.n : r1.n;
	for (i = 1; i < n; i++) {
		if (r1.res[i] > r2.res[i])
			return true;
		else if(r1.res[i] < r2.res[i])
			return false;
	}
	return false;
}

void print() {
	int i, j, n;
	n = res.size();
	for (j = 0; j < n; j++) {
		printf("%d", res[j].res[0]);
		for (i = 1; i < res[j].n; i++) {
			printf(" %d", res[j].res[i]);
		}
		printf("\n");
	}
	
}

void save() {
	int i, n = s.size();
	Res *r = (Res *)malloc(sizeof(Res));
	r->res = (int *)malloc(sizeof(int) * n);
	r->n = n;
	for (i = 0; i < n; i++) {
		r->res[i] = s[i];
	}
	res.push_back(*r);
}

void dfs(int r) {
	int i;
	sum += w[r];
	if (sum > W) {
		sum -= w[r];
		return;
	}
	else if (sum == W && t[r].n == 0) {
		s.push_back(w[r]);
		save();
		sum -= w[r];
		s.pop_back();
		return;
	}
	else {
		if (t[r].n == 0) {
			sum -= w[r];
			return;
		}
		else if(sum < W){
			s.push_back(w[r]);
			for (i = 0; i < t[r].n; i++) {
				dfs(t[r].leaf[i]);
			}
			s.pop_back();
			sum -= w[r];
		}
		else {
			sum -= w[r];
		}
	}
}

int main() {
	//freopen("1.txt", "r", stdin);
	int i, id, k, j;
	scanf("%d%d%d", &N, &M, &W);
	t = (Node *)malloc(sizeof(Node) * N);
	w = (int *)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &w[i]);
		t[i].n = 0;
		t[i].leaf = NULL;
	}
	for (i = 0; i < M; i++) {
		scanf("%d%d", &id, &k);
		t[id].leaf = (int *)malloc(sizeof(int) * k);
		t[id].n = k;
		for (j = 0; j < k; j++) {
			scanf("%d", &(t[id].leaf)[j]);
		}
	}
	dfs(root);
	sort(res.begin(), res.end(), cmp);
	print();
	//fclose(stdin);
	return 0;
}