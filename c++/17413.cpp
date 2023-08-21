#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int main() {
  vector <char> v;
  stack <char> st;
  string s;
  bool tag=false;
  getline(cin, s);
  for(int i=0; i<s.size(); i++) {
    if(tag) {
      v.push_back(s[i]);
      if(s[i]=='>') tag=false;
    } else if(s[i]=='<') {
      while(!st.empty()) {
        v.push_back(st.top()); st.pop();
      }
      tag=true;
      v.push_back(s[i]);
    } else {
      if(s[i]==' ') {
        while(!st.empty()) {
          v.push_back(st.top()); st.pop();
        }
        v.push_back(' ');
      } else {
        st.push(s[i]);
      }
    }
  }
  while(!st.empty()) {
    v.push_back(st.top()); st.pop();
  }
  for(int i=0; i<v.size(); i++) cout<<v[i];
  cout<<'\n';
  return 0;
}