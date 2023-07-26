#include <iostream>
using namespace std;

typedef struct city {
  int price, add;
} CITY;

int dp[1001]={0, };
CITY arr[21];

int Cmp(const void *a, const void *b) {
  return ((CITY *)a)->price-((CITY *)b)->price;
}

int GetDp(int n, int c) {
  int max=-1, cur, price, add, i=1;
  while(1) {
    while(arr[max+1].price<=i && max<c-1) {
      max++;
    }
    cur=0;
    for(int j=0; j<=max; j++) {
      price=arr[j].price; add=arr[j].add;
      if(dp[i-price]<0) continue;
      if(dp[i-price]+add>cur) {
        cur=dp[i-price]+add;
      }
    }
    if(cur==0) dp[i]=-1;
    else {
      dp[i]=cur;
      if(cur>=n) break;
    }
    i++;
  }
  return i;
}

int main() {
  ios_base::sync_with_stdio(false);
  int c, n;
  cin>>n>>c;
  for(int i=0; i<c; i++) {
    cin>>arr[i].price>>arr[i].add;
  }
  qsort(arr, c, sizeof(CITY), Cmp);
  cout<<GetDp(n, c)<<'\n';
  return 0;
}