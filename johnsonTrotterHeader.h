#ifndef JOHNSONTROTTERHEADER_H
#define JOHNSONTROTTERHEADER_H

#include <string>
#include <cstring>

using namespace std;

void printPermutations(string , int );

int mobileElementFinder(string word, char wordArray[], int directionArray[]); 

void swapValues(int mobilePosition, int directionArray[], char wordArray[]); 

void changeDirection(char currentMobileElementValue, string word, char wordArray[], int directionArray[]); 

void printPermutationRow(string word, char wordArray[]); 


#endif

