#include <iostream>
#include <vector>
#define MAX 400000
#define INF 2000000000
using namespace std;

vector <int> v;
int st[MAX]= {0, };

int min(int x, int y) {
  if(v[x]<v[y]) return x;
  else if(v[y]<v[x]) return y;
  else if(x<y) return x;
  return y;
}

int init(int l, int r, int n) {
  if(l==r) return st[n]=l;
  int mid=(l+r)/2;
  return st[n]=min(init(l, mid, n*2), init(mid+1, r, n*2+1));
}

int update(int l, int r, int k, int n) {
  if(l>k || r<k || l==r) return st[n];
  int mid=(l+r)/2;
  return st[n]=min(update(l, mid, k, n*2), update(mid+1, r, k, n*2+1));
}

int get(int l, int r, int x, int y, int n) {
  if(l>=x && r<=y) return st[n];
  if(l>y || r<x) return 0;
  int mid=(l+r)/2;
  return min(get(l, mid, x, y, n*2), get(mid+1, r, x, y, n*2+1));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, a, k, x, y;
  cin>>n; v.push_back(INF);
  for(int i=0; i<n; i++) {
    cin>>a; v.push_back(a);
  }
  cin>>m;
  init(1, n, 1);
  for(int i=0; i<m; i++) {
    cin>>k>>x>>y;
    if(k==1) {
      v[x]=y;
      update(1, n, x, 1);
    } else {
      cout<<get(1, n, x, y, 1)<<'\n';
    }
  }
  return 0;
}