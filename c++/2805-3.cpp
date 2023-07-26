#include <iostream>
using namespace std;

int Cmp(const void *a, const void *b) {
  return *(int *)b-*(int *)a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tree[1000000] = {0, };
  int n, m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>tree[i];
  }
  qsort(tree, n, sizeof(int), Cmp);
  int temp, count=1, len=tree[0];
  while(m>0) {
    temp=(tree[count-1]-tree[count])*count;
    if(m>=temp) {
      m-=temp; len=tree[count]; count++;
    } else {
      len-=(m/count);
      if(m%count) len--;
      break;
    }
  }
  cout<<len<<'\n';
  return 0;
}