#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  int a, b, flag=-1;
  cin>>input;
  if(input.size()>1) {
    for(int i=1; i<input.size(); i++) {
      a=1; b=1;
      for(int j=0; j<i; j++) a*=(input[j]-'0');
      for(int j=i; j<input.size(); j++) b*=(input[j]-'0');
      if(a!=b) continue;
      flag=1; break;
    }
  }
  if(flag>0) cout<<"YES\n";
  else cout<<"NO\n";
  return 0;
}