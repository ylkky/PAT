#include<iostream>
#include<string>

using namespace std;

int main() {
	int i, j, k, n, l;
	string str;
	cin >> str;
	n = str.size();
	k = (n + 2) / 3;
	l = n - 2 * k;
	for (i = 0; i < k - 1; i++) {
		cout << str[i];
		for (j = 0; j < l; j++)
			cout << " ";
		cout << str[n - 1 - i] << endl;
	}
	for (; i < k + l + 1; i++) {
		cout << str[i];
	}
	return 0;
}