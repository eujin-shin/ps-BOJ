#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;
int i=0;
bool flag=true;

int solve() {
  stack <char> st;
  int sum=0, cur=0;
  while(i<s.size()) {
    if(!flag) break;
    if(s[i]=='(' || s[i]=='[') {
      if(st.empty()) {
        st.push(s[i]); i++;
      } else {
        cur+=solve();
      }
    } else {
      if(st.empty()) {
        break;
      } else if(st.top()=='(' && s[i]==']' || st.top()=='[' && s[i]==')') {
        flag=false; break;
      } else {
        if(cur==0) cur=1;
        if(s[i]==')') sum+=cur*2;
        else sum+=cur*3;
        cur=0; st.pop();
        i++;
      }
    }
  }
  if(!st.empty()) flag=false;
  return sum;
}

int main() {
  int ans;
  cin>>s;
  ans=solve();
  if(flag && i==s.length()) cout<<ans<<'\n';
  else cout<<"0\n";
  return 0;
}