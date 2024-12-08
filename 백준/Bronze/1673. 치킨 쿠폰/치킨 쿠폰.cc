#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int sum, coupon, stamp, k;
  while(cin>>coupon) {
    cin>>k;
    sum = 0;
    stamp = 0;
    while(coupon > 0) {
      sum += coupon;
      stamp += coupon;
      coupon = stamp / k;
      stamp = stamp % k;
    }
    cout<<sum<<'\n';
  }
  return 0;
}