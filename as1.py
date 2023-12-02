student_num = int(input("Enter number of students: "))

li = []
ab_s = []

for i in range(0, student_num):
    marks = input("Enter marks of each student if student was absent enter 'ab' : ")
    if marks == 'ab':
        ab_s.append(0)
    else:
        li.append(int(marks))

def avg_score(marklist,total_students):
    j = 0
    for i in marklist:
        j += i
    
    print("Average score of the class is: ", j/total_students)

def high_low(marklist):
    print("Highest score of the class is: ", max(marklist))
    print("Lowest score of the class is: ", min(marklist))

def abs_num(abstlist):
    print("The number of students who were absent for the test are: ",len(abstlist))

def freq(marklist):
    counter = 0
    num = marklist[0]

    for i in marklist:
        curr_freq = marklist.count(i)
        if curr_freq > counter:
            counter = curr_freq
            num = i
    
    print("Marks with the highest frequency are: ", num)



print("Statistics of marks in class: ",end= "\n")

avg_score(li,len(li))
high_low(li)
abs_num(ab_s)
freq(li)