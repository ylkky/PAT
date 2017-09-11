#include<iostream>
#include<cstring>
using namespace std;

char s[10000], r[10000];

//-0.000E-0 = -0.000
//+0.000E+0 = 0.000
int main() {
	//freopen("1", "r", stdin);
	int i, j, e, p, flag = 1, exp;
	scanf("%s", s);
	j = 0;
	if (s[0] == '-')
		r[j++] = '-';
	for (i = 1; s[i] != 0; i++) {
		if (s[i] == '.')
			p = i;
		else if (s[i] == 'E') {
			e = i;
			break;
		}
	}
	if (s[e + 1] == '-')
		flag = -1;
	exp = 0;
	for (i = e + 2; s[i] != 0; i++) {
		exp = exp * 10 + s[i] - '0';
	}
	if (flag < 0) {
		for (i = 0; i < exp; i++, j++)
			r[j] = '0';
	}
	for (i = 1; i < e; i++) {
		if (i != p)
			r[j++] = s[i];
	}
	e = j;
	if (flag < 0) {
		p = 1;
		if (r[0] == '-')
			p++;
	}
	else {
		p += exp;
		if (r[0] != '-')
			p--;
	}
	for (i = 0; i < e; i++) {
		if (i == p)
			printf(".");
		printf("%c", r[i]);
	}
	for (i = e; i < p; i++) {
		printf("0");
	}
	//fclose(stdin);
	return 0;
}