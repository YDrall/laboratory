import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

first_init_input = int(input())
second_init_input = int(input())
third_init_input = int(input())

board = {}
# game loop
while True:
    first_input = input()
    second_input = input()
    third_input = input()
    fourth_input = input()
    player = []
    for i in range(third_init_input):
        fifth_input, sixth_input = [int(j) for j in input().split()]
        player.append([fifth_input,sixth_input])

    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr)

    print(first_init_input,second_init_input,third_init_input,file=sys.stderr)
    print(first_input,second_input,third_input,fourth_input,file=sys.stderr)
    print(player,file=sys.stderr)
    
    if second_input == "_" and fifth_input < first_init_input:
        print('A')
    elif third_input == "_" and sixth_input < second_init_input:
        print('C')
    elif fourth_input == "_" and fifth_input >1:
        print('E')
    elif first_init_input == "_" and sixth_input > 1:
        print('D')
    else:
        print('B')