#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> v;

int Similar(string a, string b) {
  int arr[2][26]={0, }, x, y, tmp;
  for(int i=0; i<a.size(); i++) {
    x=a[i]-'a'; y=b[i]-'a';
    if(arr[0][x]==0 && arr[1][y]==0) {
      arr[0][x]=y+1; arr[1][y]=x+1;
      continue;
    } else if(arr[0][x]==y+1 && arr[1][y]==x+1) {
      continue;
    }
    return 0;
  }
  return 1;
}

int main() {
  string s;
  int n, cnt=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>s;
    for(int j=0; j<v.size(); j++) {
      cnt+=Similar(s, v[j]);
    }
    v.push_back(s);
  }
  cout<<cnt<<'\n';
  return 0;
}