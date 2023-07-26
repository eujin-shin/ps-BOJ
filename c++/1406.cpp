#include <iostream>
#include <string>
#include <cstring>
using namespace std;

typedef struct NODE {
  char data;
  NODE *l, *r;
} node;

typedef struct LIST {
  NODE *front;
} list;

list *MakeHead() {
  list *head=new LIST;
  head->front=NULL;
  return head;
}

node *MakeNode(char in) {
  node *newnode=new NODE;
  newnode->data=in;
  return newnode;
}

node *InitList(string s, list *head) {
  head->front=MakeNode('.');
  head->front->l=NULL;
  node *bef=head->front;
  for(int i=0; i<s.size(); i++) {
    bef->r=MakeNode(s[i]);
    bef->r->l=bef; bef=bef->r;
  }
  return bef;
}

node *Left(node *cur) {
  if(cur->l==NULL) return cur;
  return cur->l;
}

node *Right(node *cur) {
  if(cur->r==NULL) return cur;
  return cur->r;
}

node *Delete(node *del, list *head) {
  if(del->l==NULL) return del;
  node *cur=del->l;
  del->l->r=del->r;
  if(del->r!=NULL) del->r->l=del->l;
  delete del;
  return cur;
}

node *Insert(node *cur, list *head, char in) {
  node *newnode=MakeNode(in);
  newnode->l=cur; newnode->r=cur->r;
  if(cur->r!=NULL) cur->r->l=newnode;
  cur->r=newnode;
  return cur->r;
}

void Print(list *head) {
  node *cur=head->front->r;
  while(cur!=NULL) {
    cout<<cur->data;
    cur=cur->r;
  }
  cout<<'\n';
  return;
}

void Break(list *head) {
  node *cur=head->front, *next;
  while(cur!=NULL) {
    next=cur->r;
    delete cur;
    cur=next;
  }
  delete head;
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  list *head=MakeHead();
  node *cur;
  string s;
  char in, order;
  int m;
  cin>>s>>m;
  cur=InitList(s, head);
  for(int i=0; i<m; i++) {
    cin>>order;
    if(order=='P') {
      cin>>in;
      cur=Insert(cur, head, in);
    } else if(order=='L') cur=Left(cur);
    else if(order=='D') cur=Right(cur);
    else if(order=='B') cur=Delete(cur, head);
  }
  Print(head);
  Break(head);
  return 0;
}