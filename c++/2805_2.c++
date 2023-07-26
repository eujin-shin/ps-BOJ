#include <iostream>
using namespace std;

int Cmp(const void *a, const void *b) {
  long long x = *(long long *)a, y = *(long long *)b;
  if(x>y) {
    return 1;
  } else if (x<y) {
    return -1;
  } else {
    return 0;
  }
}

int main() {
  long long tree[1000000] = {0, };
  long long sum = 0, x, m;
  int n, i;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>tree[i];
  }
  qsort(tree, n, sizeof(long long), Cmp);
  for(x=1; ; x++) {
    if(m-sum>x*(tree[n-x]-tree[n-x-1])) {
      sum += x*(tree[n-x]-tree[n-x-1]);
      continue;
    } else {
      i = tree[n-x];
      i -= (m-sum)/x;
      if((m-sum)%x) {
        i -= 1;
      }
      break;
    }
  }
  cout<<i<<endl;
}