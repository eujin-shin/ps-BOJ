word = input()
alp = "abcdefghijklmnopqrstuvwxyz"
ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
n = 0
for i in range(len(alp)):
  a = word.count(alp[i])+word.count(ALP[i])
  if a>n:
    n=a
    ans = ALP[i]
  elif a==n:
    ans = "?"
print(ans)