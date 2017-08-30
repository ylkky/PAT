#include<iostream>
#include<string>
#include<queue>

using namespace std;

class user {
public:
	string name, psw;
};

bool check(string psw) {
	int i, n = psw.size();
	for (i = 0; i < n; i++) {
		if ( psw[i] == '1' || psw[i] == 'l' || psw[i] == '0' || psw[i] == 'O')
			return false;
	}
	return true;
}

void modify(string *psw) {
	int i, n = (*psw).size();
	for (i = 0; i < n; i++) {
		if ((*psw)[i] == '1')
			(*psw)[i] = '@';
		else if ((*psw)[i] == 'l')
			(*psw)[i] = 'L';
		else if ((*psw)[i] == '0')
			(*psw)[i] = '%';
		else if ((*psw)[i] == 'O')
			(*psw)[i] = 'o';
	}
}
int main() {
	freopen("case.txt", "r", stdin);
	int i, k, N, cnt = 0;
	queue<int> q;
	cin >> N;
	user *u = new user[N];
	for (i = 0; i < N; i++) {
		cin >> u[i].name >> u[i].psw;
		if (!check(u[i].psw)) {
			cnt++;
			q.push(i);
			modify(&(u[i].psw));
		}
	}
	if (cnt) {
		cout << cnt << endl;
		for (i = 0; i < cnt; i++) {
			k = q.front();
			q.pop();
			cout << u[k].name << " " << u[k].psw << endl;
		}
	}
	else {
		if (N == 1)
			cout << "There is 1 account and no account is modified" << endl;
		else
			cout << "There are " << N << " accounts and no account is modified" << endl;
	}
	fclose(stdin);
	return 0;
}