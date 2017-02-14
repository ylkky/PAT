#include <iostream>

using namespace std;

int main(){
  int k,i,sum;
  int max,maxs,s,f;
  cin >> k;
  int a[k];
  for(i=0;i<k;i++)
    cin >> a[i];
  max = sum = 0;
  s = maxs = 0;
  f = k-1;
  for(i=0;i<k;i++){
    sum += a[i];

    if(sum > max){
      max=sum;
      f = i;
      maxs = s;
    }

    if(sum < 0){
      sum = 0;
      s = i+1;
    }

  }

  if(max==0){
    for(i=0;i<k;i++){
      if(a[i]==0){
        maxs = f = i;
        break;
      }
    }
  }

  cout << max << " " << a[maxs] << " " << a[f];
  return 0;
}
