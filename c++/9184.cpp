#include <iostream>
using namespace std;

int w[21][21][21]={0, };

int GetDp(int a, int b, int c) {
  if(a<=0 || b<=0 || c<=0) return 1;
  if(a>20 || b>20 || c>20) return GetDp(20, 20, 20);
  if(w[a][b][c]!=0) return w[a][b][c];
  else if(a<b && b<c) w[a][b][c]=GetDp(a, b, c-1)+GetDp(a, b-1, c-1)-GetDp(a, b-1, c);
  else w[a][b][c]=GetDp(a-1, b, c)+GetDp(a-1, b-1, c)+GetDp(a-1, b, c-1)-GetDp(a-1, b-1, c-1);
  return w[a][b][c];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c, x;
  cin>>a>>b>>c;
  while(a!=-1 || b!=-1 || c!=-1) {
    x=GetDp(a, b, c);
    cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<x<<"\n";
    cin>>a>>b>>c;
  }
  return 0;
}