#include<iostream>
#include<vector>
using namespace std;
#define MAXN 100000

int N, K;
int nextAddr[MAXN], key[MAXN];

// no empty list, but k == n exist
int main() {
	//freopen("1", "r", stdin);
	vector<int> v, res;
	int i, j, addr;
	cin >> addr >> N >> K;
	for (i = 0; i < N; i++) {
		cin >> j;
		cin >> key[j] >> nextAddr[j];
	}
	if (addr != -1) {
		while (addr != -1) {
			v.push_back(addr);
			addr = nextAddr[addr];
		}
		for (i = 0; i < v.size(); i += K) {
			if (i + K <= v.size())
				for (j = K - 1; j >= 0; j--) {
					res.push_back(v[j + i]);
				}
			else
				for (j = i; j < v.size(); j++)
					res.push_back(v[j]);
		}
		for (i = 0; i < res.size(); i++) {
			if (i == res.size() - 1)
				printf("%05d %d -1\n", res[i], key[res[i]]);
			else
				printf("%05d %d %05d\n", res[i], key[res[i]], res[i + 1]);
		}
	}
	//fclose(stdin);
	return 0;
}