#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

int N;
int maxd = 0;
vector<int> res;
list<int>* map;

int findDepth(int root);
int findCom();
int dfs(int p, int child);

int main() {
	cin >> N;
	map = new list<int>[N];
	int i, j, k, d;
	for (i = 0; i < N; i++) {
		map[i].clear();
	}
	for (i = 1; i < N; i++) {
		cin >> j >> k;
		map[j - 1].push_back(k - 1);
		map[k - 1].push_back(j - 1);
	}
	if ( (k = findCom()) > 1) {
		cout << "Error: " << k << " components" << endl;
		return 0;
	}

	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}
	for (i = 0; i < N; i++) {
		k = 0;
		k = map[i].size();
		if (k > 1)
			continue;
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
	i = map[root].front();
	return dfs(root, i) + 1;
}

int dfs(int p, int child) {
	int d = 0, max = 0;
	list<int>::iterator i;
	for (i = map[child].begin(); i != map[child].end(); i++){
		if (*i != p) {
			d = dfs(child, *i) + 1;
			if (d > max)
				max = d;
		}
	}
	return max;
}

int findCom() {
	int i, j, k, count = 0, flag = 0;
	list<int> l;
	list<int>::iterator iter, jter;
	int *know = new int[N];
	for (i = 0; i < N; i++) {
		know[i] = 0;
	}
	while (1) {
		flag = 0;
		for (i = 0; i < N; i++) {
			if (know[i] == 0) {		// find first unknown
				flag = 1;
				l.push_back(i);
				while (!l.empty()) {
					k = l.front();
					know[k] = 1;
					l.pop_front();
					for (jter = map[k].begin(); jter != map[k].end(); jter++)
						if (know[*jter] == 0 ) {
							iter = find(l.begin(), l.end(), j);
							if(iter == l.end())
								l.push_back(*jter);
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
