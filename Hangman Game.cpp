//Libs
#include <iostream>
#include <fstream>
//Classes markers
using namespace std;
string GotoLine(fstream& file, int numb);
string ToLower(string word);
//Data
string path;string word;
//Primary Classes
int main(){
    init: //Languages
    int numb; string word, hint = "Na"; char choice, clear[5];
    cout << "Are you playing in a Linux(1) or Windows(2)?";
    cin >> choice; //To define the clear code
    if (choice != '1' & choice != '2') {
        cout << "Please type a valid option!\n"; goto init; //If the user type some wrong numb
    } else if (choice == '1') {
        clear[0] = 'c'; clear[1] = 'l'; clear[2] = 'e'; clear [3] = 'a'; clear[4] = 'r'; //Linux command
    } else {
        clear[0] = 'c'; clear [1] = 'l', clear [2] = 's'; //Windows Command
    } system(clear);
    init1:
    try {
    cout << "Choice your language: English(1) Portuguese(2): ", cin >> numb; numb--; //Choice the lang2
    } catch (exception& e){
        cout << "Please write a number!\r\n"; goto init1; //If the user type some letter
    }
    if (numb != 0 && numb != 1) {
        cout << "Please write a valid number!\r\n"; goto init1; //If the user type a wrong number
    } else if (numb == 0) {
        path = "lang/Eng.txt"; //Define path to right lang
    } else {
        path = "lang/Pt-Br.txt"; ////Define path to right lang
    } system(clear); //Clear
    fstream file;
    hintMarker: //Do you want a hint?
    cout << GotoLine(file, 1), cin >> word; word = ToLower(word); system(clear); //Cçear
    cout << GotoLine(file, 2), cin >> choice;
    if (choice != 'y' & choice != 's' & choice != 'n') {
        cout << GotoLine(file, 3); goto hintMarker; //Choice about the hint
    } else if (choice == 'y' | choice == 's'){
        cout << GotoLine(file, 4); cin >> hint; 
    } system(clear); //Clear
    int score = 10; string answer[word.length()];
    for (int i =0; i < word.length(); i++) { //Define the "answer" = null
        answer[i] = "_ ";
    }
    game:
    cout << GotoLine(file, 5) << score << "\n";
    for (int i = 0; i < word.length(); i++) { //Render the answer
        cout << answer[i];
    }
    cout << "\n\n" <<GotoLine(file, 6), cin >> choice; bool boolean = false; system(clear); //Choice the letter (or show hint) & Clear 
    if (choice == '0') {
        if (score <= 5) {
            cout << GotoLine(file, 4) << hint << "\n"; goto game; //show hint
        } else {
            cout << GotoLine(file, 11) << "\n"; goto game;
        }
    }
    for (int i =0; i < word.length(); i++) {
        if (choice == word[i]) {
            answer[i] = "";answer[i].push_back(choice);answer[i] = answer[i] + " "; boolean = true; //Check if the word have the choice
        }
    }
    if (boolean == false) {
        score--; cout << GotoLine(file, 7); //Show the mensage if the player don't do the right choice :(
    }
    if (score == 0) {
        cout << GotoLine(file, 8) << word << "\n"; goto playAgain;//"You lose!"
    }
    for (int i =0; i< word.length(); i++) {
        if (answer[i] == "_ ") {
            goto game;
        }
    }
    cout << GotoLine(file, 9);
    playAgain:
    cout << GotoLine(file, 10), cin >> choice; towlower(choice);
    if (choice != 's' & choice != 'y' & choice != 'n') {
        cout << GotoLine(file, 3); goto playAgain;
    } else if (choice == 's' | choice == 'y') {
        goto hintMarker;
    }
    cout << GotoLine(file, 12) << "\n";
    return 0;
}

string GotoLine(fstream& file, int numb) {
    init:
    if (file.is_open() == true) {
        string line;
        for (int i = 0; i < numb; i++) {
            getline(file, line);
        }
        file.close();
        return line;
    } else {
        file.open(path, ios::in); goto init;
    }
}

string ToLower(string word) {
    char upper[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower[27] = "abcdefghijklmnopqrstuvwxyz"; string str = ""; 
    bool boolean = true;
    for (int i = 0 ; i < word.length(); i++) {
        for (int ii= 0; ii < 28 ; ii++) {
            if (word[i] == upper[ii]) {
                str = str + lower[ii]; boolean = false;
                goto init;
            }
            else if (ii == 27 & boolean == true) {
                str = str + word[i];
            }
        }
        init: boolean = true;
    }
    return str;
}