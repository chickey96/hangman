//
//  main.cpp
//  Hangman
//
//  Created by Corinne Hickey on 3/22/17.
//  Copyright © 2017 corinne. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>


using namespace std;



bool startGame();
bool compare(string word, char guess);
string selectGame();
string selectWord();
void displayGame(string word);
void gameLost();
char guessLetter(string totalGuesses);
string displayWord(string word);
string updateWord(string word, string wordslots, char guess);
bool matchLetter(string word, char guess);
void print_hangman(int hit_count);
bool noDoubles(string allGuesses, char guess);
bool isValid(string totalGuesses, char guess);

#define numDeath 6

int main(int argc, const char * argv[]) {
    
    if (!startGame())
    {
        return 0;
    }
    
    bool keep_playing = false;
    do {
        string word = "";
        char guess = ' ';
    
       
        

        word = selectWord();
    
    
    
        // int wordLength = (int) word.length();
        string dynamicWord = displayWord(word);
        int hit_count = 0;
    
    
    
    
        string lettersUsed = "";
        string totalGuesses = "";
    
        do{
            if (hit_count == 0){
                displayGame(word);
            }
            cout << endl << "Display: " << dynamicWord << endl << "Letters used: " << lettersUsed <<endl;
        
            guess = guessLetter(totalGuesses);
            totalGuesses += guess;
    
            if (!matchLetter(word, guess)){
                lettersUsed += guess;
                hit_count++;
                cout << endl << "Incorrect" << endl;
            
            }
      
            else {
                cout << endl << "Correct!" << endl;
                dynamicWord = updateWord(word, dynamicWord, guess);
            
                }
            
            if (dynamicWord == word){
                cout << endl << "YOU WON!!!" << endl << "the word was: " << word << endl << "Play again soon" << endl;
                return 0;
            }
            
            print_hangman(hit_count);
            cout << "You have made " << hit_count << " mistake(s) so far" << endl << "You can make 6 errors before you DIE!" << endl;
            
        } while(hit_count != 6);
        
        
            gameLost();
            cout << "the word was: " << word << endl;
        
        
        if(startGame())
            keep_playing = true;
        else
            keep_playing = false;
        
    } while( keep_playing);
    
    return 0;
    }


bool startGame (){
    
    char play = ' ';
    
    do {
        cout << endl << "Welcome to HANGMAN!!!" << endl;
        cout << endl <<"Would you like to play? y/n? " << endl;
        cin >> play;
        
        if (play == 'n'){
            cout << endl << "Ok, come back soon! " << endl;
            return false;
        }
        if (play != 'y' && play != 'n'){
            cout << endl << "Invalid entry! y or n only. " << endl;
        }
    } while (play != 'y');
       
        return true;
}

string selectWord(){
    
    string word = "";
    int random = 0;
    
    string words[25] = {"enigma", "harrowing", "garnish", "answer", "notice", "orchid", "bashful", "lard", "ermine", "knowledge", "skyscraper", "indigenous", "weaving", "marijuana", "callous", "gluttony", "psychopath", "extremities", "asshole", "maladroitness", "supercilious", "lilac", "jest", "infamous", "achievement"};
    
    srand( (unsigned int)time(NULL));
    
    random = rand() % 24 + 0;
    word = words[random];
    
    return word;
    
}
void displayGame(string word){
    
    
    cout << "HANGMAN" << endl
    << " _____"  << endl
    << " |   |"  << endl
    << "     |"  << endl
    << "     |"  << endl
    << "     |"  << endl
    << "   __|__" << endl;
    
}

char guessLetter(string totalGuesses){
    char guess = ' ';
    
    do{
        cout << endl << "Guess a letter!" << endl;
        cin >> guess;
        guess = tolower(guess);
            
    }while (!isValid(totalGuesses, guess));
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    return guess;
}


bool matchLetter(string word, char guess)
{
    
    for(int i = 0; i < word.length(); i++)
        if( word[i] == guess)
        {
            return true;
        }
    
    
    return false;
    
}


string displayWord(string word){
    
    int size = (int) word.length();
    string wordSlots = "";
    for (int i = 0; i < size; i++ ){
        wordSlots += '_';
    }
    //cout << wordSlots << endl;
    return wordSlots;
}

string updateWord(string word, string wordSlots, char guess){
    
    
        int size = (int) word.length();
    string display = wordSlots;
    for (int i = 0; i < size; i++){
        if (word[i] == guess){
            display[i] = guess;
        }
    }
    
    return display;
}

bool isValid(string totalGuesses, char guess){
    if (!isalpha(guess)){
        cout << endl << "alphabetic characters only" << endl;
        return false;
    }
    string checkGuess;// = guess;
    if (checkGuess.length() > 1){
        cout << "guess may be only 1 letter" << endl;
    }
    if (!noDoubles(totalGuesses, guess)){
        cout << endl << "no repeated guesses" << endl;
        return false;
    }
    return true;
}

bool noDoubles(string allGuesses, char guess){
    int size = (int) allGuesses.length();
    for (int i = 0; i < size; i++){
        if (allGuesses[i] == guess){
            return false;
        }
    }return true;
}









///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///////// HANGMAN DRAWINGS
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////







void print_hangman(int death_count) {

    if(death_count == 1){
    cout <<endl << "HANGMAN" << endl
    << " _____"  << endl
    << " |   |"  << endl
    << " 0   |"  << endl
    << "     |"  << endl
    << "     |"  << endl
    << "   __|__" << endl;}
    
    if(death_count == 2)
    {
    cout << endl << "HANGMAN" << endl
    << " _____"  << endl
    << " |   |"  << endl
    << " 0   |"  << endl
    << " |   |"  << endl
    << "     |"  << endl
    << "   __|__" << endl;
    }

   if(death_count==3)
   {
    cout << endl << "HANGMAN" << endl
    << " _____"  << endl
    << " |   |"  << endl
    << " 0   |"  << endl
    << "-|   |"  << endl
    << "     |"  << endl
    << "   __|__" << endl;
   }


   if(death_count==4)
   {
    cout << endl << "HANGMAN" << endl
    << " _____"  << endl
    << " |   |"  << endl
    << " 0   |"  << endl
    << "-|-  |"  << endl
    << "     |"  << endl
    << "   __|__" << endl;
   }
    
    if(death_count==5)
    {
    cout << endl << "HANGMAN" << endl
    << " _____"  << endl
    << " |   |"  << endl
    << " 0   |"  << endl
    << "-|-  |"  << endl
    << " \\   |"  << endl
    << "   __|__" << endl;
    }
    
    
}


void gameLost(){
    cout << "HANGMAN" << endl;
    cout << "  _____" << endl;
    cout << "  |   |" << endl;
    cout << "  0   |" << endl;
    cout << " -|-  |" << endl;
    cout << "  /\\  |" << endl;
    cout << "    __|__" << endl;
    cout << "YOU ARE DEAD!!!" << endl;
    cout << "(LOSER)" << endl;
}







