#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int N;

/*
��һ�ַ�������ÿ���ַ��������һ���ַ���ʼ����Աȣ� ֱ��ĳ���ַ���ͬ�����һ��case����ȥ
�ڶ��ַ������ȷ�ת�ַ������ٴ�ͷ��һ���ķ����԰ɣ���Ȼû�г�ʱ
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