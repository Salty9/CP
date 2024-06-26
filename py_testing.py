from random import randint 
file = open("input", "w")

n = 100000
file.write(f"{n} {n} 80888\n")


for i in range(n):
	file.write(str(i+1))
	file.write(" ")

file.write("\n")

for i in range(n-1):
	x = randint(i+2, n)
	file.write(f"{i+1} {x}\n")
