#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string &s1, string &s2) {
	string a = s1 + s2;
	string b = s2 + s1;
	return a < b;
}

int main() {
	//freopen("1.txt", "r", stdin);
	int n, i;
	cin >> n;
	string res = "";
	string *s = new string[n];
	for (i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n, cmp);
	for (i = 0; i < n; i++)
		res = res + s[i];
	const char* cs;
	cs = res.c_str();
	for (i = 0; cs[i] == '0'; i++);
	if (i < res.size())
		cout << cs + i << endl;
	else
		cout << 0;
	//fclose(stdin);
	return 0;
}