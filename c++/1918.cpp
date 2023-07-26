#include <iostream>
#include <string>
#include <stack>
using namespace std;

int IsOperand(char c) {
  if(c>='A' && c<='Z') return 1;
  return 0;
}

int main() {
  string oper;
  cin>>oper;
  stack <char> s;
  char c, top;
  for(int i=0; i<oper.size(); i++) {
    c=oper[i];
    if(IsOperand(c)) cout<<c;
    else if(c==')') {
      while(!s.empty() && s.top()!='(') {
        cout<<s.top(); s.pop();
      }
      s.pop();
    } else if(c=='(') {
      s.push(c);
    } else if(c=='*' || c=='/') {
      while(!s.empty() && (s.top()=='*' || s.top()=='/')) {
        cout<<s.top(); s.pop();
      }
      s.push(c);
    } else {
      while(!s.empty() && s.top()!='(') {
        cout<<s.top(); s.pop();
      }
      s.push(c);
    }
  }
  while(!s.empty()) {
    cout<<s.top(); s.pop();
  }
  cout<<'\n';
  return 0;
}