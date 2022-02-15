#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "PegSolitaire.h"

using namespace std;

namespace Cagri_Games{

void PegSolitaire::setScore() {

}
int PegSolitaire::boardScore() {
    vector<vector<int>> list = getArray();
    int result = 0;
    int i, j;
    for (i = 0;i < getColumn();++i) {
        for (j = 0;j < getRow();++j) {
            if (list[i][j] == 1)
                ++result;
        }
    }
    score = result;
    return result;

}
PegSolitaire::PegSolitaire() {
   

}
void PegSolitaire::playAuto() {
    bool flag = true;
    bool flag1 = false;
    int x, y;
    int a;


    while (flag) {
        x = rand() % 7;
        y = rand() % 7;
        a = rand() % 4;
		//Decide to coordinate and directions
        if (a == 0) {
            goToDown(x, y, flag1);
        }
        else if (a == 1) {
            goToUp(x, y, flag1);
        }
        else if (a == 2) {
            goToLeft(x, y, flag1);
        }
        else  if (a == 3) {
            goToRight(x, y, flag1);
        }
      
        if (getFlag() == true) {
            flag = false;
        }
    }
  
}
void PegSolitaire::playAutoAll() {
    print();
    while (endGame()) {
        playAuto();
    }
 
    setScore();
	boardScore();
	//print
    cout << *this;

}
bool PegSolitaire::checkOutput(string Directions) const {
    auto number = Directions[0] - 48;
    bool flag = false;
    if (number >= 0 && number < 7) {

        if (Directions[1] - 65 >= 0 && Directions[1] - 65 <= 7) {
            string yeni = Directions.erase(0, 3);
            if (yeni == "DOWN" || yeni == "UP" || yeni == "LEFT" || yeni == "RIGHT") {
                flag = true;
            }
            else {
                cerr << "You need to enter DOWN , UP , LEFT or RIGHT\n";
            }
        }
        else {
            cerr << "You need to enter a value between A and G\n";
        }
    }
    else {
        cerr << "You need to enter a number that is between 0 and 7\n";
    }

    return flag;

}
void PegSolitaire::playUser() {
    initialize();
    print();
    string coordinates;
    bool flag = false;
    while (endGame()) {
        while (!flag) {
            cout << "Enter your Coordinate and Directions that you want to do\n";
			//To prevent writing line 107 twice
            getline(cin >> ws, coordinates);
            if (coordinates.length() != 0) {
                if (checkOutput(coordinates)) {
                    flag = true;
                    playUser(coordinates);
                    print();
                }
            }


        }
        flag = false;

    }
}
void PegSolitaire::playUser(string directions) {
	// Our input are always like this 0A LEFT so this function parses our parameters 
    int number = directions[0] - 48;
    int yCoordinate = directions[1] - 65;
    const int temp = 0;
    string yeni = directions.erase(0, 3);
    if (yeni == "DOWN") {
        goToDown(number, yCoordinate, temp);
    }
    if (yeni == "UP") {
        goToUp(number, yCoordinate, temp);
    }
    if (yeni == "RIGHT") {
        goToRight(number, yCoordinate, temp);
    }
    if (yeni == "LEFT") {
        goToLeft(number, yCoordinate, temp);
    }


}
void PegSolitaire::goToUp(const int x, const int y, bool flag) {

    vector<vector<int>> board = getArray();
    if (!(x > 1)) {}
    else if ((board[x][y] == 1 && board[x - 1][y] == 1 && board[x - 2][y] == -1)) {
        board[x - 2][y] = 1;
        board[x - 1][y] = -1;
        board[x][y] = -1;
        flag = true;
        setFlag(flag);
        setArray(board);
    }
}
void PegSolitaire::goToDown(const int x, const int y, bool flag) {

    vector<vector<int>> board = getArray();
    if (x + 1 >= (getRow() - 1)) {}
    else if (x + 2 < getRow() && board[x][y] == 1 && board[x + 1][y] == 1 && board[x + 2][y] == -1) {
        board[x + 2][y] = 1;
        board[x + 1][y] = -1;
        board[x][y] = -1;
        flag = true;
        setFlag(flag);
        setArray(board);
    }
}
void PegSolitaire::goToLeft(const int x, const int y, bool flag) {
    vector<vector<int>> board = getArray();

    if (!(y > 2)) {
    }
    else if (((y >= 2)) && (board[x][y] == 1 && board[x][y - 1] == 1 && board[x][y - 2] == -1)) {

        board[x][y - 2] = 1;
        board[x][y - 1] = -1;
        board[x][y] = -1;
        setArray(board);
        flag = true;
        setFlag(flag);
    }
}
void PegSolitaire::goToRight(const int x, const int y, bool flag) {

    vector<vector<int>> board = getArray();
    if ((y + 2 >= getColumn())) {
    }
    else if (board[x][y] == 1 && board[x][y + 1] == 1 && board[x][y + 2] == -1) {
        board[x][y + 2] = 1;
        board[x][y + 1] = -1;
        board[x][y] = -1;
        flag = true;
        setArray(board);
        setFlag(flag);
    }
    else {
    }
}
bool PegSolitaire::checkSituation(const int x, const int y) const {
    bool flag = false;
    vector<vector<int>> board = getArray();
    if ((y >= 2) && (board[x][y] == -1 && board[x][y - 1] == 1 && board[x][y - 2] == 1)) {
        flag = true;
    }
    else if ((getRow() > y + 2) && board[x][y] == -1 && board[x][y + 1] == 1 && board[x][y + 2] == 1) {
        flag = true;
    }
    else if ((x < getColumn() - 2) && board[x][y] == -1 && board[x + 1][y] == 1 && board[x + 2][y] == 1) {
        flag = true;
    }
    else if ((x >= 2) && board[x][y] == -1 && board[x - 1][y] == 1 && board[x - 2][y] == 1) {
        flag = true;
    }
    return flag;
}
void PegSolitaire::print() {
    vector<vector<int>> list = getArray();
    int row, column,a=0;
    row = getRow();
    column = getColumn();
    cout << "  ";
    while (a < list.size()) {
        cout << char('A' + a) << ' ';
        ++a;
    }
    cout << "\n";
    int i, j;
    for (i = 0;i < column;++i) {
        cout << i << ' ';
        for (j = 0;j < column;++j) {
            if (list[i][j] == 0) {
                cout << " " << " ";
            }if (list[i][j] == 1) {
                cout << 'P' << ' ';
            }
            if (list[i][j] == -1) {
                cout << '.' << ' ';
            }
        }
        cout << "\n";
    }
}
void PegSolitaire::initialize() {
    int i, j;
    vector<vector<int>> list1, list2;
    vector<int> temp;
    for (i = 0;i < 7;++i) {
        for (j = 0;j < 7;++j) {
            if (i == 0 || i == 6) {
                temp.push_back(0);
                temp.push_back(0);
                temp.push_back(1);
                temp.push_back(1);
                temp.push_back(1);
                temp.push_back(0);
                temp.push_back(0);

            }
            if (i == 1 || i == 5) {
                temp.push_back(0);
                temp.push_back(1);
                temp.push_back(1);
                temp.push_back(1);
                temp.push_back(1);
                temp.push_back(1);
                temp.push_back(0);
            }
            if (i == 2 || i == 4) {
                temp.push_back(1);
            }
            if (i == 3) {
                if (j != 3) {
                    temp.push_back(1);
                }
                else {
                    temp.push_back(-1);

                }
            }

        }
        list1.push_back(temp);
        temp.clear();
    }
    setArray(list1);
    setRow(7);
    setColumn(7);
    print();
    cout << "\n";
    temp.clear();
    for (i = 0;i < 7;++i) {
        for (j = 0;j < 7;++j) {
            if (i == 0 || i == 6) {
                temp.push_back(0);
                temp.push_back(0);
                temp.push_back(1);
                temp.push_back(1);
                temp.push_back(1);
                temp.push_back(0);
                temp.push_back(0);
            }
            if (i == 1 || i == 5) {
                temp.push_back(0);
                temp.push_back(0);
                temp.push_back(1);
                temp.push_back(1);
                temp.push_back(1);
                temp.push_back(0);
                temp.push_back(0);
            }
            if (i == 2 || i == 4) {
                temp.push_back(1);
            }
            if (i == 3) {
                if (j != 3) {
                    temp.push_back(1);
                }
                else {
                    temp.push_back(-1);
                }
            }

        }
        list2.push_back(temp);
        temp.clear();
    }
    setArray(list2);
    print();
    bool flag1 = true;
    int choice;
	//To check input . Whether input is 1 or 2 
    while (flag1) {
        cout << "Choose one of them\n";
        if (!(cin >> choice)) {
            cout << "Enter a number and it has to be 1 or 2\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else {
            if (choice == 1) {
                setArray(list1);
                flag1 = false;
            }
            if (choice == 2) {
                setArray(list2);
                flag1 = false;
            }
           
        }
        
    }
    
}
bool PegSolitaire::endGame() {
    vector<vector<int>> list = getArray();
    bool flag = false;
    int i, j, x = 0;
    for (i = 0;i < getColumn();++i) {
        for (j = 0;j < getRow();++j) {
            int number = list[i][j];
            if (number != 0) {
                if (checkSituation(i, j)) {
                    j = getRow() + 1;
                    i = getColumn() + 1;
                    flag = true;
                    x = 0;
                    break;
                }
                else {
                    ++x;
                }
            }
        }
    }
    if (x != 0) {
        flag = false;
    }
    return flag;
}

} // end of namespace