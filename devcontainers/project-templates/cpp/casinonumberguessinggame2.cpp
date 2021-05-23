#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
void rules();
int main()
{
    string playerName;
    int balance; // stores player's balance
    int bettingAmount;
    int guess1; // first guessed number
    int guess2; // second guessed number
    int dice; // stores the first random number 
    char choice;
    srand(time(0)); // "Seed" the random generator
    cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
    cout << "\n\nWhat's your Name : ";
    getline(cin, playerName);
    cout << "\n\nEnter the starting balance to play game : $";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $ " << balance << "\n";
// Get player's betting balance
        do
        {
            cout << "Hey, " << playerName<<", enter amount to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > balance)
                cout << "Betting balance can't be more than current balance!\n"
                       <<"\nRe-enter balance\n ";
        }while(bettingAmount > balance);
// Get player's numbers
        do
        {
            cout << "Guess any betting number between 1 & 15 :";
            cin >> guess1;
            if(guess1 <= 0 || guess1 > 15)
                cout << "\nNumber should be between 1 and 15\n"
                    <<"Re-enter number:\n ";
        }while(guess1 <= 0 || guess1 > 15);
        
        do
        {
        cout << "Guess any other betting number between 1 & 15 :";
            cin >> guess2;
            if(guess2 <= 0 || guess2 > 15 || guess1 == guess2)
                cout << "\nNumber should be between 1 and 15 and should not be identical to the first guess.\n"
                    <<"Re-enter number:\n ";    
        }while((guess2 <=0 || guess2 > 15) || (guess1 == guess2));

        dice = rand()%15 + 1;
        
        if(dice == guess1 || dice == guess2)
        {
            cout << "\n\nYou are in luck!! You have won Rs." << bettingAmount * 10 <<"\n";
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost $ "<< bettingAmount <<"\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have balance of $ " << balance << "\n";
        if(balance == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    cout << "\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
    return 0;
}
void rules()
{
    system("cls");
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose 2 numbers between 1 to 15\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}