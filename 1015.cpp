#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n);

int main(){
  int d;
  long n,rn=0;
  cin >> n;
  while(n>0){
    cin >> d;
    if(isPrime(n)){
      while(n){
        rn = n%d + rn*d;
        n/=d;
      }
      if(isPrime(rn))
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
    else
      cout << "No" << endl;

    cin >> n;
    rn = 0;
  }
  return 0;
}

bool isPrime(int n){
  int i;
  if(n==1)
    return false;
  for(i=2;i<=sqrt((double)n);i++){
    if(n%i==0)
      return false;
  }
  return true;
}
