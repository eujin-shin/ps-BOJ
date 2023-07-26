#include <iostream>
#include <string.h>
using namespace std;

void Cmp(int *a, int *b) {
  if(*a>*b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[1000001] = {0, };
  int n, m, x, a, b;
  string yes = "YES\n", no = "NO\n";
  cin>>n>>m;
  for(int i=0; i<=n; i++) {
    arr[i] = i;
  }
  for(int i=0; i<m; i++) {
    cin>>x>>a>>b;
    if(x==0) {
      Cmp(&a, &b);
      arr[b] = arr[a];
    } else if(x==1) {
      if(arr[a]==arr[b]) cout<<yes;
      else cout<<no;
    }
  }
  return 0;
}