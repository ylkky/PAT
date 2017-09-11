#include<iostream>
#include<vector>
using namespace std;

int N;
double P, r;
int *a;
vector<int> *v;

//用数组会内存超限，注意对于大于10^5 * 10^5的二维数组要改成其他形式
double dfs(int root, double rate) {
	int i;
	double sum = 0;
	if (a[root] != 0) {
		return P * a[root] * rate;
	}
	for (i = 0; i < v[root].size(); i++) {
		sum += dfs(v[root][i], rate * r);
	}
	return sum;
}

int main() {
	freopen("1", "r", stdin);
	int i, j, k, id;
	double sum;
	cin >> N >> P >> r;
	r = 1 + r / 100.0;
	v = new vector<int>[N];
	a = new int[N];
	for (i = 0; i < N; i++) {
		a[i] = 0;
	}
	for (i = 0; i < N; i++) {
		cin >> k;
		if (k == 0)
			cin >> a[i];
		else {
			for (j = 0; j < k; j++) {
				cin >> id;
				v[i].push_back(id);
			}
		}
	}
	sum = dfs(0, 1.0);
	printf("%.1lf\n", sum);
	fclose(stdin);
	return 0;
}