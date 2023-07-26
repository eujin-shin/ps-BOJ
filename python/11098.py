n = int(input())
for i in range(n):
  p = int(input())
  max = 0
  ans = ""
  for j in range(p):
    c, name = input().split()
    c=int(c)
    if(c>max):
      max = c
      ans = name
  print(ans)
