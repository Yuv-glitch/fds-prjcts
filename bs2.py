n = int(input("Enter number of students in your class: "))
li= []
for i in range(n):
    marks = float(input("Enter marks recieved by each student: "))
    li.append(marks)

print("Unsorted list: ")
print(li)

# Selection sort in Python
def selectionSort(array, size):
   
    for step in range(size):
        min_idx = step

        for i in range(step + 1, size):
            if array[i] < array[min_idx]:
                min_idx = i
         
        (array[step], array[min_idx]) = (array[min_idx], array[step])


size = len(li)
selectionSort(li, size)
print('Selection sorted array in ascending order:')
print(li)

# Bubble sort 

def bubbleSort(array):
    
  for i in range(len(array)):

    
    for j in range(0, len(array) - i - 1):
      if array[j] > array[j + 1]:
        temp = array[j]
        array[j] = array[j+1]
        array[j+1] = temp


bubbleSort(li)

print('First five elements with bubble sort: ')
print(li[0:6])