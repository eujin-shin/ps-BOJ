N = int(input())
ans = N
for i in range(N):
  read = []
  word = input()
  for i in range(len(word)):
    letter = word[i]
    if i==0:
      continue
    else:
      if word[i-1]==letter:
        continue
      elif word[i] in read:
        ans=ans-1
        break
      else:
        read.append(word[i-1])
print(ans)