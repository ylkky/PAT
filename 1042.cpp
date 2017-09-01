#include<iostream>

using namespace std;

int k, card[54], p[54], res[54];

void print(int a) {
	int p = a / 13, k = a % 13;
	if (p == 0)
		printf("S");
	else if (p == 1)
		printf("H");
	else if (p == 2)
		printf("C");
	else if (p == 3)
		printf("D");
	else if (p == 4)
		printf("J");
	printf("%d", k + 1);
}

int main() {
	//freopen("1.txt", "r", stdin);
	int i, j;
	int *a, *b, *temp;
	cin >> k;
	for (i = 0; i < 54; i++) {
		card[i] = i;
		res[i] = 0;
		cin >> p[i];
	}
	a = card;
	b = res;
	for (i = 0; i < k; i++) {
		for (j = 0; j < 54; j++) {
			b[p[j] - 1] = a[j];
		}
		temp = a;
		a = b;
		b = temp;
	}
	for (i = 0; i < 53; i++) {
		print(a[i]);
		printf(" ");
	}
	print(a[53]);
	//fclose(stdin);
	return 0;
}