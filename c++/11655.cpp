#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  getline(cin, str);
  for(int i=0; i<str.length(); i++) {
    if(str[i]>='a' && str[i]<='z') {
      if(str[i]>'z'-13) str[i]-=13;
      else str[i]+=13;
    } else if(str[i]>='A' && str[i]<='Z') {
      if(str[i]>'Z'-13) str[i]-=13;
      else str[i]+=13;
    }
  }
  cout<<str<<'\n';
  return 0;
}