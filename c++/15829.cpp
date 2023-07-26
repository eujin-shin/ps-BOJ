#include <iostream>
using namespace std;

int main() {
  unsigned long long h = 0, r = 1, x, m = 1234567891;
  int l;
  char word[52];
  cin>>l;
  cin>>word;
  for(int i=0; i<l; i++) {
    x = (word[i]-'a'+1)*r;
    x %= m;
    h += x;
    r *= 31;
    r %= m;
    if (i==0) continue;
    h %= m;
  }
  cout<<h<<endl;
  return 0;
}