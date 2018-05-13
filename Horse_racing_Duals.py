import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())
pi = []
for i in range(n):
    pi.append(int(input()))

pi = sorted(pi)
diff = abs(pi[0] - pi[1])
for i in range(1, len(pi) - 1):
    if diff > abs(pi[i] - pi[i + 1]):
        diff = abs(pi[i] - pi[i + 1])

# Write an action using print
# To debug: print("Debug messages...", file=sys.stderr)

print(diff)
