#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  getline(cin, str, '\n');
  if(str[0]+str[4]-'0'==str[8]) cout<<"YES\n";
  else cout<<"NO\n";
  return 0;
}