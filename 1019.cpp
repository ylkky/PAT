#include<iostream>
#include<vector>
using namespace std;

int main(){
  long long N,b;
  vector<long long> v;
  cin >> N;
  cin >> b;
  char ch;
  if(N==0){
    cout << "Yes" << endl;
    cout << "0" << endl;
  }
  else{
    v.clear();
    while(N){
      v.push_back(N%b);
      N/=b;
    }

    int i,j=v.size()-1;
    for(i=0;i<j;i++,j--){
      if(v[i]!=v[j]){
        cout << "No" << endl;
        break;
      }
    }
    if(i>=j)
      cout << "Yes" << endl;
    j = v.size()-1;
    for(i=0;i<v.size();i++,j--){
      if(i!=0)
        cout << " ";
      cout << v[j] ;
    }
  }

  return 0;
}
