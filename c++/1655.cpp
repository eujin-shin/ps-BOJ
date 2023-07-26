#include <iostream>
using namespace std;


void Swap(int *a, int *b) {
  int temp=*a;
  *a=*b;
  *b=temp;
  return;
}

int LessCmp(int a, int b) {
  return b-a;
}

int MoreCmp(int a, int b) {
  return a-b;
}

void Insert(int x, int arr[], int(Cmp)(int a, int b)) {
  arr[0]=arr[0]+1;
  int cur=arr[0];
  arr[cur]=x;
  while(cur>1 && Cmp(arr[cur], arr[cur/2])<0) {
    Swap(arr+cur, arr+cur/2);
    cur/=2;
  }
}

int Pop(int arr[], int(Cmp)(int a, int b)) {
  int del=arr[1], n, i=1;
  arr[1]=arr[arr[0]]; arr[arr[0]]=0;
  arr[0]=arr[0]-1; n=arr[0];
  int left, right, next;
  while(1) {
    next=0;
    left=i*2; right=left+1;
    if(left<=n && Cmp(arr[i], arr[left])>0) {
      next=left;
    }
    if(right<=n && Cmp(arr[i], arr[right])>0) {
      if(Cmp(arr[left], arr[right])>0) next=right; 
    }
    if(next==0) break;
    Swap(arr+i, arr+next);
    i=next;
  }
  return del;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int less[100000]={0, };
  int more[100000]={0, };
  int mid, n, x;
  cin>>n;
  cin>>mid; cout<<mid<<'\n';
  for(int i=1; i<n; i++) {
    cin>>x;
    if(i%2) { // odd; should be 'more'
      if(x>=mid) {
        Insert(x, more, MoreCmp);
      } else {
        Insert(x, less, LessCmp);
        Insert(mid, more, MoreCmp);
        mid = Pop(less, LessCmp);
      }
    } else { // even; should be 'less' 
      if(x<=mid) {
        Insert(x, less, LessCmp);
      } else {
        Insert(x, more, MoreCmp);
        Insert(mid, less, LessCmp);
        mid = Pop(more, MoreCmp);
      }
    }
    cout<<mid<<'\n';
  }
  return 0;
}