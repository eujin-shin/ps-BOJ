#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int itv;
  bool flag=true;
  cin>>s;
  if(s.size()>1) itv=s[1]-s[0];
  for(int i=2; i<s.size(); i++) {
    if(s[i]-s[i-1]!=itv) {
      flag=false; break;
    }
  }
  if(flag) cout<<"◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!\n";
  else cout<<"흥칫뿡!! <(￣ ﹌ ￣)>\n";
  return 0;
}