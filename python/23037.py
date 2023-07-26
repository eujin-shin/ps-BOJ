n = int(input())
x=0
while n>0:
  k=n%10
  d=1
  for i in range(5):
    d*=k;
  x+=d; n//=10;
print(x)
