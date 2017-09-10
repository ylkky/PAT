#include<iostream>
#include<map>
#include<cstring>
#include<string>
using namespace std;

char s[1048577];

int main() {
	//freopen("1", "r", stdin);
	int i = 0, max = 0;
	char ch;
	string res;
	map<string, int> m;
	while ((ch = getchar()) != '\n')
	{
		if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z')
			s[i] = ch;
		else if (ch >= 'A' && ch <= 'Z')
			s[i] = ch - 'A' + 'a';
		else {
			s[i] = '\0';
			if(i > 0)
				m[s]++;
			i = 0;
			continue;
		}
		i++;
	}
	s[i] = 0;
	m[s]++;
	map<string, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		if (it->second > max) {
			max = it->second;
			res = it->first;
		}
	}
	cout << res << " " << max << endl;
	//fclose(stdin);
	return 0;
}