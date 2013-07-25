#!/bin/python
def min_cost(N, K, C):
    assert N == len(C)
    C.sort(reverse=True)
    total_cost = 0
    x_carry = 0
    x = 0
    i = 0
    while i < N:
        total_cost = total_cost + (x_carry + 1) * C[i]
        i = i + 1
        x = x + 1
        if x >= K:
            x = 0
            x_carry = x_carry + 1
    return total_cost

# code snippet illustrating input/output methods 
N, K = raw_input().split()
N = int(N)
K = int(K)
C = []

numbers = raw_input()

i = 0
for number in numbers.split():
   C.append( int(number) )
   i = i+1

result = min_cost(N, K, C)
print result