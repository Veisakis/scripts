oneToNine = range(9)

def show_board(board):
    for i in oneToNine:

        if i % 3 == 0 and i != 0 :
            print('--- --- ---')

        for j in oneToNine:

            if j % 3 == 0 and j != 0:
                print('|', end='')

            if j == 8:
                print(board[i][j])
            
            else:
                print(str(board[i][j]) + '', end='')

def cell(r,c):
    
    cell = []

    if (r in range(0,3)) and (c in range(0,3)):
        for w in range(3):
            for z in range(3):
                cell.append(board[w][z])
        return cell

    if (r in range(0,3)) and (c in range(3,6)):
        for w in range(0,3):
            for z in range(3,6):
                cell.append(board[w][z])
        return cell

    if (r in range(0,3)) and (c in range(6,9)):
        for w in range(0,3):
            for z in range(6,9):
                cell.append(board[w][z])
        return cell

    if (r in range(3,6)) and (c in range(0,3)):
        for w in range(3,6):
            for z in range(0,3):
                cell.append(board[w][z])
        return cell

    if (r in range(3,6)) and (c in range(3,6)):
        for w in range(3,6):
            for z in range(3,6):
                cell.append(board[w][z])
        return cell

    if (r in range(3,6)) and (c in range(6,9)):
        for w in range(3,6):
            for z in range(6,9):
                cell.append(board[w][z])
        return cell

    if (r in range(6,9)) and (c in range(0,3)):
        for w in range(6,9):
            for z in range(0,3):
                cell.append(board[w][z])
        return cell

    if (r in range(6,9)) and (c in range(3,6)):
        for w in range(6,9):
            for z in range(3,6):
                cell.append(board[w][z])
        return cell

    if (r in range(6,9)) and (c in range(6,9)):
        for w in range(6,9):
            for z in range(6,9):
                cell.append(board[w][z])
        return cell
    
def solve():
    global board

    while any(0 in sublist for sublist in board):
        for x in oneToNine:
            for row in oneToNine:
                for col in oneToNine:

                    if board[row][col] == 0:
                        
                        if (x not in board[row]) and\
                            (x not in [sublist[col] for sublist in board]) and\
                            (x not in cell(row,col)):
                            board[row][col] = x
                            print()
                            print(show_board(board))

board = [
        [2,0,5,0,0,9,0,0,4],
        [0,0,0,0,0,0,3,0,7],
        [7,0,0,8,5,6,0,1,0],
        [4,5,0,7,0,0,0,0,0],
        [0,0,9,0,0,0,1,0,0],
        [0,0,0,0,0,2,0,8,5],
        [0,2,0,4,1,8,0,0,6],
        [6,0,8,0,0,0,0,0,0],
        [1,0,0,2,0,0,7,0,8]
        ]

show_board(board)
