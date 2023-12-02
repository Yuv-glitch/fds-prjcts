a = int(input("Enter number of student who play football: "))
foot = []
for i in range(a):
    footname = int(input("Enter student's roll number: "))
    foot.append(footname)
print(foot)

b = int(input("Enter number of student who play cricket: "))
cric = []
for i in range(b):
    cricname = int(input("Enter student's roll number: "))
    cric.append(cricname)
print(cric)

c = int(input("Enter number of student who play batminton: "))
bat = []
for i in range(c):
    batname = int(input("Enter student's roll number: "))
    bat.append(batname)
print(bat)

def problem1(bat,cric):
    lst = []
    for i in bat:
            if i in cric:
                lst.append(i)
    return lst

def problem2(cric,bat):
    lst2 = []
    for i in cric:
        if i not in bat:
            lst2.append(i)
    
    for i in bat:
        if i not in cric:
            lst2.append(i)
    return lst2

def problem3(foot,cric,bat):
    sum = 0
    for i in foot:
        if i not in cric and i not in bat:
            sum = 1 + sum
    return sum

def problem4(foot,cric,bat):
    sum = 0
    for i in cric:
        if i in foot and i not in bat:
            sum = 1 + sum

    return sum


print("List of students who play both cricket and badminton= ",problem1(bat,cric))
print("List of students who play either cricket or badminton but not both= ",problem2(cric,bat))
print("Number of students who play neither cricket nor badminton= ",problem3(foot,cric,bat))
print("Number of students who play cricket and football but not badminton= ",problem4(foot,cric,bat))

