#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std; 

int limited_attempts = 6;
int score = 0;
vector <char> display;
string correctWord;
void printVector (vector<char>v);
void initializeDisplay();
char enterLetter();
int updateDisplayVector(char c);

int main() {
    
    vector<string> wordsList;
    wordsList.push_back("strawberry");
    wordsList.push_back("lime");
    wordsList.push_back("orange");
    wordsList.push_back("lemon");
    wordsList.push_back("mango");

    srand (time(0));
    correctWord = wordsList.at(rand()%5);
    cout << correctWord << endl;
    cout << "Guessing the word: " << correctWord << endl;
    cout << " ------------------------------ " << endl;
    cout <<  "  Welcome to Hangman Game !!! "  << endl;
    cout << " ------------------------------ " << endl;

    initializeDisplay();
    printVector(display);

    while (score<display.size() && limited_attempts > 0){
    updateDisplayVector(enterLetter());
    }
    if (limited_attempts <0 ){
        cout << "Sorry ~ You Lost! The word was : " << correctWord << endl;
        cout << endl;
    }
    else {
        cout << " Congrats ~ You won !!!" << endl;
    }
        cout << endl; 
    return 0;
}

void initializeDisplay() {
    for (int i= 0; i< correctWord.size(); i++){
        display.push_back ('*'); 
        
    }
}

void printVector(vector<char>v){
    for (int i = 0; i < v.size();i++){
        cout << v.at(i);
    }
    cout << endl;
}

char enterLetter(){
    char letter;
    cout << "Guess the Letter:" ;
    cin >> letter;
    int val = (int)letter;
    if ((val>=65 && val<=90) ||(val >= 97 && val <=122)){
        return letter;
    }
    else {
        enterLetter();
    }

    return letter;
 }

 int updateDisplayVector(char c){
     bool contain = false;
     for (int i =0 ; i< correctWord.size(); i++ ){
          if (c == correctWord.at(i)){
              display.at (i) = c;
              contain = true;
              score = score + 1;
          }
          
     }
        printVector(display);
       cout << "Score: " << score << endl;

        if (contain == false){
            limited_attempts = limited_attempts - 1;
            cout << "Attempt Left: " << limited_attempts << endl;
        }
        cout << endl;
     return 0;
 }


    
    