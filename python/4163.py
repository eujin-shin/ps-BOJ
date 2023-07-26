ans = []
while True:
  a, b, c = map(int, input().split())
  if a==0:
    break
  else:
    A = a*a
    B = b*b
    C = c*c
    varArr = [A, B, C]
    varArr.sort(reverse=True)
    if varArr[0]==varArr[1]+varArr[2]:
      ans.append("right")
    else:
      ans.append("wrong")
for i in range(len(ans)):
  print(ans[i])