#include<iostream>
#include<stack>

#define MAX 501
using namespace std;

int findMin(int* dist, int* know);

int N, M, S, D;

int main() {
	int **map, **c;
	int i, j, k;
	cin >> N >> M >> S >> D;
	map = new int*[N];
	c = new int*[N];
	int *dist = new int[N];
	int *cost = new int[N];
	int *know = new int[N];
	int *path = new int[N];
	for (i = 0; i < N; i++){
		map[i] = new int[N];
		c[i] = new int[N];
		for (j = 0; j < N; j++) {
			map[i][j] = MAX;
			c[i][j] = MAX;
			path[i] = -1;
		}
		dist[i] = MAX;
		know[i] = 0;
	}
	for (i = 0; i < M; i++) {
		cin >> j >> k;
		cin >> map[j][k];
		cin >> c[j][k];
		map[k][j] = map[j][k];
		c[k][j] = c[j][k];
	}
	int v, w;
	dist[S] = 0;
	cost[S] = 0;
	while (1) {
		v = findMin(dist, know);
		if (v < 0)
			break;
		else {
			know[v] = 1;
			for (j = 0; j < N; j++) {
				if (!know[j] && map[v][j] != MAX) {
					if (map[v][j] + dist[v] < dist[j]) {
						path[j] = v;
						dist[j] = dist[v] + map[v][j];
						cost[j] = cost[v] + c[v][j];
					}
					else if (map[v][j] + dist[v] == dist[j]) {
						if (cost[v] + c[v][j] < cost[j]) {
							path[j] = v;
							dist[j] = dist[v] + map[v][j];
							cost[j] = cost[v] + c[v][j];
						}
					}
				}
			}
		}
	}
	stack<int> s;
	s.push(D);
	i = D;
	while (i != S) {
		i = path[i];
		s.push(i);
	}
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << dist[D] << " " << cost[D];
	return 0;
}

int findMin(int* dist, int* know) {
	int i, min = MAX, idx = -1;
	for (i = 0; i < N; i++) {
		if (!know[i] && dist[i] < min) {
			min = dist[i];
			idx = i;
		}
	}
	return idx;
}