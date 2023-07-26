#include <iostream>
using namespace std;

int mindp[4][3] = {0, };
int maxdp[4][3] = {0, };

int GetSmall() {
  int x = mindp[0][0], small = 0;
  for(int i=1; i<3; i++) {
    if(x>mindp[i][0]) {
      x = mindp[i][0];
      small = i;
    }
  }
  return small;
}

int GetBig() {
  int x = maxdp[0][0], big = 0;
  for(int i=1; i<3; i++) {
    if(x<maxdp[i][0]) {
      x = maxdp[i][0];
      big = i;
    }
  }
  return big;
}

void GetMin() {
  int small = GetSmall();
  if(small==1) {
    for(int i=0; i<3; i++) {
      mindp[i][1]=mindp[i][1]+mindp[1][0];
    }
  } else if(small==0) {
    mindp[0][1]=mindp[0][1]+mindp[0][0];
    mindp[1][1]=mindp[1][1]+mindp[0][0];
    if(mindp[1][0]>mindp[2][0]) {
      mindp[2][1]=mindp[2][1]+mindp[2][0];
    } else {
      mindp[2][1]=mindp[2][1]+mindp[1][0];
    }
  } else if(small==2) {
    mindp[2][1]=mindp[2][1]+mindp[0][0];
    mindp[1][1]=mindp[1][1]+mindp[0][0];
    if(mindp[1][0]>mindp[0][0]) {
      mindp[0][1]=mindp[0][1]+mindp[0][0];
    } else {
      mindp[0][1]=mindp[0][1]+mindp[1][0];
    }
  }
  for(int i=0; i<3; i++) {
    mindp[i][0] = mindp[i][1];
    mindp[i][1] = 0;
  }
  return;
}

void GetMax() {
  int big = GetBig();
  if(big==1) {
    for(int j=0; j<3; j++) {
      maxdp[j][1]=maxdp[j][1]+maxdp[1][0];
    }
  } else if(big==0) {
    maxdp[0][1]=maxdp[0][1]+maxdp[0][0];
    maxdp[1][1]=maxdp[1][1]+maxdp[0][0];
    if(maxdp[1][0]>maxdp[2][0]) {
      maxdp[2][1]=maxdp[2][1]+maxdp[1][0];
    } else {
      maxdp[2][1]=maxdp[2][1]+maxdp[2][0];
    }
  } else if(big==2) {
    maxdp[2][1]=maxdp[2][1]+maxdp[2][0];
    maxdp[1][1]=maxdp[1][1]+maxdp[2][0];
    if(maxdp[1][0]>maxdp[0][0]) {
      maxdp[0][1]=maxdp[0][1]+maxdp[1][0];
    } else {
      maxdp[0][1]=maxdp[0][1]+maxdp[0][0];
    }
  }
  for(int i=0; i<3; i++) {
    maxdp[i][0] = maxdp[i][1];
    maxdp[i][1] = 0;
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>mindp[0][1]>>mindp[1][1]>>mindp[2][1];
    maxdp[0][1] = mindp[0][1];
    maxdp[1][1] = mindp[1][1];
    maxdp[2][1] = mindp[2][1];
    GetMax(); GetMin();
  }
  x = GetBig();
  cout<<maxdp[x][0]<<' ';
  x = GetSmall();
  cout<<mindp[x][0]<<'\n';
  return 0;
}