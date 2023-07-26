#include <iostream>
using namespace std;

int main() {
  int a, b, sum=0, c=0, num;
  cin>>a>>b; num=1;
  for(int i=1; i<=b; i++) {
    if(i>=a && i<=b) sum+=num;
    c++;
    if(c<num) continue;
    c=0; num++;
  }
  cout<<sum<<'\n';
  return 0;
}