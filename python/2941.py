word = input()
n = len(word)
before_equal = ["c", "s", "z"]
before_bar = ["c", "d"]
before_j = ["n", "l"]
for i in range(1, len(word)):
  if word[i] == "=":
    if word[i-1] in before_equal:
      n = n-1
      if word[i-2:i] == "dz":
        n = n-1
  elif word[i] == "-":
    if word[i-1] in before_bar:
      n = n-1
  elif word[i] == "j":
    if word[i-1] in before_j:
      n = n-1
print(n)