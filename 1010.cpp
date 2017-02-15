#include <iostream>
#include <string>
using namespace std;

long C2D(string n , int r);

int main(){
  string num[2];
  int i,tag,r;
  char radix;
  long long N[2];
  for(i=0;i<2;i++)
    cin >> num[i];
  cin >> tag;
  cin >> r;


  N[0] = C2D(num[tag-1],r);
  //cout << "N[0] = " << N[0] << endl;
  for(i = 2; i <= 36; i++){
    N[1] = C2D(num[2-tag],i);
  //  cout << "radix = " << i << ", N[1] = " << N[1] << endl;
    if(N[0]==N[1]){
      cout << i;
      break;
    }
  }

  if(i==37){
    cout << "Impossible";
  }

  return 0;
}

long C2D(string n , int r){
  int i;
  long res = 0;
  int k;
  char ch;

  for(i=0;i<n.size();i++){
    ch = n.c_str()[i];
    if(ch>='0'&&ch<='9')
      k = ch-'0';
    else
      k = ch -'a' + 10;

    if(k >= r)
      return -1;

    res = k + res*r;
  }

  return res;
}
