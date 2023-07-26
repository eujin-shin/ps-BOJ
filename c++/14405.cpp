#include <iostream>
#include <string>
using namespace std;

int main() {
  string in;
  bool flag=false;
  cin>>in;
  for(int i=0; i<in.size(); i++) {
    if(in[i]=='p') {
      if(++i>=in.size() || in[i]!='i') break;
    } else if(in[i]=='k') {
      if(++i>=in.size() || in[i]!='a') break;
    } else if(in[i]=='c') {
      if(++i>=in.size() || in[i]!='h') break;
      if(++i>=in.size() || in[i]!='u') break;
    } else break;
    if(i==in.size()-1) flag=true;
  }
  if(flag) cout<<"YES\n";
  else cout<<"NO\n";
  return 0;
}