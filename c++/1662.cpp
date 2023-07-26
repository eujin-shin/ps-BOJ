#include <iostream>
#include <string>
using namespace std;

string s;
int i=0;

int GetLen() {
  int len=0, tmp;
  while(i<s.size()) {
    if(s[i]=='(') {
      tmp=s[i-1]-'0'; i++;
      len+=tmp*GetLen()-1;
    } else if(s[i]==')') {
      i++;
      return len;
    } else {
      len++;
      i++;
    }
  }
  return len;
}

int main() {
  cin>>s;
  cout<<GetLen()<<'\n';
  return 0;
}