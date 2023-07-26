n = int(input())
l = list(map(int, input().split()))
x = int(input())
l.sort()
i, ans = 0, 0
while l[i]<=x/2:
  if x-l[i] in l[i+1:]:
    ans = ans+1
  i=i+1
print(ans)