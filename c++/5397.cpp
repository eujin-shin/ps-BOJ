#include <iostream>
#include <string>
using namespace std;

typedef struct NODE {
  NODE *l, *r;
  char c;
} node;

typedef struct PASS {
  NODE *front, *cur;
} pass;

pass *InitPass() {
  pass *ans=new pass;
  ans->cur=new node;
  ans->cur->l=NULL; ans->cur->r=NULL;
  return ans;
}

pass *Add(pass *ans, char c) {
  node *n = new node;
  n->c=c; n->r=ans->cur->r; n->l=ans->cur;
  if(ans->cur->r!=NULL) ans->cur->r->l=n;
  ans->cur->r=n;
  if(ans->cur->l==NULL) ans->front=n;
  ans->cur=n;
  return ans;
}

pass *Back(pass *ans) {
  if(ans->cur->l==NULL) return ans;
  node *d = ans->cur;
  d->l->r=d->r;
  if(d->r!=NULL) d->r->l=d->l;
  ans->cur=d->l;
  delete d;
  return ans;
}

pass *Left(pass *ans) {
  if(ans->cur->l==NULL) return ans;
  ans->cur=ans->cur->l;
  return ans;
}

pass *Right(pass *ans) {
  if(ans->cur->r==NULL) return ans;
  ans->cur=ans->cur->r;
  return ans;
}

void Print(pass *ans) {
  node *cur=ans->front;
  delete cur->l;
  while(cur!=NULL) {
    cout<<cur->c;
    cur=cur->r;
    if(cur!=NULL) delete cur->l;
  }
  delete ans;
  cout<<'\n';
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string input;
  pass *ans;
  char c;
  int t;
  cin>>t;
  while(t--) {
    ans=InitPass();
    cin>>input;
    for(int i=0; i<input.size(); i++) {
      if(input[i]=='<') ans=Left(ans);
      else if(input[i]=='>') ans=Right(ans);
      else if(input[i]=='-') ans=Back(ans);
      else ans=Add(ans, input[i]);
    }
    Print(ans);
  }
  return 0;
}