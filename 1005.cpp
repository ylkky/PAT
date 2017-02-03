#include<iostream>
#include<string>
using namespace std;

int main(){
	int s=0;
	string str;
	
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
		s/=10;
	}
	
	s = res;
	
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
	
	return 0;
}
