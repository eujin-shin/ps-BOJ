#include <iostream>
#include <vector>
#define ll long long
#define ppnt pair<int, pair<ll, ll> >
using namespace std;

vector <ppnt> v[10];
ll arr[10];

ll gcd(ll a, ll b) {
  ll t;
  if(a>b) {
    t=a; a=b; b=t;
  }
  if(b%a==0) return a;
  return gcd(b-a, a);
}

void update(int x, ll k) {
  if(arr[x]==k) return;
  arr[x]=k;
  int y;
  ll p, q;
  for(int i=0; i<v[x].size(); i++) {
    y=v[x][i].first; 
    p=v[x][i].second.first; q=v[x][i].second.second;
    update(y, arr[x]/p*q);
  }
  return;
}

int main() {
  int n, a, b;
  ll p, q, g;
  cin>>n;
  for(int i=0; i<n; i++) arr[i]=1;
  for(int i=1; i<n; i++) {
    cin>>a>>b>>p>>q;
    g=gcd(p, q);
    p/=g; q/=g;
    g=arr[a]*arr[b]/gcd(arr[a], arr[b]);
    update(a, p*g);
    update(b, q*g);
    v[a].push_back(make_pair(b, make_pair(p, q)));
    v[b].push_back(make_pair(a, make_pair(q, p)));
  }
  g=arr[0];
  for(int i=1; i<n; i++) g=gcd(arr[i], g);
  for(int i=0; i<n; i++) {
    if(i!=0) cout<<' ';
    cout<<arr[i]/g;
  }
  cout<<'\n';
  return 0;
}