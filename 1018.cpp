#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define HALF C/2
#define IFINITE 65533

int findMinDist(vector<int> dist, int *know);
int sendBike(int *path,int C, int *c, int flag,int v);
int backBike(int *path, int C, int *c, int flag, int v);

int main() {
	int i, j, k, v, flag;
	int C, N, S, M;
	int *c, **m;
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
	int *path = new int[N + 1];
	vector<int>::iterator iter;
	for (i = 0; i < N + 1; i++) {
		dist[i] = IFINITE;
		know[i] = 0;
		path[i] = -1;
	}
	path[0] = 0;
	dist[0] = 0;
	while (1) {
		v = findMinDist(dist, know);
		if (v < 0) break;
		know[v] = 1;
		for (i = 1; i <= N; i++) {
			if (know[i] == 0 && m[v][i] != -1) {
				if (dist[v] + m[v][i] < dist[i]) {
					dist[i] = dist[v] + m[v][i];
					path[i] = v;
				}
				else if (dist[v] + m[v][i] == dist[i]) {
					int pre, now;
					pre = sendBike(path, C, c, flag, path[i]);
					now = sendBike(path, C, c, flag, v);
					if (now < pre ) {
						dist[i] = dist[v] + m[v][i];
						path[i] = v;
					}
					else if (now == pre) {
						int bnow, bpre;
						pre = backBike(path, C, c, flag, path[i]);
						now = sendBike(path, C, c, flag, v);
						if (now < pre) {
							dist[i] = dist[v] + m[v][i];
							path[i] = v;
						}
					}
				}
			}
		}
	}
	int send = sendBike(path, C, c, flag, path[S]) , back = backBike(path, C, c, flag, path[S]);
	cout << send << " ";
	vector<int> p;
	i = S;
	while (i != 0) {
		p.push_back(i);
		i = path[i];
	}
	cout << 0;
	for (i = p.size() - 1; i >= 0; i--)
		cout << "->" << p[i];
	cout << " ";
	/*if (flag == 1) {
		back -= HALF;
		back = back >= 0 ? back : 0;
	}
	else
	{
		back += HALF;
		back = back >= 0 ? back : 0;
	}*/
	cout << back;
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

int sendBike(int *path, int C, int *c, int flag, int v) {
	int n = 0, g = 0, j;
	//while (v != 0) {	// 算从路上能拿多少车
	//	n += c[v] - HALF;	// 每个站多余的车
	//	v = path[v];
	//}
	vector<int> p;
	while (v != 0) {
		p.push_back(v);
		v = path[v];
	}
	for (int i = 0; i < p.size();i++) {
		j = p[i];
		if (c[j] < HALF) {
			if (c[j] + g > HALF)
				g -= (HALF - c[j]);
			else {
				n += HALF - g - c[j];
				g = 0;
			}
		}
		else if (c[j] > HALF)
			g += c[j] - HALF;
	}
	if (flag == 1)
		n = n + HALF - g;
	
	return n;
}

int backBike(int *path, int C, int *c, int flag, int v) {
	int n = 0, g = 0, j;
	vector<int> p;
	while (v != 0) {
		p.push_back(v);
		v = path[v];
	}
	for (int i = 0; i < p.size(); i++) {
		j = p[i];
		if (c[j] < HALF) {
			if (c[j] + g > HALF)
				g -= (HALF - c[j]);
			else {
				n += HALF - g - c[j];
				g = 0;
			}
		}
		else if (c[j] > HALF)
			g += c[j] - HALF;
	}
	if (flag == -1) {
		g += HALF;
	}
	else
		g = g > HALF ? g - HALF : 0;

	return g;
}