#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int t;
  double x;
  cin>>t;
  cout<<fixed;
  cout.precision(2);
  while(t--) {
    cin>>x;
    getline(cin, s);
    for(int i=0; i<s.size(); i++) {
      if(s[i]==' ') continue;
      else if(s[i]=='@') x*=3;
      else if(s[i]=='%') x+=5;
      else if(s[i]=='#') x-=7;
    }
    cout<<x<<'\n';
  }
  return 0;
}