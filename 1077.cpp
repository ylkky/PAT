#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int N;

/*
第一种方法：从每个字符串的最后一个字符开始逐个对比， 直到某个字符不同，最后一个case过不去
第二种方法：先反转字符串，再从头用一样的方法对吧，居然没有超时
*/
int main() {
	freopen("1", "r", stdin);
	int i, j;
	char ch;
	vector<string> v;
	string str, ans;
	scanf("%d", &N);
	getchar();
	//input
	for (i = 0; i < N; i++) {
		getline(cin, str);
		reverse(str.begin(), str.end());
		v.push_back(str);
	}
	//compare
	str = v[0];
	for (i = 0; i < str.size(); i++) {
		ch = str[i];
		for (j = 1; j < v.size(); j++) {
			if (ch != v[j][i])
				break;
		}
		if (j < v.size())
			break;
		ans.push_back(ch);
	}
	if (i > 0) {
		reverse(ans.begin(), ans.end());
		cout << ans;
	}
	else
		printf("nai\n");
	fclose(stdin);
	return 0;
}