#include <iostream>
#include <string>
using namespace std;

long C2D(string n , int r);

int main(){
  string num[2];
  int i,tag, r, step, upper;
  long long N[2];
  char c;
  for(i=0;i<2;i++)
    cin >> num[i];
  cin >> tag;
  cin >> r;

  N[0] = C2D(num[tag-1],r);
  c = num[2 - tag][0];
  for(i = 1; i < num[2 - tag].size(); i++){
      if(num[2 - tag][i] > c)
        c = num[2 - tag][i];
  }
  if(c >= '0' && c <= '9')
    i = c - '0';
  else
    i = c - 'a' + 10;
  i++;
  step = 1024;

  if(num[tag - 1].size() > num[2 - tag].size()){  //给出r的数的长度比较大，所以另一个数的r应该要比较大，至少比r大
    i = i > r? i : r;
  }
  //cout << "N[0] = " << N[0] << endl;
  //for(i = 2; i < 37; i++){
  while(1){
    N[1] = C2D(num[2-tag],i);
  //  cout << "radix = " << i << ", N[1] = " << N[1] << endl;
    if(N[0] == N[1]){
      cout << i;
      break;
    }
    else if(N[1] > N[0]){
      step /= 2;
      upper = i;
      i -= step;
    }
    else
      i += step;
    // no found
    if(i == upper){
      cout << "Impossible";
      break;
    }
  }
//  }

  return 0;
}

long C2D(string n , int r){
  int i;
  long long res = 0;
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
