#include <iostream>
#include <string>
using namespace std;

int main() {
  string in;
  long long cur, sum;
  int n, cnt;
  bool flag=false, num=false;
  sum=0;
  cin>>n>>in;
  for(int i=0; i<n; i++) {
    if(in[i]>='0' && in[i]<='9') num=true;
    else num=false;
    if(!flag && num) {
      cnt=1; cur=in[i]-'0'; flag=true;
    } else if(flag && num) {
      if(cnt==6) {
        cnt=0; flag=false; cur=0;
      } else {
        cnt++; cur=cur*10+in[i]-'0';
      }
    } else if(flag && !num) {
      sum+=cur; flag=false; cnt=0; cur=0;
    }
  }
  if(flag) sum+=cur;
  cout<<sum<<'\n';
  return 0;
}