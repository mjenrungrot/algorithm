import sys

lines = sys.stdin.readlines()
for line in lines:
    line = line.strip()
    A, B, C = line.split()

    if A == B and A == C: print('*')
    elif A == B and A != C: print("C")
    elif A == C and A != B: print("B")
    elif B == C and A != B: print("A")