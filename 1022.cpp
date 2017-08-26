#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>

using namespace std;

class Book {
public:
	unsigned long id;
	string title, author, puber;
	int year;
	Book(unsigned long _id, string t, string a, string p, int y) :id(_id), title(t), author(a), puber(p), year(y) {};
};

int N, M;
vector<string> ids;

void findBook(map<string, vector<int>> store, string idx);
void findBook(map<int, vector<int>> store, int idx);



int main() {
	int i, pos;
	string id, y;
	char ch;
	vector<Book> bs;
	map<string, vector<int>> kws, ts, as, ps, ys;
	string t, a, p, kw, key;
	cin >> N;
	cin.ignore();	// skip '\n'
	for (i = 0; i < N; i++) {
		getline(cin, id);
		ids.push_back(id);
		getline(cin, t);
		getline(cin, a);
		getline(cin, kw);
		getline(cin, p);
		getline(cin, y);
		ts[t].push_back(i);
		as[a].push_back(i);
		pos = kw.find(' ', 0);
		while (pos > 0) {
			key = kw.substr(0, pos);
			kws[key].push_back(i);
			kw = kw.substr(pos + 1);
			pos = kw.find(' ', 0);
		}
		kws[kw].push_back(i);
		ps[p].push_back(i);
		ys[y].push_back(i);
	}
	cin >> M;
	cin.ignore();
	int qNum;
	string qstr;
	for (i = 0; i < M; i++) {
		getline(cin, qstr);
		cout << qstr << endl;
		qNum = qstr[0] - '0';
		qstr = qstr.substr(3);
		switch (qNum)
		{
		case 1:
			findBook(ts, qstr);
			break;
		case 2:
			findBook(as, qstr);
			break;
		case 3:
			findBook(kws, qstr);
			break;
		case 4:
			findBook(ps, qstr);
			break;
		case 5:
			findBook(ys, qstr);
			break;
		default:
			break;
		}
	}
	return 0;
}

void findBook(map<string, vector<int>> store, string idx) {
	int k;
	set<string> res;
	set<string>::iterator iter;
	if (store[idx].size() == 0)
		cout << "Not Found" << endl;
	else {
		int i , n= store[idx].size();
		for (i = 0; i < n; i++) {
			k = store[idx][i];
			res.insert(ids[k]);
		}
		for (iter = res.begin(); iter != res.end(); iter++) {
			cout << *iter << endl;
		}
	}
}
