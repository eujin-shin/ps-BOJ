#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x, y, k, tmp;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>k;
    int a[5]={0, }, b[5]={0, };
    for(int j=0; j<k; j++) {
      cin>>tmp; a[tmp]++;
    }
    cin>>k;
    for(int j=0; j<k; j++) {
      cin>>tmp; b[tmp]++;
    }
    for(int j=4; j>0; j--) {
      if(a[j]>b[j]) {
        cout<<"A\n"; break;
      } else if(a[j]<b[j]) {
        cout<<"B\n"; break;
      } else if(j==1) {
        cout<<"D\n";
      }
    }
  }
  return 0;
}