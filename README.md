# wordle_Lakshana

This is a simple implementation of the Wordle game in C. The game allows players to guess 5-letter words randomly selected from a list until they guess correctly or exhaust their trials.

## How to Compile and Run

1. Navigate to the project directory in the terminal.
2. Compile the C program using the gcc command. For example, if the C file is named wordle.c, you would type gcc wordle.c -o wordle.
3. Run the resulting executable. For example, type ./wordle.

## Game Rules

- If you guess a letter correctly and it's in the correct spot, the letter will be marked as green.
- If you guess a letter correctly but it's in the wrong spot, the letter will be marked as yellow.
- If the letter isn't in the word at all, it will be marked as gray.
- You have 6 attempts to guess the word. Good luck!
