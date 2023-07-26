#include <iostream>
#include <string>
using namespace std;

int main() {
  string in;
  int h=0, s=0;
  getline(cin, in);
  for(int i=0; i<in.size()-2; i++) {
    if(in[i]!=':' || in[i+1]!='-') continue;
    if(in[i+2]==')') h++;
    else if(in[i+2]=='(') s++;
  }
  if(h==0 && s==0) cout<<"none\n";
  else if(h==s) cout<<"unsure\n";
  else if(h>s) cout<<"happy\n";
  else if(h<s) cout<<"sad\n";
  return 0;
}