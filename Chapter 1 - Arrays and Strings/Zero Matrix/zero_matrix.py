#https://ide.geeksforgeeks.org/cIVwnlYTED
def printMat(m):
    for i in range(len(m)):
        for j in range(len(m[0])):
            print(m[i][j], end = ' ')
        print()

def nullifyRow(m, row):
    for i in range(1, len(m)):
        m[row][i] = 0

def nullifyColumn(m, col):
    for i in range(1, len(m[0])):
        m[i][col] = 0
'''
def zero_matrix(m):
    if len(m) == 0: return
    rowz, colz = False, False

    for i in range(len(m)):
        if m[0][i] == 0:
            rowz = True
            break
    for i in range(len(m[0])):
        if m[i][0] == 0:
            colz = True
            break

    for i in range(1, len(m)):
        for j in range(1, len(m[0])):
            if m[i][j] == 0:
                m[0][i] = 0
                m[j][0] = 0
    
    for i in range(1, len(m)):
        if m[i][0] == 0:
            nullifyRow(m, i)
    for i in range(1, len(m[0])):
        if m[0][i] == 0:
            nullifyRow(m, i)

    if rowz:
        nullifyRow(m, 0)
    if colz:
        nullifyColumn(m, 0)            
    printMat(m)
'''

def zero_matrix(mat):
    n = len(mat)
    if n == 0: return mat
    m = len(mat[0])
    zero_rows, zero_cols = [], []
    for r in range(n):
        for c in range(m):
            if mat[r][c] == 0:
                zero_rows.append(r)
                zero_cols.append(c)
                break
    for r in zero_rows:
        for c in range(m):
            mat[r][c] = 0
    for c in zero_cols:
        for r in range(n):
            mat[r][c] = 0
    printMat(mat)
    
if __name__ == "__main__":
    mat1 = [[1,1,1,1,1],[1,0,1,1,1],[1,1,1,1,1],[1,1,1,0,1],[2,3,4,5,6]]
    mat2 = [[1,0,1,0,1],[0,0,0,0,0],[1,0,1,0,1],[0,0,0,0,0],[2,0,4,0,6]]
    zero_matrix(mat1)
    #zero_matrix(mat2)
