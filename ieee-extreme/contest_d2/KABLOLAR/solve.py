#python3
num = int(input())

for tst in range(num):
  lst = input().strip().split(' ')
  if(len(lst) == 1):
    print("DAIRE YOK")
    continue
  ff = 0
  mm = 0
  for i in lst:
    if(i=="MM"):
      mm+=1
    if(i=="FF"):
      ff+=1
  if(ff!=mm):
    print("DAIRE YOK")
  else:
    print("DAIRE")
