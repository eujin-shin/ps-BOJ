#include <iostream>
using namespace std;

int main() {
  int a, b, c, d, x, cnt;
  cin>>a>>b>>c>>d;
  for(int i=0; i<3; i++) {
    cnt=0;
    cin>>x;
    if(x%(a+b)<=a && x%(a+b)>0) cnt++;
    if(x%(c+d)<=c && x%(c+d)>0) cnt++;
    cout<<cnt<<'\n';
  }
  return 0;
}