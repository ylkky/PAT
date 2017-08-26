#include<iostream>
#include<string>

using namespace std;

bool reverse(string s) {
	int i, n = s.size() - 1;
	for (i = 0; i < n - i; i++) {
		if (s[i] != s[n - i])
			return false;
	}
	return true;
}

string add(string s) {
	string res = "";
	int i, j, a = 0, n = s.size();
	char ch;
	for (i = n - 1, j = 0; j < n; j++, i--) {
		a = (s[i] - '0') + (s[j] - '0') + a;
		ch = (a % 10) + '0';
		a = a / 10;
		res = ch + res;
	}
	if (a != 0)
		res = '1' + res;
	return res;
}

int main() {
	string s;
	int i = 0, k;
	cin >> s >> k;
	bool flag;
	for (i = 0; i < k; i++) {
		flag = reverse(s);
		if (flag) {
			cout << s << endl;
			cout << i << endl;
			return 0;
		}
		s = add(s);
	}
	cout << s << endl;
	cout << i << endl;
	return 0;
}