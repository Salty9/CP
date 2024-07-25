from random import randint 
file = open("input", "w")

N = 6
n = 2**N
file.write(f"{n}\n")


for i in range(n):
	file.write("A\n")
	file.write(f"{N} {i+1}\n")

