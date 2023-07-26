#include <iostream>
#include <vector>
#define M 50001
using namespace std;

int sum[M]={0, };
int p[3]={0, };
vector <int> v;

int FindMin() {
  int min=0, tmp;
  if(v[p[1]]<v[min]) min=1;
  if(v[p[2]]<v[min]) min=2;
  return min;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, g, a, b, c, min;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>sum[i];
    v.push_back(sum[i]);
    sum[i]+=sum[i-1];
  }
  cin>>m;
  g=sum[m*3]; p[0]=1, p[1]=m+1, p[2]=2*m+1;
  min=FindMin();
  for(int i=m*3+1; i<=n; i++) {
    if(v[i]<v[p[min]]) {
      
    }
  }
}