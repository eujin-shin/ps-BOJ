#include <iostream>
using namespace std;

int main() {
  int cur=30, n, x, cnt=0;
  cin>>n;
  while(n--) {
    cin>>x;
    if(cur>x/2 || (x%2==0 && x/2==cur)) cnt++;
    cur-=x;
    if(cur<=0) cur=30;
  }
  cout<<cnt<<'\n';
  return 0;
}