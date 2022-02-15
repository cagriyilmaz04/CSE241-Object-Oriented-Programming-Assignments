#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "EightPuzzle.h"

using namespace std;

namespace Cagri_Games{

int EightPuzzle::boardScore() {
    vector<vector<int>> list = getArray();
    int i, j, result = 0;
    int returnedVal;
    int dizi[3][3] = { {1,2,3},{4,5,6},{7,8,-1} };
    for (i = 0;i < list.size();++i) {
        for (j = 0;j < list[0].size();++j) {
            if (list[i][j] == dizi[i][j]) {
                ++result;
            }
        }
    }
    if (result == 9) {
        returnedVal = 0;
    }
    else {
        returnedVal = 9 - result;
    }
    score = returnedVal;
    return returnedVal;
}
bool EightPuzzle::checkOutput(string Directions) {
    auto number = Directions[0] - 48;
    bool flag = false;
    if (number >= 0 && number < 3) {
        if (Directions[1] - 65 >= 0 && Directions[1] - 65 <= 2) {
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
        cerr << "You need to enter a number that is between 0 and 2\n";
    }

    return flag;



}
void EightPuzzle::playAutoAll() {
    vector <vector<int>> cagri;
    while (!endGame()) {

        playAuto();


    }
    boardScore();
    cout << *this;

}
void EightPuzzle::playAuto() {
    int i, j;
    int xCoor, yCoor;
    int random, oldrandom = -1;
    vector<vector<int>> list = getArray();


    random = (rand() % 4);
    int iter_x, iter_y;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (list[i][j] == -1)
            {
                iter_x = i;
                iter_y = j;
            }
        }
    }

    if (list[0][0] == 1 && list[0][1] == 2 && list[0][2] == 3 && iter_x == 1) {
        while (random == 1) {
            random = (rand() % 4);
        }
    }
    if (list[1][0] == 4 && list[1][1] == 5 && list[1][2] == 6 && list[2][1] == 7 && list[2][2] == 8) {
        while (random == 1 && random == 3) {
            random = (rand() % 4);
        }
    }
    else if (list[1][0] == 4 && list[1][1] == 5 && list[1][2] == 6 && list[2][0] == 7 && list[2][2] == 8) {
        while (random == 1 && random == 3) {
            random = (rand() % 4);
        }
    }
    while (oldrandom == 0 && random == 2 || oldrandom == 1 && random == 3 || oldrandom == 2 && random == 4 || oldrandom == 3 && random == 1 || oldrandom == 2 && random == 0) {
        random = (rand() % 4);
    }
    if (random == 0) {
        if (iter_y != 0) {
            list[iter_x][iter_y] = list[iter_x][iter_y - 1];
            list[iter_x][iter_y - 1] = -1;
            oldrandom = random;
        }
    }
    else if (random == 1) {
        if (iter_x != 0) {
            list[iter_x][iter_y] = list[iter_x - 1][iter_y];
            list[iter_x - 1][iter_y] = -1;
            oldrandom = random;
        }
    }
    else if (random == 2) {
        if (iter_y != 2) {
            list[iter_x][iter_y] = list[iter_x][iter_y + 1];
            list[iter_x][iter_y + 1] = -1;
            oldrandom = random;
        }
    }
    else if (random == 3) {
        if (iter_x != 2) {
            list[iter_x][iter_y] = list[iter_x + 1][iter_y];
            list[iter_x + 1][iter_y] = -1;
            oldrandom = random;
        }
    }
    setArray(list);
}
void EightPuzzle::setScore() {

}
void EightPuzzle::playUser() {
    string coordinate;
    bool flag = false;
    while (!endGame()) {
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
}
void EightPuzzle::print() {

    vector<vector<int>>  list = getArray();
    int i, j, a = 0;
    cout << "  ";
    while (a < list[0].size()) {
        cout << char('A' + a) << ' ';
        ++a;
    }
    cout << "\n";

    for (i = 0;i < 3;++i) {
        cout << i << ' ';
        for (j = 0;j < 3;++j) {
            if (list[i][j] != -1) {
                cout << list[i][j] << " ";
            }
            else {
                cout << " " << " ";
            }
        }
        cout << "\n";
    }
}
void EightPuzzle::initialize() {
    vector<vector<int>>  list;
    vector <int> temp;
    int i, j, number;
    bool flag = true;
    for (i = 0;i < 3;++i) {
        for (j = 0;j < 3;++j) {
            number = 0;
            temp.push_back(number);
        }
        list.push_back(temp);
        temp.clear();
    }
    setArray(list);
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int num = (rand() % 9) + 1;
            while (isItUsing(num)) {
                num = (rand() % 9) + 1;
            }
            datas[i][j] = num;
        }
    }
    

    for (i = 0;i < datas.size();++i) {
        for (j = 0;j < datas[0].size();++j) {
            if (datas[i][j] == 9) {
                datas[i][j] = -1;
                break;
            }
        }
    }

    print();

}
bool EightPuzzle::isItUsing(int number) {
    vector<vector<int>>  list = getArray();

    for (int i = 0;i < 3;++i) {
        for (int j = 0;j < 3;++j) {
            if (list[i][j] == number) {
                return true;
            }
        }
    }
    return false;
}
void EightPuzzle::goToLeft(const int xCoordinate, const int yCoordinate, const bool flag) {
    vector<vector<int>>  list = getArray();
    int number = list[xCoordinate][yCoordinate];

    if (xCoordinate < 3 && yCoordinate < 3 && list[xCoordinate][yCoordinate - 1] == -1) {
        list[xCoordinate][yCoordinate] = -1;
        list[xCoordinate][yCoordinate - 1] = number;
        setArray(list);
        print();
    }

}
void EightPuzzle::goToRight(const int xCoordinate, const int yCoordinate, const bool flag) {
    vector<vector<int>>  list = getArray();
    int number = list[xCoordinate][yCoordinate];
    if (yCoordinate < 3 && xCoordinate < 3 && list[xCoordinate][yCoordinate + 1] == -1) {
        list[xCoordinate][yCoordinate + 1] = number;
        list[xCoordinate][yCoordinate] = -1;
        setArray(list);
        print();
    }
}
void EightPuzzle::goToDown(const int xCoordinate, const int yCoordinate, const bool flag) {
    vector<vector<int>>  list = getArray();
    int number = list[xCoordinate][yCoordinate];

    if (yCoordinate < 3 && xCoordinate < 2 && list[xCoordinate + 1][yCoordinate] == -1) {
        list[xCoordinate][yCoordinate] = -1;
        list[xCoordinate + 1][yCoordinate] = number;
        setArray(list);
        print();
    }
}
void EightPuzzle::goToUp(const int xCoordinate, const int yCoordinate, const bool flag) {
    vector<vector<int>>  list = getArray();
    int number = list[xCoordinate][yCoordinate];
    if (yCoordinate < 3 && xCoordinate < 3 && list[xCoordinate - 1][yCoordinate] == -1) {
        list[xCoordinate][yCoordinate] = -1;
        list[xCoordinate - 1][yCoordinate] = number;
        setArray(list);
        print();
    }
}
void EightPuzzle::playUser(string directions) {
    int random = -1, oldrandom = -1;
    vector<vector<int>>  Array = getArray();
    /*
    0->Down
    1->Up
    2->Right
    3->Left
    */
    int first;
    first = directions[0] - 48;
    int second = directions[1] - 65;
    cout << "First " << first << endl;
    cout << "Second " << second << endl;
    bool flag1 = false;
    string yeni = directions.erase(0, 3);
    bool flag = true;
    srand(time(NULL));
    int choice;
    if (yeni == "DOWN") {
        goToDown(first, second, flag1);
    }
    else if (yeni == "UP") {
        goToUp(first, second, flag1);
    }
    else if (yeni == "RIGHT") {
        goToRight(first, second, flag1);
    }
    else if (yeni == "LEFT") {
        goToLeft(first, second, flag1);
    }
}
bool EightPuzzle::endGame() {
    int i, j, result = 0;
    int dizi[3][3] = { {1,2,3},{4,5,6},{7,8,-1} };
    vector<vector<int>>  list = getArray();
    for (i = 0;i < 3;++i) {
        for (j = 0;j < 3;++j) {
            if (list[i][j] == dizi[i][j]) {
                ++result;
            }
        }
    }
    bool flag = false;
    if (result == 9) {
        flag = true;
    }

    return flag;
}
EightPuzzle::EightPuzzle() {

}


} // end of namespace