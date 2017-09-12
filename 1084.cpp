#include<iostream>
#include<memory.h>
using namespace std;

char s[81], t[81];
int cnt[128];

int main() {
	freopen("1", "r", stdin);
	int i, j;
	char ch;
	scanf("%s", s);
	scanf("%s", t);
	memset(cnt, 0, 128 * sizeof(int));
	for (i = 0, j = 0; s[i] != 0; i++) {
		if (s[i] == t[j])
			j++;
		else {
			if (s[i] >= 'a' && s[i] <= 'z')
				ch = s[i] - 'a' + 'A';
			else
				ch = s[i];
			if (cnt[ch] == 0) {
				printf("%c", ch);
				cnt[ch] = 1;
			}
		}
	}
	
	fclose(stdin);
	return 0;
}