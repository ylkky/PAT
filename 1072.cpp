#include<iostream>
#include<queue>
#include<memory.h>
#include<map>
using namespace std;

int N, M, K, DS;
int *know, **m, idx;		// N + M
double *avgD, *minD;		//M

int char2num(char * s) {
	int i, ret = 0;
	for (i = 0; s[i] != 0; i++) {
		ret += 10 * ret + s[i] - '0';
	}
	return ret;
}

int getNum(char *s) {
	int ret;
	cin >> s;
	if (s[0] != 'G')
		ret = char2num(s) - 1;
	else
		ret = char2num(s + 1) + N - 1;
	return ret;
}

int findMin(int *dist, int flag) {
	int i, min = -1, idx = 0, ub;
	ub = flag == 0 ? M + N : N;
	for (i = 0; i < ub; i++) {
		if (know[i] == flag){
			if (dist[i] >= 0 && (dist[i] < min || min < 0)) {
				min = dist[i];
				idx = i;
			}
		}
	}
	if (min == -1)
		return -1;
	else
		return idx;
}

void findDist(int g) {
	int i, v, w;
	double sum = 0;
	int *dist = (int *)malloc(sizeof(int) * (N + M));
	memset(know, 0, sizeof(int) * (N + M));
	for (i = 0; i < N + M; i++)
		dist[i] = -1;
	dist[g] = 0;
	i = 0;
	while (1) {
		v = findMin(dist, 0);
		if (v < 0 || i >= N)
			break;
		else {
			if (v < N) {
				if (dist[v] > DS)
					break;
				sum += dist[v];
				i++;
			}
			know[v] = 1;
			for (w = 0; w < N + M; w++) {
				if (!know[w] && m[v][w] > 0) {
					if (dist[w] > 0 && dist[w] > dist[v] + m[v][w])
						dist[w] = dist[v] + m[v][w];
					else if(dist[w] == -1)
						dist[w] = dist[v] + m[v][w];
				}
			}
		}
	}
	if (i >= N) {
		avgD[g - N] = sum / N;
		v = findMin(dist, 1);
		minD[g - N] = dist[v];
	}
}

void print() {
	int i = idx - N + 1;
	printf("G%d\n", i);
	printf("%.1lf %.1lf\n", minD[i - 1], avgD[i - 1]);
}

int main() {
	freopen("1", "r", stdin);
	int i, j, k;
	double maxmin, minavg;
	char s[6];
	cin >> N >> M >> K >> DS;
	m = (int **)malloc(sizeof(int *) * (N + M));
	know = (int *)malloc(sizeof(int) * N + M);
	avgD = (double *)malloc(sizeof(double) * M);
	minD = (double *)malloc(sizeof(double) * M);
	for (i = 0; i < N + M; i++)
		m[i] = (int *)malloc(sizeof(int) * (N + M));
	for (i = 0; i < M + N; i++) {
		printf("&m[i]: %p\n", m[i]);
		for (j = 0; j < M + N; j++)
			m[i][j] = 0;
	}
	for (i = 0; i < M; i++) {
		avgD[i] = -1;
		minD[i] = -1;
	}
	for (i = 0; i < K; i++) {
		j = getNum(s);
		k = getNum(s);
		cin >> m[j][k];
		m[k][j] = m[j][k];
	}
	maxmin = 0;
	for (i = N; i < N + M; i++) {
		findDist(i);
		j = i - N;
		if (minD[j] > maxmin) {
			maxmin = minD[j];
			idx = i;
			minavg = avgD[j];
		}
		else if (minD[j] == maxmin) {
			if (avgD[j] < minavg) {
				idx = i;
				minavg = avgD[j];
			}
		}
	}
	if (maxmin == 0)
		printf("No Solution\n");
	else
		print();
	fclose(stdin);
	return 0;
}