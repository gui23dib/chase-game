import os
def cls(): os.system("cls")

def gamestart():
    global grid 
    grid = [
        ['-', '-', '-'], 
        ['-', '0', '-'], 
        ['-', '-', '-']
    ]
    global current_position
    current_position = [1, 1]
    showtable(grid)

    return grid, current_position

def showtable(grid):
    ##cls()
    for i in range(3):
        for j in range(3):
            print(grid[i][j], end="")
        print()

def playermoveinput(playerinput, y, x):
    if(p_move == 'W'):
        y = current_position[0]-1
        x = current_position[1]
        playermovement(y, x, current_position)
    elif(p_move == 'A'):
        y = current_position[0]
        x = current_position[1]-1
        playermovement(y, x, current_position)
    elif(p_move == 'S'):
        y = current_position[0]+1
        x = current_position[1]
        playermovement(y, x, current_position)
    elif(p_move == 'D'):
        y = current_position[0]
        x = current_position[1]+1
        playermovement(y, x, current_position)

def playermovement(y, x, current_position):
    grid[current_position[y]][current_position[x]] = '-'
    grid[y][x] = '0'
    return grid,  current_position, x, y


gamestart()

x = 1
y = 1

while True:
    p_move = input()
    playermoveinput(p_move, x, y)
    current_position = [y, x]

    showtable(grid) 