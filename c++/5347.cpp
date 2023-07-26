#include <iostream>
using namespace std;

int GetLcd(int a, int b) {
  int lcd, big, small;
  if(a>b) {
    big=a; small=b;
  } else if(b>a) {
    big=b; small=a;
  } else {
    return a;
  }
  if(big%small==0) {
    return small;
  } else {
    return GetLcd(big-small, small);
  }
}

int main() {
  long long lcm;
  int t, lcd, a, b;
  cin>>t;
  for(int i=0; i<t; i++) {
    cin>>a>>b;
    lcd = GetLcd(a, b);
    lcm = (long long)a*(long long)b;
    lcm /= (long long)lcd;
    cout<<lcm<<endl;
  }
  return 0;
}