#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string input;
stack <char> l, r;

void back() {
  if(l.empty()) return;
  l.pop(); return; 
}

void left() {
  if(l.empty()) return;
  r.push(l.top()); l.pop(); return;
}

void right() {
  if(r.empty()) return;
  l.push(r.top()); r.pop(); return;
}

void Print() {
  vector <char> v;
  while(!l.empty()) {
    v.push_back(l.top()); l.pop();
  }
  reverse(v.begin(), v.end());
  while(!r.empty()) {
    v.push_back(r.top()); r.pop();
  }
  for(int i=0; i<v.size(); i++) {
    cout<<v[i];
  }
  cout<<'\n';
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--) {
    cin>>input; 
    l=stack<char>(); r=stack<char>();
    for(int i=0; i<input.size(); i++) {
      if(input[i]=='<') left();
      else if(input[i]=='>') right();
      else if(input[i]=='-') back();
      else l.push(input[i]);
    }
    Print();
  }
  return 0;
}