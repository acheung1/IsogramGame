#pragma once
#include "isogram.h"

// for Unreal Engine syntax
using FString = std::string;
using int32 = int;

IsogramGame::IsogramGame() {
	// change these two values as you like
	constexpr int32 MAX_TRIES = 3;
	const FString HIDDEN_WORD = "dank"; // MUST BE AN ISOGRAM (NO REPEATING LETTERS WORD)

	myMaxTurns = MAX_TRIES;
	hiddenWord = HIDDEN_WORD;
	hiddenWordLength = HIDDEN_WORD.length();
	gameWon = false;

	reset();
}

// when player wants to try again
void IsogramGame::reset() {
	myCurrentTurn = 1;
}

// checks if argument is valid input
bool IsogramGame::validGuess(FString guess) {
	bool valid = false;

	if (guess.length() == hiddenWordLength) {
		// alphabetical and no repeating letters
		if (alpha(guess) && isIsogram(guess)) {
			valid = true;
		}
	}
	else {
		std::cout << "Not valid b/c of incorrect word length. Try again." << std::endl;
	}

	return valid;
}

bool IsogramGame::alpha(FString guess) {
	for (char letter : guess) {
		if (!isalpha(letter)) {
			std::cout << "Not valid b/c there are non alphabetical characters. Try again." << std::endl;
			return false;
		}
	}
	return true;
}

bool IsogramGame::isIsogram(FString guess) {
	TMap <char, bool> seen;
	
	for (char letter : guess) {
		// default value for bool is false
		if (seen[letter]) {
			std::cout << "Not valid b/c the word is not an isogram. Try again." << std::endl;
			return false;
		}
		else {
			// false if the key has not been seen yet
			seen[letter] = true;
		}
	}
	return true;
}

// checks player progress and update the member variables in letterCount
// also checks if player won
LetterCount IsogramGame::submitGuess(FString guess) {
	struct LetterCount letterCount;
	
	// checks how many correct letters and how many correct letters in the correct places
	for (int32 i = 0; i < guess.length(); i++) {
		for (int32 j = 0; j < hiddenWordLength; j++) {
			if (guess[i] == hiddenWord[j]) {
				letterCount.countLetters++;
				if (i == j) {
					letterCount.countPlaces++;
				}
			}
		}
	}
	// player win if all three variables have the same values
	gameWon = ((letterCount.countLetters + letterCount.countPlaces + hiddenWordLength) / 3 == hiddenWordLength);
	return letterCount;
}


int32 IsogramGame::getCurrentTurn() const
{
	return myCurrentTurn;
}

int32 IsogramGame::getMaxTurns() const	
{
	return myMaxTurns;
}

int32 IsogramGame::getHiddenWordLength() const
{
	return hiddenWordLength;
}

bool IsogramGame::getGameWon() const
{
	return gameWon;
}

void IsogramGame::setCurrentTurn()
{
	myCurrentTurn++;
}
