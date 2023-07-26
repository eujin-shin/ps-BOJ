#include <iostream>
#define M 100001
using namespace std;

int larr[M]={0, };
int rarr[M]={0, };

int main() {
  int t, n, a, b, l, r, max, count;
  cin>>t;
  while(t--) {
    cin>>n;
    for(int i=0; i<n; i++) {
      cin>>a>>b;
      larr[a]=b;
    }
    max=larr[1]; count=1;
    for(int i=2; i<=n; i++) {
      if(larr[i]>max) continue;
      max=larr[i]; count++;
    }
    cout<<count<<'\n';
  }
}