memo = {}
def memoize(n):
    ans = 1
    for i in range(0, n+1):
        ans = ans * 2 * (2 * i + 1) // (i + 2)
        memo[i] = ans

def catalan(n):
    return memo[n-1]

memoize(5000)
q = int(input())
for i in range(0, q):
    n = int(input())
    print(catalan(n))
