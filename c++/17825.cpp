#include <iostream>
#include <queue>
using namespace std;

int dice[10]={0, }, pos[4]={0, };
int score=0;
int a[4]={10, 13, 16, 19};
int b[3]={20, 22, 24};
int c[4]={30, 28, 27, 26};
int d[4]={25, 30, 35, 40};

queue <int> q;
int arr[10]={0, };

void Move(int r, int x) {
  if(r==10) {
    if(x>score) score=x;
    return;
  }
  int cur, next, s, flag;
  for(int i=0; i<4; i++) {
    flag=0; s=x;
    cur=pos[i]; next=cur+dice[r];
    if(cur<0) continue;
    else if(cur<100) {
      if(next>20) next=-1;
      else if(next==20) next=403;
      else {
        s+=next*2;
        if(next%5==0) next*=20;
      }
    } else if(cur<200) {
      if(next>103) next+=296;
      else s+=a[next%10];
    } else if(cur<300) {
      if(next>202) next+=197;
      else s+=b[next%10];
    } else if(cur<400){
      if(next>303) next+=96;
      else s+=c[next%10];
    }
    if(next>403) next=-1;
    else if(next>=400) s+=d[next%10];

    for(int j=0; j<4; j++) {
      if(j!=i && next!=-1 && pos[j]==next) flag=1;
    }
    if(flag) continue;
    arr[r]=i;
    pos[i]=next; Move(r+1, s); pos[i]=cur;

  }
  return;
}

int main() {
  for(int i=0; i<10; i++) cin>>dice[i];
  Move(0, 0);
  cout<<score<<'\n';
  return 0;
}
// 5 1 2 3 4 5 5 3 2 4
// 1 1 1 2 3 3 3 3 3 1] 로 이동하면 214가 나옵니다.
/*
10 0 0 0
13 0 0 0
19 0 0 0
0 6 0 0
0 0 8 0
0 0 18 0
0 0 28 0
0 0 34 0
0 0 38 0
40 0 0 0
88 90 36
*/