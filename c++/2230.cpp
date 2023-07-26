#include <iostream>
using namespace std;

int GetDif(int a, int b) {
  int ans;
  if(a<0 && b<0) {
    a = -a; b = -b;
  }
  if(a>b) ans = a-b; else ans = b-a;
  return ans;
}

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[100000] = {0, };
  int n, m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  qsort(arr, n, sizeof(int), Cmp);
  int start, end, temp, dif=arr[n-1]-arr[0];
  for(start=0, end=1; end<n; end++) {
    if(arr[end]-arr[start]<m) continue;
    while(arr[end]-arr[start+1]>=m && start+1<end) {
      start++;
    }
    temp = arr[end]-arr[start];
    if(dif>temp) dif=temp;
    if(dif==m) break;
  }
  cout<<dif<<'\n';
  return 0;
}