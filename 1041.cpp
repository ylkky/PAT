#include<iostream>
#include<cstring>
using namespace std;

int cnt[10001];

int main() {
	int n;
	cin >> n;
	int *num = new int[n];
	int i;
	memset(cnt, 0, sizeof(int) * 10001);
	for (i = 0; i < n; i++) {
		cin >> num[i];
		cnt[num[i]]++;
	}
	for (i = 0; i < n; i++) {
		if (cnt[num[i]] == 1)
			break;
	}
	if (i < n)
		cout << num[i];
	else
		cout << "None";
	return 0;
}