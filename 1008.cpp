#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int i=0,sum=0,f1=0,f2=0,d=0;

  for(;i<n;i++){
    f1=f2;
    cin >> f2;
    d = f2 - f1;
    sum += (d>=0?d*6:d*(-4)) + 5 ;
  }

  cout << sum;

  return 0;
}
