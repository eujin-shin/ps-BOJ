#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string ans, s;
  bool flag=false;
  while(!cin.eof()) {
    getline(cin, s);
    if(flag) ans+="\n";
    flag=true; ans+=s;
  }
  cout<<ans;
  return 0;
}