#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;

int N, L, K;
int **map;

/*
gragh is faster than set
*/

void bfs(int id) {
	int v, w, cnt = 0, lv;
	int *know;
	queue<int> *q = new queue<int>[L + 1];
	know = new int[N];
	memset(know, 0, N * sizeof(int));
	q[0].push(id);
	know[id] = 1;
	for (lv = 0; lv < L; lv++) {
		while (!q[lv].empty()) {
			v = q[lv].front();
			q[lv].pop();
			for (w = 0; w < N; w++) {
				if (map[v][w] != 0 && !know[w]) {
					q[lv + 1].push(w);
					know[w] = 1;
				}
			}
		}
		cnt += q[lv + 1].size();
	}
	cout << cnt << endl;
}

int main() {
	//freopen("1", "r", stdin);
	int i, j, k, m;
	cin >> N >> L;
	map = new int*[N];
	for (i = 0; i < N; i++) {
		map[i] = new int[N];
		memset(map[i], 0, N * sizeof(int));
	}
	for (i = 0; i < N; i++) {
		cin >> m;
		for (j = 0; j < m; j++) {
			cin >> k;
			map[k - 1][i] = 1;			// k is followed by m
		}
	}
	cin >> K;
	for (i = 0; i < K; i++) {
		cin >> m;
		bfs(m - 1);
	}
	//fclose(stdin);
	return 0;
}
