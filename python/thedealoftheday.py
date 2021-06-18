def solve(nums, start, cc, count):
    if count == k:
        return cc

    total = 0
    for i in range(start, len(nums)):
        total += solve(nums, i+1, cc * nums[i], count + 1)
    return total

# Get input.
nums = []
for num in input().split():
    n = int(num)
    if n > 0:
        nums.append(n)
k = int(input())

# Solve.
if len(nums) < k:
    print(0)
else:
    print(solve(nums, 0, 1, 0))
