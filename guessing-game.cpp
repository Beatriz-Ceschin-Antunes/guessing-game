// Author: Beatriz Antunes
// May 17th, 2024
// Purpose: Program that plays a guessing game. A random number between 50 and 150 is generated and either the user or the computer will take guesses each time. Hints of whether number is too high or too low are given at every round.

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// range of numbers for game
const int HIGH = 150;
const int LOW = 50;

// function prototypes
int generateRandomNumber();
void userPlay();
void computerPlay();

int main() {

  cout << "Hi there! Glad to have you here, let's play!\n";

  char playerChoice;

  // player chooses who will start playing
  cout << "Would you like to (p)lay or have the (c)omputer play?"
          "\n(Enter p or c): ";
  cin >> playerChoice;

  do {

    // validates user input
    while (!(tolower(playerChoice) == 'p' || tolower(playerChoice) == 'c')) {
      cout << "Invalid input, please try again.\n(Enter p or c):";
      cin >> playerChoice;
    };

    // displays message according to user's choice of who'll play
    if (tolower(playerChoice) == 'p') {
      cout << "You have chosen to play.\n\n";
      userPlay(); // calls function that allows user to play
    } else if (tolower(playerChoice) == 'c') {
      cout << "You have chosen to let the computer play.\n\n";
      computerPlay(); // calls function that allows computer to play
    }

    // asks user if they want to play again
    cout << "\nWould you like to (p)lay or watch the (c)omputer play or "
            "(q)uit?\n";
    cin >> playerChoice;

  } while (tolower(playerChoice) == 'p' || tolower(playerChoice) == 'c');

  // if user chose to quit
  cout << "Thanks for playing! Exiting game...";

  return 0;
}

// generates random number
int generateRandomNumber() {
  srand(unsigned(time(NULL))); // seeds random numb generator

  int randomNum = rand() % (HIGH - LOW + 1) +
                  LOW; // generates random number between 50 and 150

  return randomNum;
}

// function used when user is playing (guessing random number)
void userPlay() {

  int guess;

  // computer selects a random number that needs to be guessed
  int randomNum = generateRandomNumber();

  do {
    cout << "Please enter your guess between 50 and 150: ";
    cin >> guess;

    if (guess > randomNum) {
      cout << "Sorry, your guess is too high, try again.\n\n";
    } else if (guess < randomNum) {
      cout << "Sorry, your guess is too low, try again.\n\n";
    }
  } while (guess != randomNum);

  // guessed correctly
  cout << "Congratulations, you guessed the correct number, " << randomNum
       << "!\n";
}

// function used when computer is playing (guessing random number)
void computerPlay() {

  int guess;
  int lowerBound = LOW;  // 50
  int upperBound = HIGH; // 150

  // computer selects a random number that needs to be guessed
  int randomNum = generateRandomNumber();

  // uses binary search to take a guess
  do {
    int midPoint = lowerBound + (upperBound - lowerBound) / 2;
    guess = midPoint; // first guess is the midpoint

    cout << "The computer's guess is " << guess << ".\n";

    if (guess > randomNum) {
      cout << "The computer's guess is too high. Trying again...\n\n";
      upperBound = midPoint - 1;

    } else if (guess < randomNum) {
      cout << "The computer's guess is too low. Trying again...\n\n";
      lowerBound = midPoint + 1;
    }
  } while (guess != randomNum);

  // guessed correctly
  cout << "The computer guessed the correct number, " << randomNum << "!\n";
}

/*
*********SAMPLE OUTPUT*******

Hi there! Glad to have you here, let's play!
Would you like to (p)lay or have the (c)omputer play?
(Enter p or c): t
Invalid input, please try again.
(Enter p or c):p
You have chosen to play.

Please enter your guess between 50 and 150: 100
Sorry, your guess is too high, try again.

Please enter your guess between 50 and 150: 50
Sorry, your guess is too low, try again.

Please enter your guess between 50 and 150: 75
Sorry, your guess is too low, try again.

Please enter your guess between 50 and 150: 80
Sorry, your guess is too low, try again.

Please enter your guess between 50 and 150: 90
Sorry, your guess is too high, try again.

Please enter your guess between 50 and 150: 85
Sorry, your guess is too low, try again.

Please enter your guess between 50 and 150: 87
Sorry, your guess is too low, try again.

Please enter your guess between 50 and 150: 88
Sorry, your guess is too low, try again.

Please enter your guess between 50 and 150: 89
Congratulations, you guessed the correct number, 89!

Would you like to (p)lay or watch the (c)omputer play or (q)uit?
c
You have chosen to let the computer play.

The computer's guess is 100.
The computer's guess is too high. Trying again...

The computer's guess is 74.
The computer's guess is too low. Trying again...

The computer's guess is 87.
The computer's guess is too high. Trying again...

The computer's guess is 80.
The computer's guess is too low. Trying again...

The computer's guess is 83.
The computer's guess is too high. Trying again...

The computer's guess is 81.
The computer guessed the correct number, 81!

Would you like to (p)lay or watch the (c)omputer play or (q)uit?
q
Thanks for playing! Exiting game...

*/
