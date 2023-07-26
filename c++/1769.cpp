#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int lev=1, x=0, tmp;
  cin>>s;
  if(s.size()<2) {
    cout<<"0\n";
    if(s[0]%3==0) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
  }
  for(int i=0; i<s.size(); i++) x+=s[i]-'0';
  while(x>9) {
    tmp=0;
    while(x>0) {
      tmp+=x%10; x/=10;
    }
    x=tmp; lev++;
  }
  cout<<lev<<'\n';
  if(x%3==0) cout<<"YES\n";
  else cout<<"NO\n";
  return 0;
}