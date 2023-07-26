#include <iostream>
#define M 100000
using namespace std;

typedef struct {
  int a, b, len;
} SOL;

void SetAns(SOL *ans, int a, int b) {
  ans->a=a; ans->b=b;
  ans->len=a+b;
  if(ans->len<0) ans->len=-(a+b);
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int arr[M]={0, };
  int n, min_i=-1, a, b, len;
  SOL ans;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
    if(arr[i]<0) min_i++;
  }
  ans.len=-1;
  if(min_i>0) SetAns(&ans, arr[min_i-1], arr[min_i]);
  if(min_i<n-2) {
    a=arr[min_i+1]; b=arr[min_i+2];
    if(a+b<ans.len || min_i<1) SetAns(&ans, a, b);
  }
  if(min_i>-1 && min_i<n-1) {
    a=min_i;
    for(b=a+1; b<n; b++) {
      while(a-1>-1 && arr[a-1]+arr[b]>0) {
        a--;
      }
      if(arr[a]+arr[b]<ans.len || ans.len==-1) SetAns(&ans, arr[a], arr[b]);
      if(a==0) continue;
      if(-arr[a-1]-arr[b]<ans.len || ans.len==-1) SetAns(&ans, arr[a-1], arr[b]);
    }
  }
  cout<<ans.a<<' '<<ans.b<<'\n';
  return 0;
}