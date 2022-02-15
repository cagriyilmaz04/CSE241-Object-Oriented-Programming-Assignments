#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Klotski.h"

using namespace std;

namespace Cagri_Games{
Klotski::Klotski(){
    
    
    
}
void Klotski::initialize(){
    Board.resize(7);
    for (int i = 0; i < 7; i++)
    {
        Board[i].resize(5);
    }
    Board = {
    {2,4,4,2},{2,4,4,2},{2,3,3,2},{2,1,1,2},{1,0,0,1},{5,6,6,5}
    };
    size = 5;
}
bool Klotski::checkOutput(string Directions) {
    auto number = Directions[0] - 48;
    bool flag = false;
    if (number >= 0 && number < 6) {
        if (Directions[1] - 65 >= 0 && Directions[1] - 65 <= 4) {
            string yeni = Directions.erase(0, 3);
            if (yeni == "DOWN" || yeni == "UP" || yeni == "LEFT" || yeni == "RIGHT") {
                flag = true;
            }
            else {
                cerr << "You need to enter DOWN , UP , LEFT or RIGHT\n";
            }
        }
        else {
            cerr << "You need to enter a value between A and C\n";
        }
    }
    else {
        cerr << "You need to enter a number that is between 0 and 5\n";
    }

    return flag;


}
void Klotski::setScore() {

}
void Klotski::goToLeft(const int i, const int j, bool flag) {

    if (Board[i][j] == 1 && Board[i][j - 1] == 0)  {
        Board[i][j - 1] = 1;
        Board[i][j] = 0;
    }
    else if (Board[i][j] == 2 && Board[i][j - 1] == 0 && Board[i + 1][j - 1] == 0) {
        Board[i][j - 1] = 2;
        Board[i + 1][j - 1] = 2;
        Board[i][j] = 0;
        Board[i + 1][j] = 0;
    }
    else if (Board[i][j] == 3 && Board[i][j + 1] == 3 && Board[i][j - 1] == 0) {
        Board[i][j] = 3;
        Board[i][j - 1] = 3;
        Board[i][j + 1] = 0;
    }
    else if (Board[i][j] == 4 && Board[i][j + 1] == 4 && Board[i + 1][j] == 4 && Board[i + 1][j + 1] == 4 && Board[i][j - 1] == 0 && Board[i + 1][j - 1] == 0)
    {
        Board[i][j - 1] = 4;
        Board[i + 1][j - 1] = 4;
        Board[i][j + 1] = 0;
        Board[i + 1][j + 1] = 0;
    }

}
void Klotski::goToRight(const int i, const int j, bool flag) {
    if (Board[i][j] == 1 && Board[i][j + 1] == 0) {
        Board[i][j + 1] = 1;
        Board[i][j] = 0;
    }
    else if (Board[i][j] == 2 && Board[i][j + 1] == 0 && Board[i + 1][j + 1] == 0){
        Board[i][j + 1] = 2;
        Board[i + 1][j + 1] = 2;
        Board[i][j] = 0;
        Board[i + 1][j] = 0;
    }
    else if (Board[i][j] == 3 && Board[i][j + 1] == 3 && Board[i][j + 2] == 0)  {
        Board[i][j] = 0;
        Board[i][j + 1] = 3;
        Board[i][j + 2] = 3;
    }
    else if (Board[i][j] == 4 && Board[i][j + 1] == 4 && Board[i + 1][j] == 4 && Board[i + 1][j + 1] == 4 && Board[i][j + 1] == 0 && Board[i + 1][j + 1] == 0) {
        Board[i][j] = 0;
        Board[i + 1][j] = 0;
        Board[i][j + 2] = 4;
        Board[i + 1][j + 2] = 4;
    }

}
void Klotski::goToDown(const int i, const int j, bool flag) {
    if (Board[i][j] == 1 && Board[i + 1][j] == 0)  {
        Board[i + 1][j] = 1;
        Board[i][j] = 0;
    }
    else if (Board[i][j] == 2 && Board[i + 1][j] == 2 && Board[i + 2][j] == 0) {
        Board[i][j] = 0;
        Board[i + 2][j] = 2;
    }
    else if (Board[i][j] == 3 && Board[i][j + 1] == 3 && Board[i + 1][j] == 0 && Board[i + 1][j + 1] == 0)  {
        Board[i][j] = 0;
        Board[i][j + 1] = 0;
        Board[i + 1][j] = 3;
        Board[i + 1][j + 1] = 3;
    }
    else if (Board[i][j] == 4 && Board[i][j + 1] == 4 && Board[i + 1][j] == 4 && Board[i + 1][j + 1] == 4 && Board[i + 2][j] == 0 && Board[i + 2][j + 1] == 0)  {
        Board[i][j] = 0;
        Board[i][j + 1] = 0;
        Board[i + 2][j] = 4;
        Board[i + 2][j + 1] = 4;
    }
}
void Klotski::goToUp(const int i, const int j, bool flag) {
    if (Board[i][j] == 1 && Board[i - 1][j] == 0) {
        Board[i - 1][j] = 1;
        Board[i][j] = 0;
    }
    else if (Board[i][j] == 2 && Board[i + 1][j] == 2 && Board[i - 1][j] == 0){
        Board[i + 1][j] = 0;
        Board[i - 1][j] = 2;
    }
    else if (Board[i][j] == 3 && Board[i][j + 1] == 3 && Board[i - 1][j] == 0 && Board[i - 1][j + 1] == 0) {
        Board[i][j] = 0;
        Board[i][j + 1] = 0;
        Board[i - 1][j] = 3;
        Board[i - 1][j + 1] = 3;
    }
    else if (Board[i][j] == 4 && Board[i][j + 1] == 4 && Board[i + 1][j] == 4 && Board[i + 1][j + 1] == 4 && Board[i - 1][j] == 0 && Board[i - 1][j + 1] == 0) {
        Board[i + 1][j] = 0;
        Board[i + 1][j + 1] = 0;
        Board[i - 1][j] = 4;
        Board[i - 1][j + 1] = 4;
    }
}




void Klotski::playUser(string coordinate)
{
    int i = coordinate[0] - '0';
    int j = coordinate[1] - 'A';
    char direction = coordinate[3];
    string yeni = coordinate.erase(0, 3);
    bool flag = false;
    if (yeni == "RIGHT") {
        goToRight(i, j, flag);
    }
    if (yeni == "LEFT") {
        goToLeft(i, j, flag);
    }
    if (yeni == "DOWN") {
        goToDown(i, j, flag);
    }
    if (yeni == "UP") {
        goToUp(i, j, flag);
    }
   
}

void Klotski::playUser()
{
    string coordinate;
    bool flag = false;
    while (!endGame()){
        print();
        while (!flag) {
            cout << "Please enter direction\n";
            getline(cin >> ws, coordinate);
            if (checkOutput(coordinate)) {
                flag = true;
                playUser(coordinate);
            }
        }
        flag = false;
    }
    print();

}
void Klotski::playAuto(){
    int i, j,direction;
	direction = (rand() % 4);
    i = (rand() % 5);
    j = (rand() % 4);

    if (Board[i][j] == 4 && Board[i + 1][j] == 4 && Board[i][j + 1] == 4 && Board[i + 1][j + 1] == 4 && Board[i + 2][j] == 6 && Board[i + 2][j + 1] == 6){
        Board[i + 2][j] = 4;
        Board[i + 2][j + 1] = 4;
        Board[i][j] = 0;
        Board[i][j + 1] = 0;
        return;

    }

    if ((j == 0 && direction == 2) || (j == 3 && direction == 0) || (i == 0 && direction == 3) || (i == 4 && direction == 1)) {
        return;
    }

    if (i == 2 && Board[i][j] == 4 && direction == 3) {
        return;
    }

    if (Board[i][j] == 4 && Board[i + 2][j] == 6)  {
        
    }
    if (direction == 0) {
        if (Board[i][j] == 1 && Board[i][j + 1] == 0) {
            Board[i][j + 1] = 1;
            Board[i][j] = 0;
        }
        else if (Board[i][j] == 2 && Board[i + 1][j] == 2 && Board[i][j + 1] == 0 && Board[i + 1][j + 1] == 0)  {
            Board[i][j] = 0;
            Board[i + 1][j] = 0;
            Board[i][j + 1] = 2;
            Board[i + 1][j + 1] = 2;
           
        }
        else if (Board[i][j] == 3 && Board[i][j + 1] == 3 && Board[i][j + 2] == 0) {
            if (j + 2 > 3) {
                return;
            }
            Board[i][j + 1] = 3;
            Board[i][j + 2] = 3;
            Board[i][j] = 0;
          
        }
        else if (Board[i][j] == 4 && Board[i][j + 1] == 4 && Board[i + 1][j] == 4 && Board[i + 1][j + 1] == 4 && Board[i][j + 2] == 0 && Board[i + 1][j + 2] == 0)   {
            if (j + 2 > 3)  {
                return;
            }
            Board[i][j + 2] = 4;
            Board[i + 1][j + 2] = 4;
            Board[i][j] = 0;
            Board[i + 1][j] = 0;
         
        }
    }
    if (direction == 1) {
        if (Board[i][j] == 1 && Board[i + 1][j] == 0) {
            Board[i + 1][j] = 1;
            Board[i][j] = 0;
        }
        else if (Board[i][j] == 2 && Board[i + 1][j] == 2 && Board[i + 2][j] == 0) {
            if (i + 2 > 4)
            {
                return;
            }
            Board[i][j] = 0;
            Board[i + 2][j] = 2;
        }
        else if (Board[i][j] == 3 && Board[i][j + 1] == 3 && Board[i + 1][j] == 0 && Board[i + 1][j + 1] == 0) {
            Board[i + 1][j] = 3;
            Board[i + 1][j + 1] = 3;
            Board[i][j] = 0;
            Board[i][j + 1] = 0;
          
        }
        else if (Board[i][j] == 4 && Board[i][j + 1] == 4 && Board[i + 1][j] == 4 && Board[i + 1][j + 1] == 4 && Board[i + 2][j] == 0 && Board[i + 2][j + 1] == 0)
        {
            if ((i == 3 && j == 0) || (i == 3 && j == 2))
            {
                return;
            }
            Board[i + 2][j] = 4;
            Board[i + 2][j + 1] = 4;
            Board[i][j] = 0;
            Board[i][j + 1] = 0;
           
        }
    }
    if (direction == 2) {
        if (Board[i][j] == 1 && Board[i][j - 1] == 0)  {
            Board[i][j - 1] = 1;
            Board[i][j] = 0;
        }
        else if (Board[i][j] == 2 && Board[i + 1][j] == 2 && Board[i][j - 1] == 0 && Board[i + 1][j - 1] == 0)  {
			 Board[i][j - 1] = 2;
            Board[i + 1][j - 1] = 2;
            Board[i][j] = 0;
            Board[i + 1][j] = 0;
           
          
        }
        else if (Board[i][j] == 3 && Board[i][j + 1] == 3 && Board[i][j - 1] == 0) {
            Board[i][j] = 3;
            Board[i][j - 1] = 3;
            Board[i][j + 1] = 0;
        }
        else if (Board[i][j] == 4 && Board[i][j + 1] == 4 && Board[i + 1][j] == 4 && Board[i + 1][j + 1] == 4 && Board[i][j - 1] == 0 && Board[i + 1][j - 1] == 0){
            Board[i][j + 1] = 0;
            Board[i + 1][j + 1] = 0;
            Board[i][j - 1] = 4;
            Board[i + 1][j - 1] = 4;
           
        }
    }
    if (direction == 3) {
        if (Board[i][j] == 1 && Board[i - 1][j] == 0) {
            Board[i - 1][j] = 1;
            Board[i][j] = 0;
        }
        else if (Board[i][j] == 2 && Board[i + 1][j] == 2 && Board[i - 1][j] == 0)  {
            Board[i + 1][j] = 0;
            Board[i - 1][j] = 2;
        }
        else if (Board[i][j] == 3 && Board[i][j + 1] == 3 && Board[i - 1][j] == 0 && Board[i - 1][j + 1] == 0) {
			 Board[i - 1][j] = 3;
            Board[i - 1][j + 1] = 3;
            Board[i][j] = 0;
            Board[i][j + 1] = 0;
           
        }
        else if (Board[i][j] == 4 && Board[i][j + 1] == 4 && Board[i + 1][j] == 4 && Board[i + 1][j + 1] == 4 && Board[i - 1][j] == 0 && Board[i - 1][j + 1] == 0) {
			 Board[i + 1][j] = 0;
            Board[i + 1][j + 1] = 0;
            Board[i - 1][j] = 4;
            Board[i - 1][j + 1] = 4;
           
           
        }
    }
}

void Klotski::playAutoAll(){
    print();
    while (!endGame()){
        playAuto();
    }
    print();
}



int Klotski::boardScore(){
    return 1;
}
void Klotski::print(){
    cout << "  ";
    int i, j, a=0;
	
	while(a<4){
		cout << " "<< char(a+'A');
		++a;
	}
   
    cout << endl;
    for (i = 0; i < 6; i++) {
        cout << "  " << i;
        for (j = 0; j < 4; j++){
            if (Board[i][j] == 1){
                cout << "\033[1;41m   \033[0m";
            }
            else if (Board[i][j] == 2){
                cout << "\033[1;43m   \033[0m";
            }
            else if (Board[i][j] == 3){
                cout << "\033[1;44m   \033[0m";
            }
            else if (Board[i][j] == 4){
                cout << "\033[1;45m   \033[0m";
            }
            else if (Board[i][j] == 0){
                cout << "\033[1;40m   \033[0m";
            }
            else if (Board[i][j] == 5)  {
                cout << "   ";
            }
            else if (Board[i][j] == 6)  {
                cout << "\033[1;5mxxx\033[0m";
            }
        }
        cout << endl;
    }
}

bool Klotski::endGame(){
    if (Board[5][1] == 4 && Board[5][2] == 4) {
        return true;
    }
    else {
        return false;
    }
       
}
} // end of namespace