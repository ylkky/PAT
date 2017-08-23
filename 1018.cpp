#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define HALF C/2
#define IFINITE 65533

int C, N, S, M;
int *c, **m;
vector<int> ret, res;
int minS = IFINITE, minB = IFINITE;

int findMinDist(vector<int> dist, int *know);
int sendBike(vector<int> p);
int backBike(vector<int> p);
void findWay(vector<int> *path, int *send, int *back);
void dfs(vector<int> *path, int v);

int main() {
	int i, j, k, v, flag;
	cin >> C >> N >> S >> M;
	c = new int[N + 1];
	m = new int*[N + 1];
	for (i = 0; i < N + 1; i++) {	
		m[i] = new int[N + 1];
		for (j = 0; j < N + 1; j++)
			m[i][j] = -1;
	}
	c[0] = 0;
	for (i = 1; i < N + 1; i++)		//capacity
		cin >> c[i];
	for (i = 0; i < M; i++) {		//map
		cin >> j;
		cin >> k;
		cin >> m[j][k];
		m[k][j] = m[j][k];
	}
	flag = (c[S] == 0) ? 1 : -1;
	vector<int> dist(N + 1);
	int *know = new int[N + 1];
	vector<int> *path = new vector<int>[N + 1];
	for (i = 0; i < N + 1; i++) {
		vector<int> tmp;
		dist[i] = IFINITE;
		know[i] = 0;
		path[i] = tmp;
	}
	path[0].push_back(0);
	dist[0] = 0;
	while (1) {
		v = findMinDist(dist, know);
		if (v < 0) break;
		know[v] = 1;
		for (i = 1; i <= N; i++) {
			if (know[i] == 0 && m[v][i] != -1) {	// 所有v可到达的未知节点
				if (dist[v] + m[v][i] < dist[i]) {
					dist[i] = dist[v] + m[v][i];
					path[i].clear();
					path[i].push_back(v);
				}
				else if (dist[v] + m[v][i] == dist[i]) {
					path[i].push_back(v);
				}
			}
		}
	}
	dfs(path, S);
	minB = backBike(res);
	cout << minS << " ";
	cout << 0;
	for (i = res.size() - 1; i >= 0; i--)
		cout << "->" << res[i];
	cout << "->" << S << " ";
	cout << minB;
	return 0;
}

int findMinDist(vector<int> dist, int *know) {
	int i, min = IFINITE, idx;
	int n = dist.size();
	if (n <= 0)return -1;
	for (i = 0; i < n; i++) {
		if (know[i] == 0 && dist[i] < min) {
			min = dist[i];
			idx = i;
		}
	}
	if (min == IFINITE) return -1;
	return idx;
}

int sendBike(vector<int> p) {
	int n = 0, g = 0, j;
	while(!p.empty()) {	
		j = p.back();
		p.pop_back();
		//j = p[i];
		if (c[j] < HALF) {		// 缺车
			if (c[j] + g >= HALF)	//之前拿的车够补
				g -= (HALF - c[j]);
			else {		// 之前的车不够，需要从中心再拿
				n += (HALF - g - c[j]);
				g = 0;
			}
		}
		else if (c[j] > HALF)	// 可以拿到多余的车
			g += (c[j] - HALF);
	}
	if (c[S] < HALF) {
		if (c[S] + g < HALF)
			n = n + (HALF - g - c[S]);
	}
	return n;
}

int backBike(vector<int> p) {
	int n = 0, g = 0, j;
	while (!p.empty()) {
		j = p.back();
		p.pop_back();
		if (c[j] < HALF) {
			if (c[j] + g >= HALF)
				g -= (HALF - c[j]);
			else {
				n += (HALF - g - c[j]);
				g = 0;
			}
		}
		else if (c[j] > HALF)
			g += (c[j] - HALF) ;
	}
	if (c[S] >= HALF) {
		g += (c[S] - HALF);
	}
	else
		g = g > (HALF - c[S]) ? g - (HALF - c[S]) : 0;

	return g;
}

void dfs(vector<int> *path, int v) {
	vector<int>::iterator iter;
	int w, send, back;
	if (v == 0) {
		send = sendBike(ret);
		if (send < minS) {
			res = ret;
			minS = send;
			minB = backBike(ret);
		}
		else if (send == minS) {
			back = backBike(ret);
			if (back < minB) {
				res = ret;
				minB = back;
			}
		}
		return ;
	}
	for (iter = path[v].begin(); iter != path[v].end(); iter++) {
		w = *iter;
		if(w != 0)
			ret.push_back(w);
		dfs(path, w);
		if (w != 0)
			ret.pop_back();
	}
}
