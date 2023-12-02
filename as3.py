row = int(input("Enter number of rows in the matrix: "))
col = int(input("Enter number of coloumns in the matrix: "))

matrix1 = [[0 for col in range(col)] for row in range(row)]
for i in range(0,row):
    for j in range(0,col):
        print("\n")
        print("Element position of first matrix ", i,j)
        item = int(input("Enter the element: "))
        matrix1[i][j] = item


matrix2 = [[0 for col in range(col)] for row in range(row)]
for i in range(0,row):
    for j in range(0,col):
        print("\n")
        print("Element position of second matrix ", i,j)
        item = int(input("Enter the element: "))
        matrix2[i][j] = item

print("Matrix 1 is: ")
for r in matrix1:
    print(r)

print("Matrix 2 is: ")
for r in matrix2:
    print(r)

def add(mat1,mat2):
    c = [[0 for col in range(col)] for row in range(row)]
    for i in range(len(mat1)):
        for j in range(len(mat1[0])):
            c[i][j] = mat1[i][j] + mat2[i][j]
    
    for r in c:
        print(r)
        
def subtract(mat1,mat2):
    c = [[0 for col in range(col)] for row in range(row)]
    for i in range(len(mat1)):
        for j in range(len(mat1[0])):
            c[i][j] = mat1[i][j] - mat2[i][j]
    
    for r in c:
        print(r)

def multiply(mat1,mat2):
    c = [[0 for col in range(col)] for row in range(row)]
    for i in range(len(mat1)):
        for j in range(len(mat1[0])):
            c[i][j] = mat1[i][j] * mat2[i][j]
    
    for r in c:
        print(r)
        
def transpose(mat1):
    c = [[0 for col in range(col)] for row in range(row)]
    for i in range(len(mat1)):
        for j in range(len(mat1)):
            c[i][j] = mat1[j][i]
    
    for r in c:
        print(r)
        
flag = 0
while flag == 0:
    print("\n")
    print("Operations are:",end=' ')
    print("Add,Substract,Multiply,Transpose")
    print("To end operations type stop")
    print("\n")
    op = input("Enter operation you want to perform: ")
    op = op.lower()
    if op == 'add':
        add(matrix1,matrix2)
    elif op == 'substract':
        subtract(matrix1,matrix2)
    elif op == 'multiply':
        multiply(matrix1,matrix2)
    elif op == 'transpose':
        transpose(matrix1)
    elif op == 'stop':
        flag = 1
    else:
        print("Please enter a valid operation")