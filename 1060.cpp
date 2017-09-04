#include<iostream>
#include<string.h>
using namespace std;
#define MAXD 101

int N;
char A[MAXD], B[MAXD];

void stanForm(char *s) {
	int i, j, p, k, length = strlen(s);
	printf("0.");
	for (i = 0; i < length; i++)
		if (s[i] == '.')
			break;
	p = i;
	if (p == 0) {		//0.xxxx
		for (i = i + 1; i < length; i++)
			if (s[i] != '0')
				break;
		if (i == length) {
			for (i = 0; i < N; i++)
				printf("0");
			printf("*10^0");
		}
		else {
			k = p - i + 1;
			for (j = i; j < i + N && s[j] != 0; j++)
				printf("%c", s[j]);
			if (j < i + N) {
				for (j; j < i + N; j++)
					printf("0");
			}
			printf("*10^%d", k);
		}
	}
	else {
		k = p;
		j = 0;
		for (i = 0; j < N && s[i] != 0; i++) {
			if (i != p) {
				printf("%c", s[i]);
				j++;
			}
		}
		if (s[i] == 0) {
			for (i; i < N; i++) {
				printf("0");
			}
		}
		printf("*10^%d", k);
	}
}

int main() {
	//freopen("1", "r", stdin);
	int i, j, la, lb;
	scanf("%d", &N);
	scanf("%s", A);
	scanf("%s", B);
	for (i = 0; A[i] == '0'; i++);
	strcpy(A, A + i);
	for (i = 0; B[i] == '0'; i++);
	strcpy(B, B + i);
	if (A[0] == '.' && B[0] == '.') {
		for (la = 1; A[la] == '0'; la++);
		for (lb = 1; B[lb] == '0'; lb++);
	}
	else {
		for (la = 0; A[la] != '.' && A[la] != 0; la++);
		for (lb = 0; B[lb] != '.' && B[lb] != 0; lb++);
		if (la == lb)
			la = lb = 0;
	}
	if (A[0] == '.' && B[0] == '.' && A[la] != B[lb]) {
		j = -1;
	}
	else if (A[0] != '.' && B[0] != '.' && la != lb)
		j = -1;
	else {
		j = 0;
		for (i = la; i < N + 1 && j < N; i++, j++) {
			if (A[i] != B[i])
				break;
			if (A[i] == '.')
				j--;
		}
	}
	if (j < N) {
		printf("NO ");
		stanForm(A);
		printf(" ");
		stanForm(B);
	}
	else {
		printf("YES ");
		stanForm(A);
	}
	//fclose(stdin);
	return 0;
}