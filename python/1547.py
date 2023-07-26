T = int(input())
x = 1
for i in range(T):
  a, b = map(int, input().split())
  if a==x and b==x:
    continue
  elif a==x:
    x=b
  elif b==x:
    x=a
print(x)