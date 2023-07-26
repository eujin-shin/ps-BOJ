#include <iostream>
#define MAX 1000000000
using namespace std;

int input[4]={0, };
int arr[11]={0, };
int ans[11]={0, };

int Calculator(int o, int x, int sum) {
  switch (o) {
    case 0:
      sum+=x;
      break;
    case 1:
      sum-=x;
      break;
    case 2:
      sum*=x;
      break;
    case 3:
      sum/=x;
      break;
  }
  return sum;
}

void BFS(int n, int r, int *min, int *max) {
  if(r==n-1) {
    int sum=arr[0];
    for(int i=1; i<n; i++) {
      sum=Calculator(ans[i-1], arr[i], sum);
    }
    if(*min>sum) *min=sum;
    if(*max<sum) *max=sum;
  } else {
    for(int i=0; i<4; i++) {
      if(input[i]>0) {
        input[i]=input[i]-1;
        ans[r]=i;
        BFS(n, r+1, min, max);
        input[i]=input[i]+1;
      }
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, min=MAX, max=-MAX;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  for(int i=0; i<4; i++) {
    cin>>input[i];
  }
  BFS(n, 0, &min, &max);
  cout<<max<<'\n'<<min<<'\n';
  return 0;
}