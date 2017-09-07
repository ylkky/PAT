#include<iostream>
//#include<map>
#include<set>
using namespace std;

int N, K;
//map<int, long int> cnt;

int main() {
	//freopen("1", "r", stdin);
	int i, j, k, m, min, r;
	double count, t;
	set<int>::iterator it1, it2;
	scanf("%d", &N);
	set<int> *v = new set<int>[N];
	for (i = 0; i < N; i++) {
		scanf("%d", &m);
		for (j = 0; j < m; j++) {
			scanf("%d", &k);	//cin >> k;
			v[i].insert(k);
		}
	}
	scanf("%d", &K); // cin >> K;
	for (k = 0; k < K; k++) {
		scanf("%d%d", &i, &j); // cin >> i >> j;
		i--;
		j--;
		count = 0;
		t = v[i].size() + v[j].size();
		it1 = v[i].begin();
		for (it2 = v[j].begin(); it1 != v[i].end() && it2 != v[j].end();) {
			if (*it1 == *it2) {
				count++;
				it1++;
				it2++;
			}
			else if (*it1 < *it2)
				it1++;
			else
				it2++;
		}
		t -= count;
		t = count / t;
		t *= 100.0;
		printf("%.1lf%%\n", t);
	}
	//fclose(stdin);
	return 0;
}