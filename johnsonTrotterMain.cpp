#include "csce310homework01part02.h"
#include <string>
#include <cstring>
#include <array>
#include <iostream>

using namespace std;

void printPermutations(string word, int permutations ) {

  // Input: word can be any string of characters, presorted in lexiographic order; 
  // permutations is an integer number of permutations that you would like to compute

  int wordLength = word.length(); 
  char wordArray[wordLength-1]; 
  int directionArray[wordLength-1]; // 0: Left, 1: Right
  int mobilePosition; 
  char currentMobileElementValue; 

  strcpy(wordArray, word.c_str()); 

  for(int i = 0; i < wordLength; i++) {
    directionArray[i] = 0; 
  }

  for(int k = 0; k < permutations; k++) {
    printPermutationRow(word, wordArray); 
    mobilePosition = mobileElementFinder(word, wordArray, directionArray); 
    if(mobilePosition != -1) {
      NULL; 
    } else {
      break; 
    }
    currentMobileElementValue = wordArray[mobilePosition];  
    swapValues(mobilePosition, directionArray, wordArray); 
    changeDirection(currentMobileElementValue, word, wordArray, directionArray);
  }
  
}

void changeDirection(char currentMobileElementValue, string word, char wordArray[], int directionArray[]) {
  for(int i = 0; i < word.length(); i++) {
    if(wordArray[i] > currentMobileElementValue) {
      if(directionArray[i] == 0) {
        directionArray[i] = 1; 
      } else if (directionArray[i] == 1) {
        directionArray[i] = 0; 
      }
    }
  }
}

int mobileElementFinder(string word, char wordArray[], int directionArray[]) {

  int mobilePosition = -1; // Establishing base value

  for(int i = 0; i < word.length() - 1; i++) {
    for(int j = i+1; j < word.length(); j++) { 

      if(wordArray[i] > wordArray[j]) {
        if((i == 0 && directionArray[i] == 0) || (i == (word.length()-1) && directionArray[i] == 1)) {
          continue; 
        }
        
        // If i is facing left: 
        if(directionArray[i] == 0) {
          if(i != 0 && (wordArray[i] > wordArray[i-1])) {
            if(mobilePosition == -1 || wordArray[mobilePosition] < wordArray[i]) { // If the previous mobile element is the default value, or a smaller element, then change
              mobilePosition = i; 
            }
          }
        }

        // If i is facing right: 
        else if(directionArray[i] == 1) {
          if(i != (word.length()- 1) && (wordArray[i] > wordArray[i+1])) {
            if(mobilePosition == -1 || wordArray[mobilePosition] < wordArray[i]) {
              mobilePosition = i; 
            }
          }
        }
      }

      else {
        if((j == 0 && directionArray[j] == 0) || (j == (word.length()-1) && directionArray[j] == 1)) {
          continue; 
        }
          
        // If j is facing left:
        if(directionArray[j] == 0) {
          if(j != 0 && (wordArray[j] > wordArray[j-1])) {
            if(mobilePosition == -1 || wordArray[mobilePosition] < wordArray[j]) {
                mobilePosition = j; 
              }
            }
          }
          
        // If j is facing right: 
        if(directionArray[j] == 1) {
          if(j != (word.length()-1) && (wordArray[j] > wordArray[j+1])) {
            if(mobilePosition == -1 || wordArray[mobilePosition] < wordArray[j]) {
              mobilePosition = j; 
            }
          }
        }
      }
    }
  }
  return mobilePosition; 
}

void swapValues(int mobilePosition, int directionArray[], char wordArray[]) {

  char tempCharacter; 
  char tempDirection; 

  if(directionArray[mobilePosition] == 0) {
    tempCharacter = wordArray[mobilePosition-1]; 
    tempDirection = directionArray[mobilePosition - 1]; 

    wordArray[mobilePosition-1] = wordArray[mobilePosition]; 
    directionArray[mobilePosition-1] = directionArray[mobilePosition]; 

    wordArray[mobilePosition] = tempCharacter; 
    directionArray[mobilePosition] = tempDirection;  
  }
  else if(directionArray[mobilePosition] == 1) {
    tempCharacter = wordArray[mobilePosition + 1]; 
    tempDirection = directionArray[mobilePosition + 1]; 

    wordArray[mobilePosition + 1] = wordArray[mobilePosition]; 
    directionArray[mobilePosition + 1] = directionArray[mobilePosition]; 

    wordArray[mobilePosition] = tempCharacter; 
    directionArray[mobilePosition] = tempDirection; 
  }
} 

void printPermutationRow(string word, char wordArray[]) {

  for(int i = 0; i < word.length(); i++) {
    cout << wordArray[i]; 
  }
  cout << endl; 
}

int main(int argc, char**argv) {
  printPermutations("StringGoesHere", 1); // Words must be tested that are already in lexiographic order
  return 0; 
}