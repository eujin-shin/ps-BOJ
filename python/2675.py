t = int(input())
for i in range(t):
  r, word = input().split()
  r = int(r)
  ans = []
  n = 0
  for a in range(len(word)):
    for i in range(r):
      ans.append(word[a])
  print(''.join(ans))