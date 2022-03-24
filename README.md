Timothy Queva
CS2010 Lab3
September 28, 2020

Description: This program plays the gambling game Craps and is for the purposes of a lab. Don't gamble. Statistically speaking, the odds
do not favour you EVER!

Gameplay: Two dice are thrown and totals added. 7 or 11 wins. 2,3,12 loses. Any other is your goal to roll (point).
Subsequent throw(s)-however many-either make this to win or make a 7 in which case you lose. Wins give you the wagered amount on top of
original balance (eg. Original balance: 100. Wagered: 23. New balance after win: 123). Losses make you lose the wagered amount. Gameplay
ends when credit balance reaches 0 or when player decides to end game.

Limitation: This program cannot deal with incorrect inputs of letters instead of numbers.

Instructions: Navigate to the correct file folder.
	1. Compile and link by typing: make
	2. Run by typing: ./Craps
