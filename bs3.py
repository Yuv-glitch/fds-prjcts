n = int(input("Enter number of students in your class: "))
li= []
for i in range(n):
    prctg = int(input("Enter percentage recieved by each student: "))
    li.append(prctg)

def counting_sort(nums, exp):
    n = len(nums)
    output = [0] * n
    count = [0] * 10  # count array to store the count of each digit
    for i in range(n):
        index = nums[i] // exp
        count[index % 10] += 1
    for i in range(1, 10):
        count[i] += count[i - 1]
    i = n - 1
    while i >= 0:
        index = nums[i] // exp
        output[count[index % 10] - 1] = nums[i]
        count[index % 10] -= 1
        i -= 1
    for i in range(n):
        nums[i] = output[i]


def radix_sort(nums):
    max_num = max(nums)
    exp = 1
    while max_num // exp > 0:
        counting_sort(nums, exp)
        exp *= 10


print("List before sorting ",li)
radix_sort(li)
print("List after sorting ",li)