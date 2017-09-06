#include<iostream>
#include<string.h>
using namespace std;

char s[4][61];
char date[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main() {
	//freopen("1", "r", stdin);
	int i;
	char d = 0, h = 0;
	int dd, hh, mm;
	for (i = 0; i < 4; i++)
		scanf("%s", s[i]);
	for (i = 0; s[0][i] != 0 && s[1][i] != 0; i++)
		if (s[0][i] >= 'A' && s[0][i] <= 'G' && s[0][i] == s[1][i]) {
			d = s[0][i];
			break;
		}
	for (i = i + 1; s[0][i] != 0 && s[1][i] != 0; i++)
		if (s[0][i] == s[1][i]) {
			if (s[0][i] >= '0' && s[0][i] <= '9' || s[0][i] >= 'A' && s[0][i] <= 'N') {
				h = s[0][i];
				break;
			}	
		}
	for (i = 1; s[2][i] != 0 && s[3][i] != 0; i++)
		if (s[2][i] == s[3][i]) {
			if (s[2][i] >= 'a' && s[2][i] <= 'z' || s[2][i] >= 'A' && s[2][i] <= 'Z') {
				mm = i;
				break;
			}
		}
	if (d >= 'A' && d <= 'N')
		dd = d - 'A';
	if (h >= '0' && h <= '9')
		hh = h - '0';
	else {
		hh = h - 'A' + 10;
	}
	printf("%s %02d:%02d\n", date[dd], hh, mm);
	//fclose(stdin);
	return 0;
}