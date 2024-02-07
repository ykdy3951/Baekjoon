import sys
input=sys.stdin.readline


class Node:

    def __init__(self):
        self.left : Node = None
        self.right : Node = None
        self.up : Node = None
        self.down : Node = None
        self.col : Node = None
        self.row = 0
        self.size = 0

class dlx:

    def __init__(self):
        pass

    def cover(self, col : Node):
        col.right.left = col.left
        col.left.right = col.right

        col_iter = col.down
        while col_iter != col:
            row_iter = col_iter.right
            while row_iter != col_iter:
                row_iter.down.up = row_iter.up
                row_iter.up.down = row_iter.down
                row_iter.col.size -= 1
                row_iter = row_iter.right
            col_iter = col_iter.down
    
    def uncover(self, col : Node):
        col_iter = col.up
        while col_iter != col:
            row_iter = col_iter.left
            while row_iter != col_iter:
                row_iter.col.size += 1
                row_iter.down.up = row_iter
                row_iter.up.down = row_iter
                row_iter = row_iter.left
            col_iter = col_iter.up
        col.right.left = col
        col.left.right = col

    def search(self, head : Node, solution : list):
        if head.right == head:
            return True
        ptr : Node = None
        min_size = 1e9
        col_iter = head.right
        while col_iter != head:
            if col_iter.size < min_size:
                if col_iter.size == 0:
                    return False
                min_size = col_iter.size
                ptr = col_iter
            col_iter = col_iter.right

        self.cover(ptr)
        row_iter = ptr.down
        while row_iter != ptr:
            solution.append(row_iter.row)
            col_iter = row_iter.right
            while col_iter != row_iter:
                self.cover(col_iter.col)
                col_iter = col_iter.right
            if self.search(head, solution):
                return True
            solution.pop()
            col_iter = row_iter.left
            while col_iter != row_iter:
                self.uncover(col_iter.col)
                col_iter = col_iter.left
            row_iter = row_iter.down
        self.uncover(ptr)
        return False

    def solve(self, matrix : list):
        n = len(matrix[0])
        column = [Node() for _ in range(n)]
        head = Node()
        head.right = column[0]
        head.left = column[n-1]
        for i in range(n):
            column[i].size = 0
            column[i].up = column[i]
            column[i].down = column[i]
            if i == 0:
                column[i].left = head
            else:
                column[i].left = column[i-1]
            if i == n-1:
                column[i].right = head
            else:
                column[i].right = column[i+1]

        nodes = []
        for i in range(len(matrix)):
            last = None
            for j in range(n):
                if matrix[i][j]:
                    node = Node()
                    node.row = i
                    node.col = column[j]
                    node.up = column[j].up
                    node.down = column[j]
                    
                    if last == None:
                        node.left = node
                        node.right = node
                    else:
                        node.left = last
                        node.right = last.right
                        last.right.left = node
                        last.right = node
                    last = node
                    column[j].up.down = node
                    column[j].up = node
                    column[j].size += 1
                    
                    nodes.append(node)

        solution = []
        self.search(head, solution)
        return solution

matrix = []
data = []
input_line = [[0]*3 for _ in range(82)]
chk = [[0]*9 for _ in range(9)]
ans = 0
def make_row(i, j, k : int):
    row = [0 for _ in range(324)]
    row[i*9+j] = 1
    row[81+i*9+k] = 1
    row[162+j*9+k] = 1
    row[243+(i//3*3+j//3)*9+k] = 1
    
    matrix.append(row)
    data.append((i, j, k))
    
for i in range(1, 82):
    input_line[i] = list(map(int, input().split()))
    if not chk[input_line[i][0]-1][input_line[i][1]-1]:
        make_row(input_line[i][0]-1, input_line[i][1]-1, input_line[i][2]-1)
        chk[input_line[i][0]-1][input_line[i][1]-1] = 1
    else:
        ans = i
        for j in range(9):
            for k in range(9):
                if chk[j][k]:
                    continue
                for num in range(9):
                    make_row(j, k, num)
        if dlx().solve(matrix):
            print(i)
            exit()

        for j in range(i-1, 0, -1):
            for num in range(9):
                if input_line[j][2] - 1 == num:
                    continue
                make_row(input_line[j][0]-1, input_line[j][1]-1, num)

            if dlx().solve(matrix):
                print(j)
                exit()
        
        

dlx = dlx()
if dlx.solve(matrix):
    print(-1)
    exit()

for i in range(81, 0, -1):

    for num in range(9):
        if input_line[i][2] - 1 == num:
            continue
        make_row(input_line[i][0]-1, input_line[i][1]-1, num)

    solution = dlx.solve(matrix)

    if solution:
        print(i)
        exit()