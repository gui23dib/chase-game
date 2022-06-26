import os
from turtle import clear
def cls(): os.system("cls")

def showtable():
    cls()
    for i in range(5):
        for j in range(11):
            print(grid[i][j], end="")
        print()
    statcheck()

def tablecolision(p, max, newp):
    if(current_position[p] == max):
            current_position[p] = newp
    return current_position

def playermoveinput(p_move):
    clear_position = current_position
    if(p_move == 'W' or p_move == 'w'):
        current_position[0] -= 1
        tablecolision(0, -1, 4)
    elif(p_move == 'A' or p_move == 'a'):
        current_position[1] -= 1
        tablecolision(1, -1, 10)
    elif(p_move == 'S' or p_move == 's'):
        current_position[0] += 1
        tablecolision(0, 5, 0)
    elif(p_move == 'D' or p_move == 'd'):
        current_position[1] += 1
        tablecolision(1, 11, 0)
    return current_position, clear_position

def playermovement(current_position):
    grid[current_position[0]][current_position[1]] = '-'
    grid[y][x] = '0'
    return grid,  current_position

def tableupdate(k):
    grid[current_position[0]][current_position[1]] = '-'
    playermoveinput(k)
    grid[current_position[0]][current_position[1]] = '0'
    showtable()
    return grid

def statcheck():
    print(current_position[0], current_position[1])

global grid 
grid = [
    ['-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'], 
    ['-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'], 
    ['-', '-', '-', '-', '-', '0', '-', '-', '-', '-', '-'],
    ['-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-'],
    ['-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-']
]
global current_position
current_position = [2, 5]
# CURRENT_POSITION[0] === Y
# CURRENT_POSITION[1] === X

while True:
    showtable()
    player_key = input("--> ")
    tableupdate(player_key)
