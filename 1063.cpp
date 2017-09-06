#include<iostream>
#include<map>
#include<set>
using namespace std;

int N, K;
map<int, int> cnt;

int main() {
	//freopen("1", "r", stdin);
	int i, j, k, m;
	double count, t;
	set<int>::iterator iter;
	scanf("%d", &N);
	set<int> *v = new set<int>[N];
	for (i = 0; i < N; i++) {
		scanf("%d", &m);
		for (j = 0; j < m; j++) {
			scanf("%d", &k);	//cin >> k;
			v[i].insert(k);
			cnt[k] |= 1 << i;
		}
	}
	scanf("%d", &K); // cin >> K;
	for (k = 0; k < K; k++) {
		scanf("%d%d", &i, &j); // cin >> i >> j;
		i--;
		j--;
		count = 0;
		t = v[i].size() + v[j].size();
		for (iter = v[i].begin(); iter != v[i].end(); iter++) {
			m = cnt[*iter]&(1 << j);
			if ( m != 0x0)
				count++;
		}
		t -= count;
		t = count / t;
		t *= 100.0;
		printf("%.1lf%%\n", t);
	}
	//fclose(stdin);
	return 0;
}