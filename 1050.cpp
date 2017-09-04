#include<iostream>
#include<string.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

char s1[10001], s2[10001];
int flag[128];

int main() {
	//freopen("1.txt", "r", stdin);
	gets_s(s1);
	gets_s(s2);
	int i, n = strlen(s2) + 1;
	memset(flag, 0, 128 * sizeof(int));
	for (i = 0; i < n; i++) {
		flag[(int)s2[i]] = 1;
	}
	n = strlen(s1) + 1;
	for (i = 0; i < n; i++) {
		if (flag[(int)s1[i]] != 1)
			printf("%c", s1[i]);
	}
	printf("\n");
	//fclose(stdin);
	return 0;
}