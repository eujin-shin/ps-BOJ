#include <iostream>
#include <string>
using namespace std;

int arr[20]={0, };

int main() {
  int n, m=1, k, tmp=0, x=0;
  string s;
  cin>>n>>k;
  cin>>s;
  for(int i=0; i<s.size(); i++) {
    if(s[i]==',') {
      arr[x++]=m*tmp; tmp=0; m=1;
    } else if(s[i]=='-') {
      m=-1;
    } else {
      tmp*=10; tmp+=s[i]-'0';
    }
  }
  arr[x]=m*tmp;
  for(int i=1; i<=k; i++) {
    for(int j=0; j<n-i; j++) {
      arr[j]=arr[j+1]-arr[j];
    }
  }
  for(int i=0; i<n-k; i++) {
    if(i>0) cout<<',';
    cout<<arr[i];
  }
  cout<<'\n';
  return 0;
}