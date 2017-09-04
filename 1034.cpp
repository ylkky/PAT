#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
using namespace std;
#define MAX 26*26*26

int N, K;
set<int> res;

class Node {
public:
	int p, tt, sum;
	Node() :p(-1), tt(0), sum(0){};
};

class Call {
public:
	int id, t;
	Call(int idd, int tt) :id(idd), t(tt) {};
};

map<int, Node > tree;
map<int, vector<Call> > calls;

int myHash(const char *s);
void findGang();
string findName(int a);
int findRoot(int i);

int main() {
	//freopen("1.txt", "r", stdin);
	int i, j, k, t;
	cin >> N >> K;
	string name;
	for (i = 0; i < N; i++) {
		cin >> name;
		j = myHash(name.c_str());
		cin >> name;
		k = myHash(name.c_str());
		cin >> t;
		Call tmp1(k, t), tmp2(j, t);
		calls[j].push_back(tmp1);
		calls[k].push_back(tmp2);
	}
	map<int, vector<Call> >::iterator citer;
	vector<Call> *p;
	for (citer = calls.begin(); citer != calls.end(); citer++) {
		p = &(*citer).second;
		j = (*citer).first;
		for (i = 0; i < (*p).size(); i++) {
			tree[j].tt += (*p)[i].t;
		}
	}
	//½ÓÏÂÀ´ÕÒcomponents
	findGang();
	j = res.size();
	set<int>::iterator iter;
	cout << j << endl;
	for (iter = res.begin(); iter != res.end(); iter++) {
		name = findName(*iter);
		cout << name << " " << -tree[*iter].p << endl;
	}
	//fclose(stdin);
	return 0;
}

int myHash(const char *s) {
	int i, ret = 0, n = 3;
	for (i = 0; i < n; i++) {
		ret = ret * 26 + (s[i] - 'A');
	}
	return ret;
}

string findName(int a) {
	int i, n = 3, tmp;
	string ret = "";
	char ch;
	for (i = 0; i < n; i++) {
		tmp = a % 26;
		ch = tmp + 'A';
		ret = ch + ret;
		a /= 26;
	}
	return ret;
}

void findGang() {
	map<int, vector<Call> >::iterator i;
	vector<Call>::iterator j;
	int k, kk;
	for (i = calls.begin(); i != calls.end(); i++) {
		for (j = (*i).second.begin(); j != (*i).second.end(); j++) {
				k = findRoot((*i).first);
				kk = findRoot((*j).id);
				if(k != kk && tree[k].tt > tree[kk].tt){		// k's weight > kk's
					tree[k].p += tree[kk].p;
					tree[kk].p = k;
					tree[k].sum += tree[kk].sum + (*j).t;
					tree[kk].sum = 0;
				}
				else if (k != kk && tree[k].tt <= tree[kk].tt) {
					tree[kk].p += tree[k].p;
					tree[k].p = kk;
					tree[kk].sum += (*j).t + tree[k].sum;
					tree[k].sum = 0;
				}
				else if (k == kk)
					tree[k].sum += (*j).t;
		}
	}
	map<int, Node>::iterator iter;
	for (iter = tree.begin(); iter != tree.end(); iter++) {
		if ((*iter).second.p < -2 && (*iter).second.sum > 2 * K) {
			res.insert((*iter).first);
		}
	}
}

int findRoot(int i) {
	int v;
	for (v = i; tree[v].p >= 0; v = tree[v].p);
	return v;
}
