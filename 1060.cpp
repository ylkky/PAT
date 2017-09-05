#include<iostream>
#include<string.h>
using namespace std;
#define MAXD 101

int N;
char A[MAXD], B[MAXD];

int stanForm(char *s) {
	int i, j, k, n;
	for (i = 0; s[i] == '0'; i++);
	if (s[i] == '.') {		//0.000000xxxx
		for (j = i + 1; s[j] == '0'; j++);
		n = s[j] == 0? 0 : i - j + 1;
		for (k = 0; k < N && s[j] != 0; k++, j++)
			s[k] = s[j];
		for (k = k; k < N; k++)
			s[k] = '0';
		s[k] = 0;
	}
	else {
		for (j = i; s[j] != '.' && s[j] != 0; j++);
		n = j - i;
		for (k = 0; i < j && k < N; k++, i++)
			s[k] = s[i];
		if (s[i] == '.') {
			for (i = i + 1; k < N && s[i] != 0; k++, i++)
				s[k] = s[i];
		}
		for (k = k; k < N; k++)
			s[k] = '0';
		s[k] = 0;
	}
	return n;
}

int main() {
	//freopen("1", "r", stdin);
	int i, a, b;
	scanf("%d", &N);
	scanf("%s", A);
	scanf("%s", B);
	a = stanForm(A);
	b = stanForm(B);
	if (a != b) {
		printf("NO 0.%s*10^%d 0.%s*10^%d\n", A, a, B, b);
	}
	else {
		if (strcmp(A, B))
			printf("NO 0.%s*10^%d 0.%s*10^%d\n", A, a, B, b);
		else
			printf("YES 0.%s*10^%d\n", A, a);
	}
	//fclose(stdin);
	return 0;
}
