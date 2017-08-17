#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findHW(int c, int n, int ** m);

int main() {
	int N, M, K;
	int i, j, k;
	cin >> N >> M >> K;
	int **map = new int*[N];
	for (i = 0; i < N; i++) {
		map[i] = new int[N];
		for ( j = 0; j < N; j++)
		{
			map[i][j] = 0;
		}
	}
	for (i = 0; i < M; i++) {
		cin >> j >> k;
		map[j - 1][k - 1] = map[k - 1][j - 1] = 1;
	}
	//vector<int> q, c;
	int *c = new int[K];
	for (i = 0; i < K; i++) {
		cin >> c[i];
		//c.push_back[j];
	}
	//////////////////////////////
	for (i = 0; i < K; i++)
		findHW(c[i], N, map);
	cin >> i;
	return 0;
}

void findHW(int c, int n, int ** m)
{
	int i, j, k, v, count = 0;
	int *flag = new int[n];
	vector<int> q;
	vector<int>::iterator iter;
	// 拿到第一个没有被占领的城市
	for ( i = 0; i < n; i++)
	{
		if (i != c - 1) {
			v = i;
			break;
		}
	}
	for( i = 0; i < n; i++)
		flag[i] = 0;

	flag[c - 1] = -1;
	flag[v] = 1;
	i = 1;
	while(i < n) {
		//v = q.front();
		j = 0;
		q.push_back(v);
		//v = q.front();
		while (j < q.size()) {
			v = q[j];
			for (k = 0; k < n; k++) {
				if (m[v][k] == 1 && k != c - 1) {
					if (flag[k] == 0) {
						q.push_back(k);
						flag[k] = 1;
					}
				}
			}
			j++;
		}
		i += q.size();
		count++;
		q.clear();
		for (j = 0; j < n; j++) {
			if (flag[j] == 0 && j != c - 1) {
				v = j;
				break;
			}
		}
	}
	cout << count - 1 <<endl;
}