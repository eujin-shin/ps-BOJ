#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <int> v;

int main() {
  string s;
  int x=1, tmp=0;
  cin>>s;
  for(int i=1; i<=s.size(); i++) {
    if(s[s.size()-i]=='1') tmp+=x;
    x*=2;
    if(i%3==0 || i==s.size()) {
      v.push_back(tmp); tmp=0; x=1;
    }
  }
  for(int i=1; i<=v.size(); i++) {
    cout<<v[v.size()-i];
  }
  cout<<'\n';
  return 0;
}