word = input()
a = len(word)
n = 0
if a==1:
  if word!=" ":
    n=n+1
else:
  n = 1
  for i in range(1, a-1):
    x = word[i]
    if x==" ":
      n=n+1
print(n)