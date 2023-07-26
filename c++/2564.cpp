#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int arr[400]={0, };
  int pos[5]={0, };
  int w, h, n, v, x, start, cur, len, sum=0;
  cin>>w>>h>>n;
  len=2*(w+h);
  n++;
  pos[2]=2*w+h; pos[3]=pos[2]+h; pos[4]=w;
  while(n--) {
    cin>>v>>x;
    if(v==2) x=pos[2]-x;
    else if(v==3) x=pos[3]-x;
    else if(v==4) x+=pos[4];
    if(n>0) arr[x]=arr[x]+1;
  }
  start=x;
  for(int i=1; i<=w+h; i++) {
    cur=x+i; if(cur>=len) cur-=len;
    sum+=arr[cur]*i; arr[cur]=0;
    cur=x-i; if(cur<0) cur+=len;
    sum+=arr[cur]*i; arr[cur]=0;
  }
  cout<<sum<<'\n';
  return 0;
}