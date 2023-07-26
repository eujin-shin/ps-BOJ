#include <iostream>
#include <queue>
using namespace std;

void decomp(int *a, int *b, int *c, int *d, int x) {
  int temp = x;
  *d=temp%10; temp/=10;
  *c=temp%10; temp/=10;
  *b=temp%10; temp/=10;
  *a=temp%10; temp/=10;
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int prime[10][10][10][10] = {0, };
  int arr[10001] = {0, };
  int t, start, dest;
  for(int i=2; i<10000; i++) {
    if(arr[i]) continue;
    for(int j=2*i; j<10000; j+=i) {
      arr[j] = 1;
    }
  }
  int a, b, c, d, temp;
  for(int i=1000; i<10000; i++) {
    if(arr[i]) continue;
    decomp(&a, &b, &c, &d, i);
    prime[a][b][c][d] = 1;
  }
  int now, next, count, ans, cur, pos;
  cin>>t;
  while(t--) {
    int visit[10][10][10][10] = {0, };
    queue <int> q;
    cin>>start>>dest;
    q.push(start);
    now=1; next=0; count=0; ans=-1;
    while(!q.empty()) {
      if(now==0) {
        now=next; next=0; count++;
      }
      cur = q.front(); q.pop();
      if(cur==dest) {
        ans = count; break;
      }
      decomp(&a, &b, &c, &d, cur);
      if(cur==start) {
        visit[a][b][c][d] = 1;
      }
      for(int i=0; i<10; i++) {
        if(prime[i][b][c][d] && visit[i][b][c][d]==0) {
          q.push(i*1000+b*100+c*10+d); next++;
          visit[i][b][c][d]=1;
        }
      }
      for(int i=0; i<10; i++) {
        if(prime[a][i][c][d] && visit[a][i][c][d]==0) {
          q.push(a*1000+i*100+c*10+d); next++;
          visit[a][i][c][d]=1;
        }
      }
      for(int i=0; i<10; i++) {
        if(prime[a][b][i][d] && visit[a][b][i][d]==0) {
          q.push(a*1000+b*100+i*10+d); next++;
          visit[a][b][i][d]=1;
        }
      }
      for(int i=0; i<10; i++) {
        if(prime[a][b][c][i] && visit[a][b][c][i]==0) {
          q.push(a*1000+b*100+c*10+i); next++;
          visit[a][b][c][i]=1;
        }
      }
      now--;
    }
    if(ans==-1) {
      cout<<"Impossible\n";
    } else {
      cout<<ans<<'\n';
    }
  }
  return 0;
}