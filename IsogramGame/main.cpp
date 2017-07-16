#pragma once
#include <iostream>
#include <string>
#include "isogram.h"

// for Unreal Engine Syntax
using FText = std::string;
using int32 = int;

// prototypes 
void printIntro();
FText getGuess();
void playGame();
bool tryAgain();

// Creates a new game
IsogramGame game;

int main() {
	bool repeatGame = false;

	printIntro();
	do {
		game.reset();
		playGame();

		if (game.getGameWon()) {
			repeatGame = false;
		}
		else {
			repeatGame = tryAgain();
		}
	} while (repeatGame);
	return 0;
}

// prints introduction to isogram game
void printIntro() {
	std::cout << "Welcome to the Isogram Guessing Game!" << std::endl;
	std::cout << "Guess the right word within a set amount of turns." << std::endl;
	std::cout << "You have " << game.getMaxTurns() << " turns to figure out the ";
	std::cout << game.getHiddenWordLength() << " letter(s) isogram.\n" << std::endl;
}

FText getGuess() {
	FText guess;
	bool valid = false;

	// Get a valid guess from player
	while (!valid) {
		std::cout << "Enter you Guess: ";
		std::getline(std::cin, guess);
		valid = game.validGuess(guess);
	}
	return guess;
}

void playGame() {
	FText guess;
	bool winGame = false;
	struct LetterCount letterCount;

	// loop till max tries or isogram is founded
	while (game.getCurrentTurn() <= game.getMaxTurns() && !(game.getGameWon())) {
		std::cout << "Turn " << game.getCurrentTurn() << "\n" << std::endl;
		// checks for valid input
		guess = getGuess();
		// process player progress on the game
		letterCount = game.submitGuess(guess);
		
		if (game.getGameWon()) {
			std::cout << "CORRECT. YOU WIN." << std::endl;
		}
		else {
			std::cout << "Incorrect." << std::endl;
			std::cout << "Number of letters correct: " << letterCount.countLetters << std::endl;
			std::cout << "Number of letters in correct positions: " << letterCount.countPlaces << std::endl << std::endl;
			game.setCurrentTurn();
		}
	}
}

// is called when player failed to guess the isogram
bool tryAgain() {
	FText respond;

	std::cout << "Do you want play again? Press Y to continue, any other key to quit game: ";
	std::getline(std::cin, respond);

	bool anotherOne = respond[0] == 'Y' || respond[0] == 'y';
	return anotherOne;
}