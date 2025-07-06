#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>
#include <cstdlib>
#include<iomanip>
#include <fstream>

using namespace std;

#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void colour(char ch); // for colour in candy
void swap(char& x, char& y); // swap two values
char crushrand(int c);  // random candy    
const int height1 = 8;
void lshapeeasy(char array[][height1], int w, int x, int y);// for swap with function
void pattreneasy(char array[][height1], int w); // for make attren in easy mode
const int height2 = 10;
void lshapehard(char array[][height2], int w, int x, int y); // for swap in function
void pattrenhard(char array[][height2], int w); // for hard mode pattren

int main() {
    int  easy = 0, hard = 0;
    int game_easy[3] = { 0 }, game_hard[3] = { 0 };
    while (true) {
        char selection;
        cout << " -----------------------" << endl;
        cout << "|" << setw(24) << "|" << endl << "|" << "  1: START" << setw(14) << "|" << endl;
        cout << "|" << setw(24) << "|" << endl << "|" << "  2: SCORE" << setw(14) << "|" << endl;
        cout << "|" << setw(24) << "|" << endl << "|" << "  3: EXIT" << setw(15) << "|" << endl;
        cout << "|" << setw(24) << "|" << endl << "|" << "  4: INSTRUCTION" << setw(8) << "|" << endl;
        cout << "|" << setw(24) << "|" << endl << "|" << "  5: CREDIT" << setw(13) << "|" << endl;
        cout << "|" << setw(24) << "|" << endl << "|" << "  ENTER YOUR CHOICE " << setw(4) << "|" << endl;
        cout << " -----------------------" << endl;
        cin >> selection;
        system("cls");
        if (selection == '1') {
            int x = 0, y = 0;
            while (true) {
                cout << " ------------------------ " << endl;
                cout << "|                        |" << endl;
                cout << "|  1. Easy Mode          |" << endl;
                cout << "|                        |" << endl;
                cout << "|  2. Hard Mode          |" << endl;
                cout << "|                        |" << endl;
                cout << "|  3. Back to home       |" << endl;
                cout << "|                        |" << endl;
                cout << "|  Enter Your Choice     |" << endl;
                cout << "|                        |" << endl;
                cout << " ------------------------ " << endl;
                char choice;
                cin >> choice;
                system("cls");

                if (choice == '1') {
                    int timer = 60, score = 0;
                    const int w = 8, h = 8;
                    char array[w][h] = { ' ' };
                    srand(time(0));
                    for (int i = 0; i < h; i++) {
                        for (int j = 0; j < w; j++) {
                            array[i][j] = crushrand(rand() % 5 + 1); // use function to take random value and give expression to function
                        }
                    }
                    while (timer > 0) {
                        cout << "\tTimer :" << timer-- << "\t\tScore :" << score << endl;
                        pattreneasy(array, w);
                        cout << " Press any key to continue " << endl;
                        if (_kbhit()) { // press any key and enter in if and timer stop
                            while (true)
                            {
                                cout << "Which Element You want to swap?";
                                cout << "Input row:";
                                cin >> x;
                                cout << "Input column:";
                                cin >> y;
                                if (x >= 0 && x < 8 && y >= 0 && y < 8)
                                    break;
                                else
                                {
                                    cout << "Invalid Input... Enter Between 0 and 7." << endl;
                                    continue;
                                }
                            }
                            cout << " press key W for up, S for down,A for left and D for right " << endl;
                            int key;
                            key = _getch();
                            switch (key) {
                            case KEY_UP:
                                swap(array[x][y], array[x - 1][y]);
                                x = x - 1;
                                break;
                            case KEY_DOWN:
                                swap(array[x][y], array[x + 1][y]);
                                x = x + 1;
                                break;
                            case KEY_LEFT:
                                swap(array[x][y], array[x][y - 1]);
                                y = y - 1;
                                break;
                            case KEY_RIGHT:
                                swap(array[x][y], array[x][y + 1]);
                                y = y + 1;
                                break;
                            default:
                                cout << " Wrong Input " << endl;

                            }
                        }
                        if (array[x][y] == array[x - 1][y] && array[x][y] == array[x][y - 1] ||
                            array[x][y] == array[x - 1][y] && array[x - 1][y] == array[x - 2][y] && array[x][y] == array[x][y - 1] ||
                            array[x][y] == array[x - 1][y] && array[x][y] == array[x][y - 1] && array[x][y - 1] == array[x][y - 2]) {
                            score = score + 10;
                            char ch = array[x][y];
                            lshapeeasy(array, 8, x, y);
                            if (ch == array[x - 1][y])
                                lshapeeasy(array, 8, x - 1, y);
                            if (ch == array[x - 2][y])
                                lshapeeasy(array, 8, x - 2, y);
                            if (ch == array[x][y - 1])
                                lshapeeasy(array, 8, x, y - 1);
                            if (ch == array[x][y - 2])
                                lshapeeasy(array, 8, x, y - 2);
                        }
                        if ((array[x][y] == array[x][y + 1] && array[x][y + 1] == array[x][y + 2]) || // for row similar check
                            (array[x][y] == array[x][y - 1] && array[x][y] == array[x][y + 1]) ||
                            (array[x][y] == array[x][y - 1] && array[x][y - 1] == array[x][y - 2])) {
                            score = score + 10;
                            int count = y, countend = y;
                            if (array[x][y] == array[x][y + 1])
                                ++count;
                            if (array[x][y + 1] == array[x][y + 2])
                                ++count;
                            if (array[x][y] == array[x][y - 1])
                                --countend;
                            if (array[x][y - 1] == array[x][y - 2])
                                --countend;
                            for (int i = countend; i <= count; i++) {
                                for (int j = x; j >= 0; j--) {
                                    char c = crushrand(rand() % 5 + 1);
                                    if (j > 0)
                                        swap(array[j][i], array[j - 1][i]);
                                    if (j == 0)
                                        swap(array[0][i], c);
                                }
                            }
                        }
                        if ((array[x][y] == array[x - 1][y] && array[x - 1][y] == array[x - 2][y]) || //for similar column 
                            (array[x][y] == array[x + 1][y] && array[x][y] == array[x - 1][y]) ||
                            (array[x][y] == array[x + 1][y] && array[x + 1][y] == array[x + 2][y])) {
                            score = score + 10;
                            int count = 1;
                            if (array[x][y] == array[x - 1][y])
                                ++count;
                            if (array[x - 1][y] == array[x - 2][y])
                                ++count;
                            if (array[x][y] == array[x + 1][y]) {
                                ++count;
                                ++x;
                            }
                            if (array[x][y] == array[x + 1][y]) {
                                ++count;
                                ++x;
                            }
                            for (int i = count; i >= 0; i--) {
                                for (int j = x; j >= 0; j--) {
                                    char c = crushrand(rand() % 5 + 1);
                                    if (j > 0)
                                        swap(array[j][y], array[j - 1][y]);
                                    if (j == 0)
                                        swap(array[0][y], c);
                                }
                            }
                        }
                        if ((array[x][y] == array[x - 1][y - 1] && array[x - 1][y - 1] == array[x - 2][y - 2]) || // for same dignol
                            (array[x][y] == array[x - 1][y - 1] && array[x][y] == array[x + 1][y + 1]) ||
                            (array[x][y] == array[x + 1][y + 1] && array[x + 1][y + 1] == array[x + 2][y + 2])) {
                            score = score + 10;
                            int count = 1;
                            if (array[x][y] == array[x + 1][y + 1])
                                ++count;
                            if (array[x + 1][y + 1] == array[x + 2][y + 2])
                                ++count;
                            if (array[x][y] == array[x - 1][y - 1]) {
                                ++count;
                                --x;
                                --y;
                            }
                            if (array[x][y] == array[x - 1][y - 1]) {
                                ++count;
                                --x;
                                --y;
                            }
                            for (int i = 0; i <= count; i++) {
                                for (int j = x + i, col = y + i; j >= 0; j--) {
                                    char c = crushrand(rand() % 5 + 1);
                                    if (j > 0)
                                        swap(array[j][col], array[j - 1][col]);
                                    if (j == 0)
                                        swap(array[0][col], c);
                                }
                            }
                        }
                        if ((array[x][y] == array[x - 1][y + 1] && array[x - 1][y + 1] == array[x - 2][y + 2]) ||
                            (array[x][y] == array[x - 1][y + 1] && array[x][y] == array[x + 1][y - 1]) ||
                            (array[x][y] == array[x + 1][y - 1] && array[x + 1][y - 1] == array[x + 2][y - 2])) {
                            score = score + 10;
                            int count = 1;
                            if (array[x][y] == array[x + 1][y - 1])
                                ++count;
                            if (array[x + 1][y - 1] == array[x + 2][y - 2])
                                ++count;
                            if (array[x][y] == array[x - 1][y + 1]) {
                                ++count;
                                --x;
                                ++y;
                            }
                            if (array[x][y] == array[x - 1][y + 1]) {
                                ++count;
                                --x;
                                ++y;
                            }
                            for (int i = 0; i <= count; i++) {
                                for (int j = x + i, col = y - i; j >= 0; j--) {
                                    char c = crushrand(rand() % 5 + 1);
                                    if (j > 0)
                                        swap(array[j][col], array[j - 1][col]);
                                    if (j == 0)
                                        swap(array[0][col], c);
                                }
                            }
                        }
                        Sleep(1000);
                        system("cls");
                    }
                    ofstream outFile("myData.txt");
                    if (!outFile.is_open()) {
                        cerr << "Error opening the file!" << endl;
                        return 1;
                    }
                    game_easy[easy] = score;
                    outFile << game_easy[0] << endl;
                    outFile << game_easy[1] << endl;
                    outFile << game_easy[2] << endl;
                    outFile.close();
                    easy++;
                    if (easy > 2)
                        easy = 0;
                    cout << " -------------------- " << endl;
                    cout << "|                    |" << endl;
                    cout << "|     TIME   UP      |" << endl;
                    cout << "|                    |" << endl;
                    cout << " -------------------- " << endl;
                    Sleep(500);
                    system("cls");
                }
                if (choice == '2') {
                    int timer = 40, score = 0;
                    const int w = 10, h = 10;
                    char array[w][h] = { ' ' };
                    srand(time(0));
                    for (int i = 0; i < h; i++) {
                        for (int j = 0; j < w; j++) {
                            array[i][j] = crushrand(rand() % 7 + 1);
                        }
                    }
                    while (timer > 0) {
                        cout << "\tTimer :" << timer-- << "\t\tScore :" << score << endl;
                        pattrenhard(array, w);
                        cout << " Press any key to continue" << endl;
                        if (_kbhit()) { // press any key and enter in if and timer stop
                            while (true)
                            {
                                cout << "Which Element You want to swap?";
                                cout << "Input row:";
                                cin >> x;
                                cout << "Input column:";
                                cin >> y;
                                if (x >= 0 && x < 10 && y >= 0 && y < 10)
                                    break;
                                else
                                {
                                    cout << "Invalid Input... Enter Between 0 and 10." << endl;
                                    continue;
                                }
                            }
                            cout << " press key W for up, S for down,A for left and D for right " << endl;
                            int key;
                            key = _getch();
                            switch (key) {
                            case KEY_UP:
                                swap(array[x][y], array[x - 1][y]);
                                x = x - 1;
                                break;
                            case KEY_DOWN:
                                swap(array[x][y], array[x + 1][y]);
                                x = x + 1;
                                break;
                            case KEY_LEFT:
                                swap(array[x][y], array[x][y - 1]);
                                y = y - 1;
                                break;
                            case KEY_RIGHT:
                                swap(array[x][y], array[x][y + 1]);
                                y = y + 1;
                                break;
                            default:
                                cout << " Wrong Input " << endl;

                            }
                        }
                        if (array[x][y] == array[x - 1][y] && array[x][y] == array[x][y - 1] ||
                            array[x][y] == array[x - 1][y] && array[x - 1][y] == array[x - 2][y] && array[x][y] == array[x][y - 1] ||
                            array[x][y] == array[x - 1][y] && array[x][y] == array[x][y - 1] && array[x][y - 1] == array[x][y - 2]) {
                            score = score + 10;
                            char ch = array[x][y];
                            lshapehard(array, 10, x, y);
                            if (ch == array[x - 1][y])
                                lshapehard(array, 10, x - 1, y);
                            if (ch == array[x - 2][y])
                                lshapehard(array, 10, x - 2, y);
                            if (ch == array[x][y - 1])
                                lshapehard(array, 10, x, y - 1);
                            if (ch == array[x][y - 2])
                                lshapehard(array, 10, x, y - 2);
                        }
                        if ((array[x][y] == array[x][y + 1] && array[x][y + 1] == array[x][y + 2]) || // for row similar check
                            (array[x][y] == array[x][y - 1] && array[x][y] == array[x][y + 1]) ||
                            (array[x][y] == array[x][y - 1] && array[x][y - 1] == array[x][y - 2])) {
                            score = score + 10;
                            int count = y, countend = y;
                            if (array[x][y] == array[x][y + 1])
                                ++count;
                            if (array[x][y + 1] == array[x][y + 2])
                                ++count;
                            if (array[x][y] == array[x][y - 1])
                                --countend;
                            if (array[x][y - 1] == array[x][y - 2])
                                --countend;
                            for (int i = countend; i <= count; i++) {
                                for (int j = x; j >= 0; j--) {
                                    char c = crushrand(rand() % 7 + 1);
                                    if (j > 0)
                                        swap(array[j][i], array[j - 1][i]);
                                    if (j == 0)
                                        swap(array[0][i], c);
                                }
                            }
                        }
                        if ((array[x][y] == array[x - 1][y] && array[x - 1][y] == array[x - 2][y]) || //for similar column 
                            (array[x][y] == array[x + 1][y] && array[x][y] == array[x - 1][y]) ||
                            (array[x][y] == array[x + 1][y] && array[x + 1][y] == array[x + 2][y])) {
                            score = score + 10;
                            int count = 1;
                            if (array[x][y] == array[x - 1][y])
                                ++count;
                            if (array[x - 1][y] == array[x - 2][y])
                                ++count;
                            if (array[x][y] == array[x + 1][y]) {
                                ++count;
                                ++x;
                            }
                            if (array[x][y] == array[x + 1][y]) {
                                ++count;
                                ++x;
                            }
                            for (int i = count; i >= 0; i--) {
                                for (int j = x; j >= 0; j--) {
                                    char c = crushrand(rand() % 7 + 1);
                                    if (j > 0)
                                        swap(array[j][y], array[j - 1][y]);
                                    if (j == 0)
                                        swap(array[0][y], c);
                                }
                            }
                        }
                        if ((array[x][y] == array[x - 1][y - 1] && array[x - 1][y - 1] == array[x - 2][y - 2]) || // for same dignol
                            (array[x][y] == array[x - 1][y - 1] && array[x][y] == array[x + 1][y + 1]) ||
                            (array[x][y] == array[x + 1][y + 1] && array[x + 1][y + 1] == array[x + 2][y + 2])) {
                            score = score + 10;
                            int count = 1;
                            if (array[x][y] == array[x + 1][y + 1])
                                ++count;
                            if (array[x + 1][y + 1] == array[x + 2][y + 2])
                                ++count;
                            if (array[x][y] == array[x - 1][y - 1]) {
                                ++count;
                                --x;
                                --y;
                            }
                            if (array[x][y] == array[x - 1][y - 1]) {
                                ++count;
                                --x;
                                --y;
                            }
                            for (int i = 0; i <= count; i++) {
                                for (int j = x + i, col = y + i; j >= 0; j--) {
                                    char c = crushrand(rand() % 7 + 1);
                                    if (j > 0)
                                        swap(array[j][col], array[j - 1][col]);
                                    if (j == 0)
                                        swap(array[0][col], c);
                                }
                            }
                        }
                        if ((array[x][y] == array[x - 1][y + 1] && array[x - 1][y + 1] == array[x - 2][y + 2]) ||
                            (array[x][y] == array[x - 1][y + 1] && array[x][y] == array[x + 1][y - 1]) ||
                            (array[x][y] == array[x + 1][y - 1] && array[x + 1][y - 1] == array[x + 2][y - 2])) {
                            score = score + 10;
                            int count = 1;
                            if (array[x][y] == array[x + 1][y - 1])
                                ++count;
                            if (array[x + 1][y - 1] == array[x + 2][y - 2])
                                ++count;
                            if (array[x][y] == array[x - 1][y + 1]) {
                                ++count;
                                --x;
                                ++y;
                            }
                            if (array[x][y] == array[x - 1][y + 1]) {
                                ++count;
                                --x;
                                ++y;
                            }
                            for (int i = 0; i <= count; i++) {
                                for (int j = x + i, col = y - i; j >= 0; j--) {
                                    char c = crushrand(rand() % 7 + 1);
                                    if (j > 0)
                                        swap(array[j][col], array[j - 1][col]);
                                    if (j == 0)
                                        swap(array[0][col], c);
                                }
                            }
                        }
                        Sleep(1000);
                        system("cls");
                    }
                    ofstream outFile("myData1.txt");
                    if (!outFile.is_open()) {
                        cerr << "Error opening the file!" << endl;
                        return 1;
                    }
                    game_hard[hard] = score;
                    outFile << game_hard[0] << endl;
                    outFile << game_hard[1] << endl;
                    outFile << game_hard[2] << endl;
                    outFile.close();
                    hard++;
                    if (hard > 2)
                        hard = 0;
                    cout << " -------------------- " << endl;
                    cout << "|                    |" << endl;
                    cout << "|     TIME   UP      |" << endl;
                    cout << "|                    |" << endl;
                    cout << " -------------------- " << endl;
                    Sleep(500);
                    system("cls");
                }
                else if (choice == '3')
                    break;
                else {
                    cout << " Invalid input " << endl;
                    system("cls");
                    continue;
                }
            }
        }
        else if (selection == '2') {
            while (true) {
                cout << " ------------------------------ " << endl;
                cout << "|                              |" << endl;
                cout << "|  1. Easy Mode score          |" << endl;
                cout << "|                              |" << endl;
                cout << "|  2. Hard Mode score          |" << endl;
                cout << "|                              |" << endl;
                cout << "|  3. Back to home             |" << endl;
                cout << "|                              |" << endl;
                cout << "|  Enter Your Choice           |" << endl;
                cout << "|                              |" << endl;
                cout << " ------------------------------ " << endl;
                char choice;
                cin >> choice;
                system("cls");
                if (choice == '1') {
                    while (true) {
                        ifstream inFile("myData.txt");
                        if (!inFile.is_open()) {
                            cerr << "Error opening the file!" << endl;
                            return 1;
                        }
                        inFile >> game_easy[0];
                        inFile >> game_easy[1];
                        inFile >> game_easy[2];
                        cout << "Game1: " << game_easy[0] << endl;
                        cout << "Game2: " << game_easy[1] << endl;
                        cout << "Game3: " << game_easy[2] << endl;
                        inFile.close();
                        cout << endl;
                        char x;
                        cout << "Move back enter 0" << endl;
                        cin >> x;
                        if (x == '0') // for move back to score form easy score
                            break;
                        else { // for invalid input in easy score
                            cout << "invalid input" << endl;
                            system("cls");
                            continue;
                        }
                    }
                }
                if (choice == '2') {
                    while (true) {
                        ifstream inFile("myData1.txt");
                        if (!inFile.is_open()) {
                            cerr << "Error opening the file!" << endl;
                            return 1;
                        }
                        inFile >> game_hard[0];
                        inFile >> game_hard[1];
                        inFile >> game_hard[2];
                        cout << "Game1: " << game_hard[0] << endl;
                        cout << "Game2: " << game_hard[1] << endl;
                        cout << "Game3: " << game_hard[2] << endl;
                        inFile.close();
                        cout << endl;
                        char x;
                        cout << "Move back enter 0" << endl;
                        cin >> x;
                        if (x == '0') // for move back to score from hard score
                            break;
                        else { // for invalid input in hard score
                            cout << "invalid input" << endl;
                            system("cls");
                            continue;
                        }
                    }
                }
                if (choice == '3') { // for back to home from score
                    break;
                }
                else { // for invalid input in score
                    cout << " Invalid choice " << endl;
                    system("cls");
                    continue;
                }
            }
        }
        else if (selection == '3') { // for exit in main
            break;
        }
        if (selection == '4') {
            while (true) {
                char x = ' ';
                cout << "\t\t\t\t |---------------------Instructions---------------------|" << endl;
                cout << "\t\t\t\t |                                                      |" << endl;
                cout << "\t\t\t\t | How to Play:                                         |" << endl;
                cout << "\t\t\t\t |                                                      |" << endl;
                cout << "\t\t\t\t |   1. Select Play Mode By pressing 1 or 2             |" << endl;
                cout << "\t\t\t\t |   3. Give Candy address.                             |" << endl;
                cout << "\t\t\t\t |   3. Press w for up , s for down, A for left, D      |" << endl;
                cout << "\t\t\t\t |      for Right                                       |" << endl;
                cout << "\t\t\t\t | GamePlay:                                            |" << endl;
                cout << "\t\t\t\t |                                                      |" << endl;
                cout << "\t\t\t\t |   1. When Player Swipe Candy and candy not crushes   |" << endl;
                cout << "\t\t\t\t |  Turn will be lost and Candy will swipe.             |" << endl;
                cout << "\t\t\t\t |   2.If condition Matches Upper Candies Will move down|" << endl;
                cout << "\t\t\t\t |   and new Candies will be generated above.           |" << endl;
                cout << "\t\t\t\t |                                                      |" << endl;
                cout << "\t\t\t\t |    Press 0 for go back..                             |" << endl;
                cout << "\t\t\t\t |------------------------------------------------------|" << endl;
                cin >> x;
                if (x == '0') {// for move back to home
                    system("cls");
                    break;
                }
                else { // for invalid input in instruction
                    cout << "invalid input" << endl;
                    system("cls");
                    continue;
                }
            }
        }
        if (selection == '5') {
            while (true) {
                char x = ' ';
                cout << "\t\t\t\t |----------CREDITS-----------|" << endl;
                cout << "\t\t\t\t |                            |" << endl;
                cout << "\t\t\t\t |   Nimrah   23F-0734        |" << endl;
                cout << "\t\t\t\t |                            |" << endl;
                cout << "\t\t\t\t |   Naeem    23f0690         |" << endl;
                cout << "\t\t\t\t |                            |" << endl;
                cout << "\t\t\t\t |                            |" << endl;
                cout << "\t\t\t\t |   Press 0 to go back.      |" << endl;
                cout << "\t\t\t\t |----------------------------|" << endl;
                cin >> x;
                if (x == '0') {// for move back to home
                    system("cls");
                    break;
                }
                else { // for invalid input in instruction
                    cout << "invalid input" << endl;
                    system("cls");
                    continue;
                }
            }
        }
        else { // for invalid input in main
            cout << "Invalid input" << endl;
            system("cls");
            continue;
        }
    }
    system("pause");
    return 0;
}

void swap(char& x, char& y) { // swap two values
    x = x + y;
    y = x - y;
    x = x - y;
}
char crushrand(int c) { // random candy
    char candy = ' ';
    if (c == 1)
        candy = '@';
    else if (c == 2)
        candy = '#';
    else if (c == 3)
        candy = '$';
    else if (c == 4)
        candy = '%';
    else if (c == 5)
        candy = '&';
    else if (c == 6)
        candy = '!';
    else if (c == 7)
        candy = '*';
    return candy;
}
void lshapeeasy(char array[][height1], int w, int x, int y) { // for swap with function
    for (int j = x; j >= 0; j--) {
        char c = crushrand(rand() % 5 + 1);
        if (j > 0)
            swap(array[j][y], array[j - 1][y]);
        if (j == 0)
            swap(array[0][y], c);
    }
}
void pattreneasy(char array[][height1], int w) { // for make pattren in easy mode
    for (int i = 0; i < height1; i++) {
        cout << endl;
        if (i == 0) {
            cout << "     ";
            for (int j = 0; j < w; j++)
                cout << " col" << j << " ";
            cout << endl;
        }
        cout << "      ";
        for (int j = 0; j < w; j++)
            cout << "-----" << " ";
        cout << endl;
        cout << " row" << i;
        cout << "|";

        for (int j = 0; j < w; j++) {
            colour(array[i][j]);
            cout << "  " << array[i][j] << "  " << "|";
        }
    }
    cout << endl << "      ";
    for (int j = 0; j < w; j++)
        cout << "-----" << " ";
    cout << endl;
}
void colour(char ch) { // for colour in candy
    switch (ch) {
    case '$':
        cout << ANSI_COLOR_RED;
        break;
    case '%':
        cout << ANSI_COLOR_GREEN;
        break;
    case '#':
        cout << ANSI_COLOR_YELLOW;
        break;
    case '&':
        cout << ANSI_COLOR_BLUE;
        break;
    case '*':
        cout << ANSI_COLOR_MAGENTA;
        break;
    case '!':
        cout << ANSI_COLOR_CYAN;
        break;
    default:
        cout << ANSI_COLOR_RESET;
    }
}
void lshapehard(char array[][height2], int w, int x, int y) { // for swap in l shap
    for (int j = x; j >= 0; j--) {
        char c = crushrand(rand() % 7 + 1);
        if (j > 0)
            swap(array[j][y], array[j - 1][y]);
        if (j == 0)
            swap(array[0][y], c);
    }
}
void pattrenhard(char array[][height2], int w) { // for pattren in hard mode
    for (int i = 0; i < height2; i++) {
        cout << endl;
        if (i == 0) {
            cout << "     ";
            for (int j = 0; j < w; j++)
                cout << " col" << j << " ";
            cout << endl;
        }
        cout << "      ";
        for (int j = 0; j < w; j++)
            cout << "-----" << " ";
        cout << endl;
        cout << " row" << i;
        cout << "|";

        for (int j = 0; j < w; j++) {
            colour(array[i][j]);
            cout << "  " << array[i][j] << "  " << "|";
        }
    }
    cout << endl << "      ";
    for (int j = 0; j < w; j++)
        cout << "-----" << " ";
    cout << endl;
}