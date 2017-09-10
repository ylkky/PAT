#include<iostream>
#include<queue>
using namespace std;

int N, M, *V, **F, **m;

int cmp(const void *a, const void *b) {
	return *(int *)b - *(int *)a;
}

void dp() {
	int i, j;
	F = (int **)malloc(sizeof(int *) * (M + 1));
	m = (int **)malloc(sizeof(int *) * (M + 1));
	for (i = 0; i <= M; i++) {
		F[i] = (int *)malloc(sizeof(int) * (N + 1));
		m[i] = (int *)malloc(sizeof(int) * (N + 1));
		F[i][0] = 0;
		m[i][0] = 0;
	}
	for (i = 1; i <= N; i++) {
		F[0][i] = 0; 
		m[0][i] = 0;
	}
	for (i = 1; i <= M; i++) {		//i is value j is coin num
		for (j = 1; j <= N; j++) {
			if (V[j - 1] <= i) {
				if (F[i][j - 1] > F[i - V[j - 1]][j - 1] + V[j - 1]) {
					F[i][j] = F[i][j - 1];
					m[i][j] = 0;
				}
				else {
					m[i][j] = 1;
					F[i][j] = F[i - V[j - 1]][j - 1] + V[j - 1];
				}
			}
			else {
				F[i][j] = 0;
				m[i][j] = 0;
			}
		}
	}
	//for (i = 0; i <= M; i++) {
	//	cout << "row: " << i << "\t";
	//	for (j = 0; j <= N; j++)
	//		cout << F[i][j] << " ";
	//	cout << endl;
	//}
	//cout << endl;
	//for (i = 0; i <= M; i++) {
	//	cout << "row: " << i << "\t";
	//	for (j = 0; j <= N; j++)
	//		cout << m[i][j] << " ";
	//	cout << endl;
	//}
}

//使用动态规划 dynamic programming
//二维矩阵来表示
int main() {
	freopen("1", "r", stdin);
	int i, j, v, cnt = 0, max, idx, k;
	scanf("%d%d", &N, &M);
	V = (int *)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++) {
		scanf("%d", &v);
		if (v <= M) {
			V[cnt++] = v;
		}
	}
	N = cnt;
	qsort(V, N, sizeof(int), cmp);
	dp();
	for (i = N; i > 0; i--) {
		if (F[M][i] == M)
			break;
	}
	if (i == 0)
		printf("No Solution\n");
	else {
		j = M;
		// trace route
		queue<int> q;
		while (j > 0 && i > 0) {
			while (m[j][i] == 0) i--;
			q.push(V[i - 1]);
			j = j - V[i - 1];
			i--;
		}
		printf("%d", q.front());
		q.pop();
		while (!q.empty()) {
			printf(" %d", q.front());
			q.pop();
		}
	}
	fclose(stdin);
	return 0;
}