#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

int N, **m;
int maxd = 0;
vector<int> res;

int findDepth(int root);
int findCom();
int dfs(int p, int child);

int main() {
	cin >> N;
	m = new int*[N];
	int i, j, k, d;
	for (i = 0; i < N; i++) {
		m[i] = new int[N];
		for (j = 0; j < N; j++)
			m[i][j] = 0;
	}
	for (i = 1; i < N; i++) {
		cin >> j >> k;
		m[j-1][k-1] = m[k-1][j-1] = 1;
	}
	if ( (k = findCom()) > 1) {
		cout << "Error: " << k << " components";
		return 0;
	}
	for (i = 0; i < N; i++) {
		k = 0;
		for (j = 0; j < N; j++) 
			k += m[i][j];

		if (k > 1)
			continue;
		//else if (k == 0) {
		//	findCom();
		//	return 0;
		//}
		else if (k == 1) {
			d = findDepth(i);
			if (d > maxd) {
				res.clear();
				res.push_back(i);
				maxd = d;
			}
			else if (d == maxd)
				res.push_back(i);
		}
	}
	sort(res.begin(), res.end());
	while (!res.empty()) {
		cout << res.front() + 1 << endl;
		res.erase(res.begin());
	}
	return 0;
}

int findDepth(int root) {
	int i;
	for (i = 0; i < N; i++)
		if (m[root][i] == 1)
			break;
	return dfs(root, i);
}

int dfs(int p, int child) {
	int i, d = 0, max = 0;
	for (i = 0; i < N; i++) {
		if (m[child][i] == 1 && i != p) {
			d = dfs(child, i) + 1;
			if (d > max)
				max = d;
		}
	}
	return max;
}

int findCom() {
	int i, j, k, count = 0, flag = 0;
	list<int> l;
	list<int>::iterator iter;
	int *know = new int[N];
	for (i = 0; i < N; i++) {
		know[i] = 0;
	}
	while (1) {
		flag = 0;
		for (i = 0; i < N; i++) {
			if (know[i] == 0) {
				flag = 1;
				l.push_back(i);
				while (!l.empty()) {
					k = l.front();
					know[k] = 1;
					l.pop_front();
					for (j = 0; j < N; j++)
						if (know[j] == 0 && m[k][j] == 1) {
							iter = find(l.begin(), l.end(), j);
							if(iter == l.end())
								l.push_back(j);
						}
				}
				count++;
				break;
			}
		}
		if (flag == 0)
			break;
	}
	return count;

}