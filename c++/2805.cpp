#include <iostream>
using namespace std;

int Cmp(const void *a, const void *b) {
  return *(int *)b-*(int *)a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tree[1000000] = {0, };
  int n, m, sum=0, x, ans;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>tree[i];
  }
  qsort(tree, n, sizeof(int), Cmp);
  for(int i=1; i<=n; i++) {
    x = tree[i-1]-tree[i];
    if(m-sum<=i*x) {
      ans = tree[i-1];
      ans -= (m-sum)/i;
      if((m-sum)%i) {
        ans--;
      }
      break;
    } else {
      sum += i*x;
    }
  }
  cout<<ans<<endl;
}

// 7 0; 5; 4
// 3 4; 1; 1;
// 2 