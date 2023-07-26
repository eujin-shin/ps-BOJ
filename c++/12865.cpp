#include <iostream>
using namespace std;

int dp[100010][110] = {0, };

typedef struct {
  int weight, value;
} object;

int Cmp(const void *a, const void *b) {
  object x = *(object *)a, y = *(object *)b;
  if(x.weight-y.weight==0) {
    return x.value-y.value;
  }
  return x.weight-y.weight;
}

int GetDp(int k, int n, object arr[]) {
  int max=0, x=1, cur_v, cur_w, flag, flag2;
  for(int i=arr[1].weight; i<=k; i++) {
    while(arr[x+1].weight<=i) {
      if(x>=n) {
        break;
      }
      x++;
    }
    cout<<x<<" "<<arr[x].weight<<" ";
    max = dp[i-1][0];
    flag = 0;
    for(int j=1; j<=x; j++) {
      cur_v = arr[j].value;
      cur_w = arr[j].weight;
      if(dp[i-cur_w][j]) continue;
      if(max<dp[i-cur_w][0]+cur_v) {
        max = dp[i-cur_w][0]+cur_v;
        flag = j;
      }
    }
    dp[i][0] = max;
    if(flag) {
      cur_w = arr[flag].weight;
      for(int h=1; h<=x; h++) {
        dp[i][h] = dp[i-cur_w][h];
      }
      dp[i][flag] = 1;
      cout<<flag<<" ";
    } else {
      for(int h=1; h<=x; h++) {
        dp[i][h] = dp[i-1][h];
      }
      max = 0;
      for(int h=1; h<=x; h++) {
        for(int l=h; l<=n && arr[l].weight-arr[h].weight<=1; l++) {
          if(dp[i][h]==0 || dp[i][l]) continue;
          if(arr[l].value-arr[h].value>max) {
            max = arr[l].value-arr[h].value;
            flag2 = h;
            flag = l;
          }
        }
        /*
        if(dp[i][h] || dp[i][h-1]==0) continue;
        if(arr[h].weight-arr[h-1].weight==1) {
          if(arr[h].weight-arr[h-1].weight>max) {
            flag = h;
            max = arr[h].weight-arr[h-1].weight;
          }
        }
        */
      }
      if(flag) {
        dp[i][flag] = 1;
        dp[i][flag2] = 0;
        dp[i][0] = dp[i][0] + max;
      }
    }
    cout<<dp[i][0]<<endl;
  }
  return dp[k][0];
}

int main() {
  ios_base::sync_with_stdio(false);
  object arr[105] = {0, };
  int n, k;
  
  cin>>n>>k;
  arr[0].weight = 0;
  for(int i=1; i<=n; i++) {
    cin>>arr[i].weight>>arr[i].value;
  }
  qsort(arr, n+1, sizeof(object), Cmp);
  cout<<GetDp(k, n, arr)<<endl;
}