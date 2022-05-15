mat = [[5,2,4],[8,"_",1],[3,6,7]]
goal = [[1,2,3],[4,5,6],[7,8,"_"]]
seen = [mat]
options = [-1,0,1]

def h(mat):
    score = 9
    for i in range(3):
        for j in range(3):
            if mat[i][j] == goal[i][j]:
                score-=1
    return score

def copy(mat):
    newmat = []
    for i in range(3):
        nr = []
        for j in range(3):
            nr.append(mat[i][j])
        newmat.append(nr)
    return newmat

def nextMat(mat,row,col):
    row_gap = 0
    col_gap = 0;
    for i in range(3):
        for j in range(3):
            if mat[i][j] == "_":
                row_gap = i
                col_gap = j
                break
    new_row = row_gap + row
    new_col = col_gap + col

    newmat = copy(mat)

    if new_row < 0 or new_row > 2 or new_col < 0 or new_col > 2:
        return None
    newmat[new_row][new_col], newmat[row_gap][col_gap] = newmat[row_gap][col_gap], newmat[new_row][new_col]
    return newmat

def solve():

    frontier = [ [mat,[mat]] ]

    expanded = []

    cnt = 0
    min_f = 100
    min_g = 100

    while(cnt < 10000):

        min_f = 100
        cnt+=1
        
        curr = frontier[0]
        print("------------", len(frontier))

        for i in frontier:
            if len(i[1]) + h(i[0]) < min_f:
                if i[0] in expanded:
                    continue;
                curr = i
                min_f =  h(i[0]) + len(i[1])

        currMat = curr[0]
        print(currMat)
        expanded.append(currMat)

        if currMat == goal:
            print("\n\n\n\nSUCCESS")
            for i in currMat:
                print(i)
            return

        for i in options:
            for j in options:
                nxt = nextMat(currMat,i,j)
                if(nxt != None):
                    if nxt in seen:
                        continue
                    frontier.append([nxt,curr[1]+nxt])
                    seen.append(nxt)
                    
solve()