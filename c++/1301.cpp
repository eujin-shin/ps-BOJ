#include <iostream>
#include <vector>
using namespace std;

int arr[5]={0, }, n=0, c=0;
vector <int> g, u;

void Make(int r) {
  if(r==n) {
    c++; return;
  }
  int put, get, f;
  for(int i=0; i<u.size(); i++) {
    /*
    연속된 3개의 구슬은 g
    사용할 수 있는 구슬은 u

    u를 차례로 돌면서 하나씩 g로 이동시킴
    g의 맨 앞 원소는 u로 복귀시킴
    만약 개수가 0이라면 복귀시키지 않음
    다음 단계로 재귀
    갯수 배열, 두 벡터를 원상복귀 시키고 continue
    */
    f=0;
    put=u[i]; u.erase(u.begin()+i);
    arr[put]--; g.push_back(put);
    if(g.size()>2) {
      get=g[0]; f++;
      g.erase(g.begin());
      if(arr[get]>0) {
        u.push_back(get); f++;
      }
    }
    Make(r+1);
    arr[put]++;
    u.insert(u.begin()+i, put);
    g.erase(g.end()-1);
    // cout<<put<<'\n';
    if(f==0) continue;
    g.insert(g.begin(), get);
    if(f>1) u.erase(u.end()-1);
  }
  return;
}

int main() {
  int m;
  cin>>m;
  for(int i=0; i<m; i++) {
    cin>>arr[i]; u.push_back(i); n+=arr[i];
  }
  Make(0);
  cout<<c<<'\n';
  return 0;
}