#include<iostream>
#include<vector>

using namespace std;
struct Node {
	int addr;
	char ch;
	int next;
};
int N;
int node[100000];
int flag[100000];

int main() {
	freopen("case.txt", "r", stdin);
	vector<int> w[2];
	int a[2], i, j, k;
	char ch;
	cin >> a[0] >> a[1] >> N;
	for (i = 0; i < N; i++) {
		cin >> j;
		cin >> ch;
		cin >> node[j];
	}
	memset(flag, 0, sizeof(int) * 100000);
	for (i = a[0];  i != -1; i = node[i]) {
		flag[i]++;
	}
	for (i = a[1]; i != -1; i = node[i]) {
		if (flag[i] == 1)
			break;
	}
	if (i > 0)
		printf("%05d", i);
	else
		cout << i;
	fclose(stdin);
	return 0;
}
