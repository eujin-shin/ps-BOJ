#include <iostream>
using namespace std;

int arr[10] = {0, };

int check(int ch) {
  int flag = 1, count = 0;
  while(ch>=0) {
    if(arr[ch%10]) {
      flag = -1; break;
    }
    count++;
    ch/=10;
    if(ch==0) ch=-1;
  }
  if(flag==-1) count=-1;
  return count;
}

int main() {
  int n, m, temp, cur=100, ans;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>temp;
    arr[temp] = 1;
  }
  ans = n-100;
  if(ans<0) ans = -ans;
  for(int i=0; i<ans; i++) {
    temp = check(n+i);
    if(temp!=-1 && ans>i+temp) {
      ans = i+temp;
    }
    if(n-i<0) continue;
    temp = check(n-i);
    if(temp!=-1 && ans>i+temp) {
      ans = i+temp;
    }
  }
  cout<<ans<<'\n';
  return 0;
}