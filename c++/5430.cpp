#include <iostream>
#include <string.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin>>t;
  string order, arr;
  int num[100000] = {0, };
  while(t--) {
    cin>>order>>n>>arr;
    for(int i=1, x=0; x<n; i+=2) {
      num[x] = arr[i]-'0';
    }
  }
}