#include <iostream>
#include <string>
using namespace std;

int main(){
	long a,b,sum;
	int i=0,flag=0,j=0;
	cin >> a >> b ;
	sum = a + b ;
	if(sum < 0){
		cout << "-" ;
		sum = -sum;
	}
	else if(sum==0)
		cout << '0';
	int res=0;
	while(sum!=0){
		if(flag==0){
			if(sum%10==0)
				i++;
			else
				flag=1;
		}
		res=sum%10+res*10;
		sum/=10;
		j++;
	}	

	char ch;
	while(res){
		ch=res%10 + '0';
		res /= 10;
		cout << ch;
		j--;
		if(j&&j%3==0)
			cout << ',';
	}

	while(j){
		cout << '0';
		j--;
		if(j&&j%3==0)
			cout << ',';
	}
	return 0;
}
