import time

def eliminaMultipli(num):
  for x in numeri[numeri.index(num):]:
    if x==num:
      print("Found a new prime number: "+str(x))
      continue
    if num>(num_max/2):
      return
    if x%num==0:
      numeri.remove(x)

num_max=int(input("Insert n to find prime numbers between 0 and n ==> "))
numeri=[]

start_time=time.time()

for x in range(num_max-1):
  numeri.append(x+2)

for numero in numeri:
  eliminaMultipli(numero)

print(numeri)

print("\nTotal prime numbers found: "+str(len(numeri)))

print("Execution time: "+str(time.time()-start_time)+" seconds")
