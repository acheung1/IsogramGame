#pragma once
#include <string>
#include <iostream>
#include <map>
#define TMap std::map

// For Unreal Engine syntax
using FString = std::string;
using int32 = int;

struct LetterCount {
	// # correct letters and # correct lettters and correct places
	int32 countLetters = 0;
	int32 countPlaces = 0;
};

enum EResetStatus {
	YES,
	NO
};

class IsogramGame {
public:
	IsogramGame();
	// const to prevent methods changing instance variables
	int32 getMaxTurns() const;
	int32 getCurrentTurn() const; 
	int32 getHiddenWordLength() const;
	bool getGameWon() const;
	void setCurrentTurn();

	void reset();
	bool validGuess(FString);
	bool alpha(FString);
	bool isIsogram(FString);
	LetterCount submitGuess(FString);

private:
	int32 myCurrentTurn;
	int32 myMaxTurns;
	int32 hiddenWordLength;
	FString hiddenWord;
	bool gameWon;
};