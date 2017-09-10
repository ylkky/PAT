#include<iostream>
#include<cstring>
using namespace std;

int cmp(const void* a, const void *b) {
	return *(char *)b - *(char *)a;
}

int reverse(char *s) {
	int i, ret = 0;
	for (i = 0; i < 4; i++) {
		ret = ret * 10 + s[3 - i] - '0';
	}
	return ret;
}

int char2num(char *s) {
	int i, ret = 0; 
	for (i = 0; i < 4; i++)
		ret = ret * 10 + s[i] - '0';
	return ret;
}

void num2char(int num, char *s) {
	int i;
	for (i = 0; i < 4; i++) {
		s[3 - i] = num % 10 + '0';
		num /= 10;
	}
	s[4] = 0;
}

int main() {
	//freopen("1", "r", stdin);
	char s[5];
	int num1, num2, res;
	scanf("%d", &res);
	/* if (strlen(s) < 4) {
		int l = strlen(s);
		l = 4 - l;
		memcpy(s + l, s, 5 - l);
		for (int j = 0; j < l; j++)
			s[j] = '0';
	}*/
	num2char(res, s);
	do {
		qsort(s, 4, sizeof(char), cmp);
		num1 = char2num(s);
		num2 = reverse(s);
		res = num1 - num2;
		printf("%04d - %04d = %04d\n", num1, num2, res);
		if (res == 0)
			break;
		num2char(res, s);
	} while (res != 6174);
	//fclose(stdin);
	return 0;
}