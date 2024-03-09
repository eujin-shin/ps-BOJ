#include <iostream>
#include <string>
using namespace std;

int arr[10]={0, }, visit[10]={0, }, cnt[26]={0, }, ans=0;
string s;

bool check(int n) {
  for(int i=1; i<n; i++) {
    if(s[arr[i]]==s[arr[i-1]]) return false;
  }
  return true;
}

void Backtrack(int n, int r) {
  if(n==r) {
    if(check(n)) ans++;
    return;
  }
  for(int i=0; i<n; i++) {
    if(visit[i]!=0) continue;
    visit[i]=1; arr[r]=i;
    Backtrack(n, r+1);
    visit[i]=0;
  }
  return;
}

int main() {
  cin>>s;
  Backtrack(s.length(), 0);
  for(int i=0; i<s.length(); i++) ans/=++cnt[s[i]-'a'];
  cout<<ans<<'\n';
  return 0;
}