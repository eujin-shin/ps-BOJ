#include <iostream>
#include <vector>
using namespace std;

typedef struct {
  int s, d, size;
} SHARK;

int map[101][101]={0, };
SHARK arr[10001];
int m, n;

void Move(SHARK *sh, int *i, int *j) {
  if(sh->d==1) *i-=sh->s; 
  else if(sh->d==2) *i+=sh->s; 
  else if(sh->d==3) *j+=sh->s; 
  else if(sh->d==4) *j-=sh->s;
  while(*i<1 || *i>n || *j>m || *j<1) {
    if(*i<1) {
      *i=-*i+2; sh->d=2;
    } else if(*i>n) {
      *i=n-(*i-n); sh->d=1;
    } else if(*j>m) {
      *j=m-(*j-m); sh->d=4;
    } else if(*j<1) {
      *j=-*j+2; sh->d=3;
    }
  }
  return;
}

int Bigger(int a, int b) {
  if(arr[a].size>arr[b].size) return a;
  return b;
}

void Rearr() {
  vector <pair<pair<int, int>, int> > v;
  int x, y, index;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++) {
      if(map[i][j]!=0) {
        x=j; y=i; index=map[i][j];
        Move(&(arr[index]), &y, &x);
        v.push_back(make_pair(make_pair(x, y), index));
        map[i][j]=0;
      }
    }
  }
  for(int i=0; i<v.size(); i++) {
    x=v[i].first.first; y=v[i].first.second;
    index=v[i].second;
    if(map[y][x]!=0) map[y][x]=Bigger(index, map[y][x]);
    else map[y][x]=index;
  }
  return;
}

int main() {
  int k, r, c, s, d, size, sum=0, index;
  cin>>n>>m>>k;
  for(int i=1; i<=k; i++) {
    cin>>r>>c>>s>>d>>size;
    arr[i].d=d; arr[i].s=s; arr[i].size=size;
    map[r][c]=i;
  }
  for(int i=1; i<=m; i++) {
    for(int j=1; j<=n; j++) {
      if(map[j][i]!=0) {
        index=map[j][i];
        sum+=arr[index].size;
        map[j][i]=0;
        break;
      }
    }
    Rearr();
  }
  cout<<sum<<'\n';
  return 0;
}