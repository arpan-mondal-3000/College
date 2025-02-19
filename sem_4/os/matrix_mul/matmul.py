import sys, random
from time import *

n = 512

A = [[random.random() 
		for row in range(n)]
		for col in range(n)]

B = [[random.random() 
		for row in range(n)]
		for col in range(n)]

C = [[random.random() 
		for row in range(n)]
		for col in range(n)]

start = time()

for i in range(n):
	for j in range(n):
		for k in range(n):
			C[i][j] += A[i][k] * B[k][j]

end = time()

print("%0.6f" %(end - start))

#print("a=%d,b=%d" % (5,5))