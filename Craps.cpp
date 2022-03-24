/* Timothy Queva
   CS2010 Lab3
   September 28, 2020
*/

/*This program plays the gambling game Craps and is for the purposes of a lab. Don't gamble. Statistically speaking, the odds
do not favour you EVER!

Gameplay: Two dice are thrown and totals added. 7 or 11 wins. 2,3,12 loses. Any other is your goal to roll (point).
Subsequent throw(s)-however many-either make this to win or make a 7 in which case you lose. Wins give you the wagered amount on top of
original balance (eg. Original balance: 100. Wagered: 23. New balance after win: 123). Losses make you lose the wagered amount. Gameplay
ends when credit balance reaches 0 or when player decides to end game.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

//Random number generator
int die(){
	return rand()%6+1;
}

int main(){
	char uchoice;
	bool repeatGame=false;
	bool rollagain=false;;
	int creds=100;
	int wager;
	int die1=1;
	int die2=1;
	int result=2;
	int point=0;
	
	srand(time(0));		//Changes default seed to random value.
	
	cout << "This is the gambling game of Craps" << endl << endl;
	
	do{
		//User prompt for wager. Rejects incorrect number inputs
		do{
			cout << "You have " << creds << " credits. How much do you wager? : ";
			cin >> wager;
			
			if(wager>creds) cout << "  ---You don't have that amount!" << endl << endl;
			if(wager <=0) cout << "  ---You can't bet zero or a negative amount!" << endl << endl;
		} while(wager>creds || wager <=0);
		
		//Random number generator
		die1 = ::die();
		die2 = ::die();
		result = die1 + die2;
		
		//Deals with initial win/lose gameplay (7/11 win. 2,3,12 loss)
		if(result == 7 || result == 11){
			cout << "Player rolled " << die1 << " + " << die2 << " = " << result << endl;
			creds += wager;
			cout << "Player won. Credit balance is now " << creds << endl;
		}
		else if(result == 2 || result == 3 || result == 12){
			cout << "Player rolled " << die1 << " + " << die2 << " = " << result << endl;
			creds -= wager;
			cout << "Player lost. Credit balance is now " << creds << endl;
		}
		else{
			point = result;
			cout << "Point is " << point << endl;
			//cout << "Press ENTER to continue...";
			//cin.get();
			rollagain=true;
		}
		
		//Deals with "point" aspect of gameplay
		while(rollagain){
			die1 = rand()%6+1;
			die2 = rand()%6+1;
			result = die1+die2;
			
			cout << "Player rolled " << die1 << " + " << die2 << " = " << result << endl;
			
			//Displays winnings/losts
			if(result == point){
				creds += wager;
				cout << "Player won. Credit balance is now " << creds << endl;
				rollagain = false;
			}
			else if(result == 7){
				creds -= wager;
				cout << "Player lost. Credit balance is now " << creds << endl;
				rollagain = false;
			}
			else{
				//cout << "Press ENTER to rollagain" << endl;
				//cin;
			}
		}
		rollagain = false;	//resets loop condition
		
		//Ends gameplay immediately if credits=0
		if (creds<=0){
			cout << "Sorry, you've run out of credits to play." << endl;
			break;
		}
		
		//User prompts to continue/discontinue playing game
		cout << "Would you like to try again (Y/n)?:";
		cin >> uchoice;
		cout << endl;
		
		//Converts char answer to lowercase
		uchoice = putchar(tolower(uchoice));
		
		//Terminates loop according to user choice
		if(uchoice == 'y') repeatGame = true;
		else{
			cout << "Ending balance: " << creds << " credits." << endl;
			repeatGame = false;
		}
		
	}while(repeatGame);
}