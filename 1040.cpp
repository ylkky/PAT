#include<iostream>
#include<string>

using namespace std;

int main() {
	//freopen("1.txt", "r", stdin);
	string s;
	getline(cin, s);
	const char *p;
	p = s.c_str();
	int i, j, k, n = s.size();
	int max = 0, cnt;
	for (i = 0; i < n; i++) {
		j = i - 1;
		k = i + 1;
		cnt = 1;
		for (; j >= 0, k < n; j--, k++) {
			if (p[j] != p[k])
				break;
			cnt += 2;
		}
		if (cnt > max)
			max = cnt;
	}
	for (i = 0; i < n; i++) {
		j = i;
		k = i + 1;
		cnt = 0;
		for (; j >= 0, k < n; j--, k++) {
			if (p[j] != p[k])
				break;
			cnt += 2;
		}
		if (cnt > max)
			max = cnt;
	}
	cout << max << endl;
	//fclose(stdin);
	return 0;
}