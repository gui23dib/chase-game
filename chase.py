import random
import os
from turtle import clear
def cls(): os.system("cls")

def showtable(turn):
    cls()
    if(turn == 1):
        print("WELCOME!!!")
        print("PRESS W/A/S/D TO START...")
    for i in range(5):
        for j in range(11):
            print(grid[i][j], end="")
        print()
    starcheck(star_position)

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

def tableupdate(k):
    grid[star_position[0]][star_position[1]] = '*'
    grid[current_position[0]][current_position[1]] = '-'
    playermoveinput(k)
    grid[current_position[0]][current_position[1]] = '0'
    showtable(0)
    return grid

def starcheck(star_position):
    if(current_position[0] == star_position[0] and current_position[1] == star_position[1]):
        print("VOCE CAPTUROU A ESTRELA! PARABENS!")

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
global star_position
star_position = [random.randint(0, 4),random.randint(0, 10)]
game_start_parameter = 1 # 1 for first turn and game star

while True:
    showtable(game_start_parameter)
    player_key = input("--> ")
    tableupdate(player_key)
    game_start_parameter = 0