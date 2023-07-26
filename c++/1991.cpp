#include <iostream>
using namespace std;

typedef struct {
  char self, left, right;
} NODE;

NODE tree[27];

void front(int x) {
  cout<<tree[x].self;
  if(tree[x].left!='.') front(tree[x].left-'A');
  if(tree[x].right!='.') front(tree[x].right-'A');
}

void mid(int x) {
  if(tree[x].left!='.') mid(tree[x].left-'A');
  cout<<tree[x].self;
  if(tree[x].right!='.') mid(tree[x].right-'A');
}

void back(int x) {
  if(tree[x].left!='.') back(tree[x].left-'A');
  if(tree[x].right!='.') back(tree[x].right-'A');
  cout<<tree[x].self;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char temp, l, r;
  int n, x;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>temp>>l>>r;
    tree[temp-'A'].self = temp;
    tree[temp-'A'].left = l;
    tree[temp-'A'].right = r;
  }
  front(0); cout<<'\n';
  mid(0); cout<<'\n';
  back(0); cout<<'\n';
  return 0;
}