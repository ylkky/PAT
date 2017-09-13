#include<iostream>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
#define MAXINT 0x7fffffff

int N, K, start, des, maxh, avg, cnt;
int **m, *h, *know, *dist;
char **name;
vector<int> *v, ret, path;

int findMin(int *dist) {
	int i, min = MAXINT, idx = -1;
	for (i = 0; i < N; i++) {
		if (know[i] == 0 && dist[i] < min) {
			min = dist[i];
			idx = i;
		}
	}
	return idx;
}

void dijkstra(int s) {
	int i, j, k;
	know = new int[N];
	dist = new int[N];
	for (i = 0; i < N; i++) {
		know[i] = 0;
		dist[i] = MAXINT;
	}
	dist[s] = 0;
	for (i = 0; i < N; i++) {
		k = findMin(dist);
		if (k < 0)
			break;
		else {
			know[k] = 1;
			for (j = 0; j < N; j++) {
				if (m[k][j] > 0 && !know[j] && dist[j] > dist[k] + m[k][j]) {
					dist[j] = dist[k] + m[k][j];
					v[j].clear();
					v[j].push_back(k);
				}
				else if (m[k][j] > 0 && dist[j] == dist[k] + m[k][j]) {
					v[j].push_back(k);
				}
			}
		}
	}
}

void dfs(int s, int ha) {
	int i, sum = 0;
	if (s == start) {
		cnt++;
		path.push_back(start);
		ha += h[start];
		if (ha > maxh) {
			maxh = ha;
			ret = path;
			avg = ha / (path.size() - 1);
		}
		else if (ha == maxh && avg < (ha / (path.size() - 1))) {
			ret = path;
			avg = ha / (path.size() - 1);
		}
		path.pop_back();
	}
	else {
		path.push_back(s);
		sum = ha + h[s];
		for (i = 0; i < v[s].size(); i++) {
			dfs(v[s][i], sum);
		}
		path.pop_back();
	}
}

int main() {
	freopen("1", "r", stdin);
	int i, j, k;
	char c1[4], c2[4];
	cin >> N >> K >> c1;
	map<string, int> city;
	maxh = 0;
	cnt = 0;
	city[c1] = 0;
	m = new int*[N];
	h = new int[N];
	v = new vector<int>[N];
	name = new char*[N];
	for (i = 0; i < N; i++) {
		m[i] = new int[N];
		h[i] = 0;
		name[i] = new char[4];
		for (j = 0; j < N; j++)
			m[i][j] = 0;
	}
	strcpy(name[0], c1);
	for (i = 1; i < N; i++) {
		cin >> c1 >> j;
		city[c1] = i;
		h[i] = j;
		strcpy(name[i], c1);
	}
	for (i = 0; i < K; i++) {
		cin >> c1 >> c2 >> j;
		m[city[c1]][city[c2]] = j;
		m[city[c2]][city[c1]] = j;
	}
	start = 0;
	des = city["ROM"];
	dijkstra(start);
	dfs(des, 0);
	cout << cnt << " " << dist[des] << " " << maxh << " " << avg << endl;
	k = ret.size();
	cout << name[ret[k - 1]];
	for (i = k - 2; i >= 0; i--)
		cout << "->" << name[ret[i]];
	fclose(stdin);
	return 0;
}