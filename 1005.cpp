#include<iostream>
#include<string>
using namespace std;

int main(){
	int s=0 , i=0;
	string str = "";

	cin >> str;
	int n = str.size();
	const char* ch;

	ch = str.c_str();

	for(int i=0;i<n;i++){
		s += ch[i] - '0';
	}

	int res=0;

	while(s){
		res = res*10 + s%10;
		if(s%10!=0){
			if(i==0)
				i=-1;
		}
		else if(i>=0)
			i++;
		s/=10;
	}

	s = res;

	if(s==0)
		cout << "zero" ;

	while(s){
		switch(s%10){
			case 1:cout << "one";break;
			case 2:cout << "two";break;
			case 3:cout << "three";break;
			case 4:cout << "four";break;
			case 5:cout << "five";break;
			case 6:cout << "six";break;
			case 7:cout << "seven";break;
			case 8:cout << "eight";break;
			case 9:cout << "nine";break;
			case 0:cout << "zero";break;
		}
		s/=10;
		if(s!=0)
			cout << " ";
	}

		while(i>0){
			cout << " zero" ;
			i--;
		}

	return 0;
}
