num = int(input("Enter number of students who attended training program: "))
li = []
for i in range(num):
    rn = int(input("Enter roll number of student: "))
    li.append(rn)

trg = int(input("Enter roll number you want to search: "))

def linear_srch(lis,target):
    print("Result of linear search")
    flag = 0
    for i in lis:
        if i == target:
            flag = i

    if flag != 0:
        print("Student attended the training program")
        print("Index of ",target," is ",lis.index(flag))
    else:
        print("Student did not attend the training program")
        
def sentinel_srch(lis,target):
    print("Result of sentinel search")
    n = len(lis)
    last = lis[n - 1]

    lis[n - 1] = target
    i = 0
 
    while (lis[i] != target):
        i += 1
 
    lis[n - 1] = last
 
    if ((i < n - 1) or (lis[n - 1] == target)):
        print("Student attended training program")
        print("Index of ", target, " is ",i)
    else:
        print("Student did not attend the training program")

linear_srch(li,trg)
sentinel_srch(li,trg)

num1 = int(input("Enter number of students who attended training program: "))
li1 = []
for i in range(num1):
    rn = int(input("Enter roll number of students in ordered manner: "))
    li1.append(rn)

trg1 = int(input("Enter roll number you want to search: "))

def binary_srch(lis,target):
    low = 0
    high = len(lis) - 1
    mid = 0
 
    while low <= high:
 
        mid = (high + low) // 2
 
        # If x is greater, ignore left half
        if lis[mid] < target:
            low = mid + 1
 
        # If x is smaller, ignore right half
        elif lis[mid] > target:
            high = mid - 1
 
        # means x is present at mid
        else:
            return mid

    return -1
 
result = binary_srch(li1, trg1)
 
if result != -1:
    print("Result of binary search")
    print("Student attended the training program")
else:
    print("Result of binary search")
    print("Student did not attend training program")

def fibonacci_search(lis, target):
    size = len(lis)
     
    start = -1
     
    f0 = 0
    f1 = 1
    f2 = 1
    while(f2 < size):
        f0 = f1
        f1 = f2
        f2 = f1 + f0
     
     
    while(f2 > 1):
        index = min(start + f0, size - 1)
        if lis[index] < target:
            f2 = f1
            f1 = f0
            f0 = f2 - f1
            start = index
        elif lis[index] > target:
            f2 = f0
            f1 = f1 - f0
            f0 = f2 - f1
        else:
            return index
    if (f1) and (lis[size - 1] == target):
        return size - 1
    return -1

res = fibonacci_search(li1,trg1)
if res != -1:
    print("Result of fibonacci search")
    print("Student attended the training program")
    print("Index of ",trg1," is ",res)
else:
    print("Result of fibonacci search")
    print("Student did not attend fibonacci search")