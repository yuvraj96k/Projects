# importing random python library
import random

# user-defined function for play the game
def play():
    # taking input from the user
    user = input("What is your choice ? ('r' for rock, 'p' for paper, 's' for scissors): ")
    # computer choice by using random library
    computer = random.choice(['r', 'p', 's'])

    # tie condition
    if user == computer:
        return 'It is a tie.'

    # player win condition
    if is_win(user, computer):
        return 'You Won!'

    # last condition for loss of player
    return 'You Lost!'

# user-defined function for decide winner
def is_win(player, opponent):
    if (player == 'r' and opponent == 's') or (player == 's' and opponent == 'p') or (player == 'p' and opponent == 'r'):
        return True

# running full program
print(play())