#include<iostream>
#include<string>
using namespace std;

int add(int a, int i, int* s) {
	*s = a + a + i;
	i = *s / 10;
	*s = *s % 10;
	return i;
}

string calc(string s) {
	string ret;
	int i = s.size() - 1;
	int k = 0, r;
	char ch;
	for (i; i >= 0; i--) {
		k = add(s[i] - '0', k, &r);
		ch = (char)r + '0';
		ret.insert(ret.begin(), ch);
	}
	if (k == 0)
		return ret;
	else
	{
		ch = (char)k + '0';
		ret.insert(ret.begin(), ch);
		return ret;
	}
}

void count(string s, int* a) {
	int i, j;
	for (i = 0; i < 10; i++)
		a[i] = 0;
	for (i = 0; i < s.size(); i++) {
		j = s[i] - '0';
		a[j]++;
	}
}

int main() {
	string s, res;
	int a[10], b[10];
	int i;
	cin >> s;
	res = calc(s);
	count(s, a);
	count(res, b);
	for (i = 0; i < 10; i++) {
		if (a[i] != b[i]) {
			cout << "No" << endl;
			break;
		}
	}
	if (i >= 10)
		cout << "Yes" << endl;
	cout << res << endl;
	return 0;
}
