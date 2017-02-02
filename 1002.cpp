#include <iostream>
using namespace std;

int main(){
  double *a[2];
  int k[2];
  double ai=0;
  int Ni=0,n[2];
  int max;


  for(int i=0;i<2;i++){
    cin >> k[i];
    a[i]= new double[1001];
    for(int j=0;j<1001;j++)
      a[i][j]=0;
    for(int j=0;j<k[i];j++){
      cin >> Ni;
      cin >> ai;
      if(j==0){
        n[i]=Ni;
      }
      a[i][Ni]=ai;
    }
  }

  max=n[0]>=n[1]?0:1;
  double *sum=new double[n[max]];
  int count=0;

  for(int i=0;i<=n[max];i++){
    if(i<=n[1-max])
      sum[i]=a[max][i]+a[1-max][i];
    else
      sum[i]=a[max][i];
    if(sum[i]!=0)
      count++;
  }

  cout << count;

  cout.setf(ios_base::fixed, ios_base::floatfield);
  cout.precision(1);
  for(int i=n[max];i>=0;i--){
    if(sum[i]!=0){
      cout << " " << i << " " << sum[i];

    }
  }

  delete[] sum;
  return 0;
}
