#include <iostream>
#include <string>
using namespace std;

string ans;
int n;

void Check(string tmp, int a, int b) {
  string s=tmp;
  char c;
  for(int i=0; i<a-i; i++) {
    c=s[i]; s[i]=s[a-i]; s[a-i]=c;
  }
  a++;
  for(int i=0; a+i<b-i; i++) {
    c=s[a+i]; s[a+i]=s[b-i]; s[b-i]=c;
  }
  b++;
  for(int i=0; b+i<n-1-i; i++) {
    c=s[b+i]; s[b+i]=s[n-1-i]; s[n-1-i]=c;
  }
  if(ans.compare(s)>0 || (a==1 && b==2)) ans=s;
  return;
}

void Backtrack(int k, string s) {
  char c;
  for(int i=k+1; i<n-1; i++) {
    if(k<0) Backtrack(i, s);
    else Check(s, k, i);
  } 
  return;
}

int main() {
  string s;
  cin>>ans;
  n=ans.length(); s=ans;
  Backtrack(-1, s);
  cout<<ans<<'\n';
  return 0;
}