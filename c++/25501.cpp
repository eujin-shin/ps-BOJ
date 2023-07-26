#include <iostream>
#include <string>
using namespace std;

int cnt;

int recursion(string s) {
  int l=0, r=s.size()-1;
  while(1) {
    cnt++;
    if(l>=r) break;
    if(s[l]!=s[r]) return 0;
    l++; r--;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  string s;
  cin>>t;
  for(int i=0; i<t; i++) {
    cnt=0;
    cin>>s;
    cout<<recursion(s)<<' '<<cnt<<'\n';
  }
  return 0;
}