t = int(input())
for i in range(t):
  n, c = map(int, input().split())
  x = n // c
  if n%c:
    x += 1
  print(x)