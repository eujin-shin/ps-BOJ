#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> v;

int main() {
  string input;
  int cur, x;
  cin>>input;
  for(int i=0; i<input.size(); i++) {
    x=4; cur=input[i]-'0';
    while(x>0) {
      if(cur>=x) {
        v.push_back(1); cur-=x;
      } else if(v.size()>0) v.push_back(0);
      x/=2;
    }
  }
  if(v.size()==0) {
    cout<<"0\n";
    return 0;
  }
  for(int i=0; i<v.size(); i++) cout<<v[i];
  cout<<'\n';
  return 0;
}