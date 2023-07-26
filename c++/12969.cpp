#include <iostream>
using namespace std;

int n, k, f=0;
int arr[3]={0, };
char ans[30]={0, };
bool flag=false;

void Btrack(int r, int x, int l) {
  if(l<k-x || x>k) return;
  if(r==n) {
    if(x==k) flag=true;
    return;
  }
  int small=0;
  for(int i=0; i<3; i++) {
    arr[i]+=1; ans[r]=i+'A';
    Btrack(r+1, x+small, l-r);
    if(flag) return;
    arr[i]-=1; small+=arr[i];
  }
  return;
}

int main() {
  int l=0;
  cin>>n>>k;
  for(int i=1; i<n; i++) l+=i;
  Btrack(0, 0, l);
  if(!flag) cout<<"-1\n";
  else {
    for(int i=0; i<n; i++) {
      cout<<ans[i];
    }
    cout<<'\n';
  }
  return 0;
}