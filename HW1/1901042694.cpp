#include <iostream>
#include <vector>
#include <ctime> // Rand number 
using namespace std;
//Each board has a space. Because of this, I added to space our enum class to indicate all board situation.
enum class Situation {
    empty, peg, space
};
//The first six functions make our all shapes
vector <vector<Situation>> makeVectorShape1();
vector <vector<Situation>> makeVectorShape2();
vector  <vector<Situation>> makeVectorShape3();
vector  <vector<Situation>> makeVectorShape4();
vector <vector<Situation>> makeVectorShape5();
vector <vector<Situation>> makeVectorShape6();
//This function shows all boards. Afterwards , it shows only one board that we choose
void display(vector <vector<Situation>>& temp, int sayi);
//This function checks whether our user can move any direction
bool isItSuitable(vector <vector<Situation>>& temp, const int boardNumber);
//This function is our most important function that is called from main function
void playTheGame();
//The first 4 functions ease to job of moveOn Function and check 4 directions
bool moveToTheRight(vector <vector <Situation>>& arr1, int xCoord, int yCoord, const int board, const int player, bool& flag);
bool moveToTheLeft(vector <vector <Situation>>& arr1, int xCoord, int yCoord, const int board, const int player, bool& flag);
bool moveToTheUp(vector <vector <Situation>>& arr1, int xCoord, int yCoord, const int board, const int player, bool& flag);
bool moveToTheDown(vector <vector <Situation>>& arr1, int xCoord, int yCoord, const int board, const int player, bool& flag);
//This function holds all directions about movement and this function has 4 function in body
void moveOn(vector <vector <Situation>>& arr1, int xCoord, int yCoord, int directions, int boardNumber, const int player, bool& flag);
//This is our helper function to IsItSuitable Function
bool checkSituation(vector <vector <Situation>>& arr1, int x, int y, const int value);
// This function calculates how many peg do we have.
void checkTheWin(const vector <vector<Situation>> arr1, int& number);
//This function shows all shape and user choose one of them. This function controls valid input.
void decidedToShape(vector <vector <Situation>>& arr1, int& board);

int main() {
    srand(time(NULL));
    playTheGame();
}
vector <vector<Situation>> makeVectorShape1() {
    vector <vector<Situation>> arr1 = {
    {Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space},
    {Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::space},
    {Situation::peg,Situation::peg,Situation::peg,Situation::empty,Situation::peg,Situation::peg,Situation::peg},
    {Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg},
    {Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg},
    {Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::space},
    {Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space}
    };
    return arr1;
}
vector <vector<Situation>> makeVectorShape2() {
    vector <vector<Situation>> arr1 = {
        {Situation::space,Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space,Situation::space},
        {Situation::space,Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space,Situation::space},
        {Situation::space,Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space,Situation::space},
        {Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg},
        {Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::empty,Situation::peg,Situation::peg,Situation::peg,Situation::peg},
        {Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg},
        {Situation::space,Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space,Situation::space},
        {Situation::space,Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space,Situation::space},
        {Situation::space,Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space,Situation::space}
    };

    return arr1;
}
vector  <vector<Situation>> makeVectorShape3() {
    vector <vector<Situation>> newArr = {
        {Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space,Situation::space},
        {Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space,Situation::space},
        {Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space,Situation::space},
        {Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg},
        {Situation::peg,Situation::peg,Situation::peg,Situation::empty,Situation::peg,Situation::peg,Situation::peg,Situation::peg},
        {Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg},
        {Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space,Situation::space},
        {Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space,Situation::space}
    };

    return newArr;
}
vector<vector<Situation>> makeVectorShape4() {
    vector <vector<Situation>> arr1 = {
        {Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space},
        {Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space},
        {Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg},
        {Situation::peg,Situation::peg,Situation::peg,Situation::empty,Situation::peg,Situation::peg,Situation::peg},
        {Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg},
        {Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space},
        {Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space},
    };
    return arr1;
}
vector <vector<Situation>> makeVectorShape5() {
    vector <vector<Situation>> arr1 = { {Situation::space,Situation::space,Situation::space,Situation::space,Situation::peg,Situation::space,Situation::space,Situation::space,Situation::space},
    {Situation::space,Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space,Situation::space},
    {Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space},
    {Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::space},
    {Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::empty,Situation::peg,Situation::peg,Situation::peg,Situation::peg},
    {Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::space},
    {Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space},
    {Situation::space,Situation::space,Situation::space,Situation::peg,Situation::peg,Situation::peg,Situation::space,Situation::space,Situation::space} ,
    {Situation::space,Situation::space,Situation::space,Situation::space,Situation::peg,Situation::space,Situation::space,Situation::space,Situation::space} };
    return arr1;
}
vector <vector<Situation>> makeVectorShape6() {
    vector <vector<Situation>> list = {
        {Situation::space,Situation::space,Situation::space,Situation::space,Situation::empty,Situation::space,Situation::space,Situation::space,Situation::space}
        ,{Situation::space,Situation::space,Situation::space,Situation::peg,Situation::space,Situation::peg,Situation::space,Situation::space,Situation::space},
        {Situation::space,Situation::space,Situation::peg,Situation::space,Situation::peg,Situation::space,Situation::peg,Situation::space,Situation::space},
        {Situation::space,Situation::peg,Situation::space,Situation::peg,Situation::space,Situation::peg,Situation::space,Situation::peg,Situation::space},
        {Situation::peg,Situation::space,Situation::peg,Situation::space,Situation::peg,Situation::space,Situation::peg,Situation::space,Situation::peg} };

    return list;
}
void display(vector<vector<Situation>>& temp, int sayi) {
    int i, j, x = 0, y = 0;
    int a = 0;
    int flag = 0;
    cout << "  ";
    //To show each column as a letter
    while (a < temp[0].size()) {
        cout << char('a' + a) << ' ';
        ++a;
    }
    cout << "\n";
    for (i = 0; i < temp.size(); ++i) {
        cout << i << ' ';
        for (j = 0; j < temp[i].size(); ++j) {
            if (temp[i][j] == Situation::peg) {
                cout << "P ";
                ++x;
            }
            else if (temp[i][j] == Situation::space) {
                cout << "  ";
            }
            else {
                cout << "." << " ";
                ++y;
            }
        }
        cout << "\n";
    }
}
void decidedToShape(vector <vector <Situation>>& arr1, int& choosenBoard) {
    cout << "Choose your board\n";
    bool flagForNumber = true;
    arr1 = makeVectorShape1();
    cout << "\nNumber 1\n";
    display(arr1, 1);
    arr1 = makeVectorShape2();
    cout << "\nNumber 2\n";
    display(arr1, 2);
    arr1 = makeVectorShape3();
    cout << "\nNumber 3\n";
    display(arr1, 3);
    arr1 = makeVectorShape4();
    cout << "\nNumber 4\n";
    display(arr1, 4);
    arr1 = makeVectorShape5();
    cout << "\nNumber 5\n";
    display(arr1, 5);
    arr1 = makeVectorShape6();
    cout << "\nNumber 6\n";
    display(arr1, 6);
    cout << "Enter a number to choose board between 1 and 6" << endl;
    do {

        if (!(cin >> choosenBoard)) {
            cout << "Enter a number and it has to be between 1-6\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if (choosenBoard > 6 || choosenBoard < 1) {
            cout << "Between 1 and 6\n";
        }
    } while (!(choosenBoard >= 1 && choosenBoard <= 6));
    if (choosenBoard == 1) { arr1 = makeVectorShape1(); }
    else if (choosenBoard == 2) { arr1 = makeVectorShape2(); }
    else if (choosenBoard == 3) { arr1 = makeVectorShape3(); }
    else if (choosenBoard == 4) { arr1 = makeVectorShape4(); }
    else if (choosenBoard == 5) { arr1 = makeVectorShape5(); }
    else if (choosenBoard == 6) { arr1 = makeVectorShape6(); }
}
void playTheGame() {
    vector <vector <Situation>> arr1;
    bool flag = true, flagForNumber = true, flagForComputerMove = false;
    int controller, x, y, direction, choosenBoard, checkValue = 0;
    char xCoordinate, yCoordinate, Directions;
    bool flagForCoordinateX = true;
    // Variable flagForComputerMove controls whether if random value valid to move. If it is true , we will see updated board.
    decidedToShape(arr1, choosenBoard);
    display(arr1, choosenBoard);
    bool checkController = true;
    //Initialize 0 because Enter the while loop
    controller = 0;
    bool flagControl = true;
    //CHECK ALL VALUE 
    cout << "Who play this game User(1) Computer(2)" << endl;
    do {
        if (!(cin >> controller)) {
            cout << "Please enter a numeric\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }else if (!(controller ==1|| controller ==2)) {
            cout << "Need to be 1 or 2 "<< endl;
        }
        else {
            flagControl = false;
        }
    } while (flagControl);
    while (flag) {
        if (isItSuitable(arr1, choosenBoard)) {
            if (controller == 1) {
                cout << "Enter y and x coordinate and Direction" << endl;
                cout << "Enter y coordinate\n";
                cin >> yCoordinate;
                while (!(yCoordinate >= 'A' && yCoordinate <= char(arr1[0].size() + 'A'))) {
                    cout << "Between A and "<< char((arr1[0].size()-1)+'A')<< " "<<endl;
                    cin >> yCoordinate;
                }
                cout << "Enter x Coordinate\n";
                do {
                    if (!(cin >> x)) {
                        cout << "Please enter a numeric\n";
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }if (x > arr1.size()) {
                        cout << "Need to be less than  " << arr1.size()<< endl;
                    }
                    else {
                        flagForCoordinateX = false;
                    }
                } while (flagForCoordinateX);
                cout << "Enter Directions\n";
                cin >> Directions;
                while (!(Directions == 'L' || Directions == 'R' || Directions == 'U' || Directions == 'D')) {
                    cout << "Your direction needs to be L or R or U or D\n";
                    cin >> Directions;

                }
                y = yCoordinate - 65;
                switch (Directions) {
                case 'D':
                    direction = 3;
                    break;
                case 'L':
                    direction = 1;
                    break;
                case 'R':
                    direction = 0;
                    break;
                case 'U':
                    direction = 2;
                    break;
                default:
                    cout << "Wrong Directions\n";
                    break;
                }

                moveOn(arr1, x, y, direction, choosenBoard, controller, flagForComputerMove);
                display(arr1, choosenBoard);
            }
            else if (controller == 2) {
                //Random value for coordinate x y and directions
                x = rand() % arr1.size();
                y = rand() % arr1[x].size();
                direction = rand() % 4;
                //Convert to char
                if (direction == 0) {
                    Directions = 'R';
                }
                else if (direction == 1) {
                    Directions = 'L';
                }
                else if (direction == 2) {
                    Directions = 'U';
                }
                else if (direction == 3) {
                    Directions = 'D';
                }

                yCoordinate = char(y + 'A');

                moveOn(arr1, x, y, direction, choosenBoard, controller, flagForComputerMove);

                if (flagForComputerMove == true) {
                    cout << yCoordinate << " " << x << " " << Directions << endl;
                    display(arr1, choosenBoard);
                    //To set back if we dont do this our value will be always true 
                    flagForComputerMove = false;
                }
            }

        }
        else {
            flag = false;
        }
    }
    //This time, this function calculates how many peg do we have in the end to learn points.
    checkTheWin(arr1, checkValue);
    cout << "No more legal moves. " << " " << "Your score is " << checkValue << endl;
}
bool isItSuitable(vector <vector<Situation>>& arr1, const int value) {
    unsigned int i = 0, j = 0;
    bool flag = false;
    int x = 0;
    for (i = 0; i < arr1.size(); ++i) {
        for (j = 0; j < arr1[i].size(); ++j) {
            if (arr1[i][j] != Situation::space) {
                if (checkSituation(arr1, i, j, value)) {
                    j = arr1[i].size() + 1;
                    i = arr1.size() + 1;
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
bool checkSituation(vector <vector <Situation>>& arr1, int x, int y, const int value) {
    bool flag = false;
    if (value == 6) {
        if ((y >= 4) && (arr1[x][y] == Situation::empty && arr1[x][y - 2] == Situation::peg && arr1[x][y - 4] == Situation::peg)) {
            flag = true;
        }
        else if ((4 >= y) && arr1[x][y] == Situation::empty && arr1[x][y + 2] == Situation::peg && arr1[x][y + 4] == Situation::peg) {
            flag = true;
        }
        else  if ((((x + 2 < arr1.size() && y - 2 >= 0) && arr1[x][y] == Situation::empty && arr1[x + 1][y - 1] == Situation::peg && arr1[x + 2][y - 2] == Situation::peg) || ((x + 2 < arr1.size() && y + 1 < arr1[0].size()) && arr1[x][y] == Situation::empty && arr1[x + 1][y + 1] == Situation::peg && arr1[x + 2][y + 2] == Situation::peg))) {
            flag = true;
        }
        else if (((x >= 2 && y + 1 < arr1[0].size()) && arr1[x][y] == Situation::empty && (arr1[x - 1][y + 1] == Situation::peg && arr1[x - 2][y + 2] == Situation::peg) || ((x >= 2 && y - 2 >= 0) && arr1[x][y] == Situation::empty && arr1[x - 1][y - 1] == Situation::peg && arr1[x - 2][y - 2] == Situation::peg))) {
            flag = true;
        }
    }
    if (value != 6) {
        if ((y >= 2) && (arr1[x][y] == Situation::empty && arr1[x][y - 1] == Situation::peg && arr1[x][y - 2] == Situation::peg)) {
            flag = true;
        }
        else if ((arr1[0].size() > y + 2) && arr1[x][y] == Situation::empty && arr1[x][y + 1] == Situation::peg && arr1[x][y + 2] == Situation::peg) {
            flag = true;
        }
        else if ((x < arr1.size() - 2) && arr1[x][y] == Situation::empty && arr1[x + 1][y] == Situation::peg && arr1[x + 2][y] == Situation::peg) {
            flag = true;
        }
        else if ((x >= 2) && arr1[x][y] == Situation::empty && arr1[x - 1][y] == Situation::peg && arr1[x - 2][y] == Situation::peg) {
            flag = true;
        }
    }
    else {
    }
    return flag;
}
void moveOn(vector <vector <Situation>>& arr1, int xCoord, int yCoord, int directions, int board, const int player, bool& flag) {
    //This function choose a one case. it depends one directions value that is a parameter
    switch (directions)
    {
    case 0:
        moveToTheRight(arr1, xCoord, yCoord, board, player, flag);
        break;
    case 1:
        moveToTheLeft(arr1, xCoord, yCoord, board, player, flag);
        break;
    case 2:
        moveToTheUp(arr1, xCoord, yCoord, board, player, flag);
        break;
    case 3:
        moveToTheDown(arr1, xCoord, yCoord, board, player, flag);
    default:
        break;
    }
}
bool moveToTheRight(vector <vector <Situation>>& arr1, int x, int y, const int board, const int player, bool& flagComputer) {
    bool flag = false;
    if (board != 6) {
        if ((y + 2 >= arr1[x].size())) {
        }
        else if (arr1[x][y] == Situation::peg && arr1[x][y + 1] == Situation::peg && arr1[x][y + 2] == Situation::empty) {
            arr1[x][y + 2] = Situation::peg;
            arr1[x][y + 1] = Situation::empty;
            arr1[x][y] = Situation::empty;
            flag = true;
            if (player == 1) {
                cout << "Moved Successfully\n";
            }
            else { flagComputer = true; }
        }
        else {
            if (player == 1) {
                cout << "Cannot Move\n";
            }
        }
    }
    else {
        if (y <= 4 && (arr1[x][y + 4] == Situation::empty && arr1[x][y + 2] == Situation::peg && arr1[x][y] == Situation::peg)) {
            arr1[x][y + 4] = Situation::peg;
            arr1[x][y + 2] = Situation::empty;
            arr1[x][y] = Situation::empty;
            flag = true;
            if (player == 1) {
                cout << "Moved Successfully\n";
            }
            else { flagComputer = true; }
        }
        else {
            if (player == 1) {
                cout << "Cannot Move\n";
            }
            else {}
        }
    }
    return flag;
}
bool moveToTheLeft(vector <vector <Situation>>& arr1, int x, int y, const int board, const int player, bool& flagComputer) {
    bool flag = false;
    if (board != 6) {
        if (!(y > 2)) {
        }
        else if (arr1[x][y] == Situation::peg && arr1[x][y - 1] == Situation::peg && arr1[x][y - 2] == Situation::empty && (y - 1 >= 0 && y - 2 >= 0)) {

            arr1[x][y - 2] = Situation::peg;
            arr1[x][y - 1] = Situation::empty;
            arr1[x][y] = Situation::empty;
            flag = true;
            if (player == 1) {
                cout << "Moved Successfully\n";
            }
            else { flagComputer = true; }
        }
        else {
            if (player == 1) {
                cout << "Cannot move\n";
            }
        }
    }
    else {
        if ((y >= 4) && arr1[x][y - 4] == Situation::empty && arr1[x][y - 2] == Situation::peg && arr1[x][y] == Situation::peg) {
            arr1[x][y] = Situation::empty;
            arr1[x][y - 2] = Situation::peg;
            arr1[x][y - 4] = Situation::peg;
            flag = true;
            if (player == 1) {
                cout << "Moved Successfully\n";
            }
            else { flagComputer = true; }

        }
        else {
            if (player == 1) {
                cout << "Cannot move\n";
            }

        }
    }
    return flag;
}
bool moveToTheUp(vector <vector <Situation>>& arr1, int x, int y, int board, const int player, bool& flagComputer) {
    bool flag = false;
    if (board != 6) {
        if (!(x > 1)) {}
        else if ((arr1[x][y] == Situation::peg && arr1[x - 1][y] == Situation::peg && arr1[x - 2][y] == Situation::empty)) {
            arr1[x - 2][y] = Situation::peg;
            arr1[x - 1][y] = Situation::empty;
            arr1[x][y] = Situation::empty;
            flag = true;
            if (player == 1) {
                cout << "Moved Successfully\n";
            }
            else { flagComputer = true; }
        }
        else {
            flag = false;
            if (player == 1) {
                cout << "Cannot move\n";
            }

        }
    }
    else {
        if (!(x > 1)) {}
        else if ((x >= 2 && y + 1 < arr1[0].size()) && (arr1[x][y] == Situation::peg && arr1[x - 1][y + 1] == Situation::peg && arr1[x - 2][y + 2] == Situation::empty)) {
            arr1[x - 2][y + 2] = Situation::peg;
            arr1[x - 1][y + 1] = Situation::empty;
            arr1[x][y] = Situation::empty;
            flag = true;
            //Determine user or computer
            if (player == 1) {
                cout << "Moved Successfully\n";
            }
            else { flagComputer = true; }

        }
        else if ((x >= 2 && y - 2 >= 0) && (arr1[x][y] == Situation::peg && arr1[x - 1][y - 1] == Situation::peg && arr1[x - 2][y - 2] == Situation::empty)) {
            arr1[x - 2][y - 2] = Situation::peg;
            arr1[x - 1][y - 1] = Situation::empty;
            arr1[x][y] = Situation::empty;
            flag = true;
            if (player == 1) {
                cout << "Moved Successfully\n";
            }
            else { flagComputer = true; }
        }
        else {
            if (player == 1) {
                cout << "Cannot move\n";
            }

            flag = false;
        }
    }
    return flag;
}
bool moveToTheDown(vector <vector <Situation>>& arr1, int x, int y, int board, const int player, bool& flagComputer) {
    bool flag = false;
    if (board != 6) {
        if (x + 1 >= (arr1[x].size() - 1)) {}
        else if (arr1[x][y] == Situation::peg && arr1[x + 1][y] == Situation::peg && arr1[x + 2][y] == Situation::empty) {
            arr1[x + 2][y] = Situation::peg;
            arr1[x + 1][y] = Situation::empty;
            arr1[x][y] = Situation::empty;
            flag = true;
            if (player == 1) {
                cout << "Successfully\n";
            }
            else { flagComputer = true; }
        }
        else {
            flag = false;
            if (player == 1) {
                cout << "Cannot move\n";
            }
        }
    }
    else {
        if ((arr1.size() > x + 2 && y >= 2) && arr1[x][y] == Situation::peg && arr1[x + 1][y - 1] == Situation::peg && arr1[x + 2][y - 2] == Situation::empty) {
            arr1[x + 2][y - 2] = Situation::peg;
            arr1[x + 1][y - 1] = Situation::empty;
            arr1[x][y] = Situation::empty;
            flag = true;
            if (player == 1) {
                cout << "Successfully\n";
            }
            else { flagComputer = true; }
        }
        else  if ((arr1.size() > x + 2 && y >= 2) && arr1[x][y] == Situation::peg && arr1[x + 1][y + 1] == Situation::peg && arr1[x + 2][y + 2] == Situation::empty) {
            arr1[x + 2][y + 2] = Situation::peg;
            arr1[x + 1][y + 1] = Situation::empty;
            arr1[x][y] = Situation::empty;
            flag = true;
            if (player == 1) {
                cout << "Successfully\n";
            }
            else { flagComputer = true; }
        }
        else {
            flag = false;
            if (player == 1) {
                cout << "Cannot move\n";
            }
        }
    }
    return flag;
}
void checkTheWin(const vector <vector<Situation>> arr1, int& number) {
    int i, j;
    for (i = 0; i < arr1.size(); ++i) {
        for (j = 0; j < arr1[i].size(); ++j) {
            if (arr1[i][j] == Situation::peg) {
                ++number;
            }
        }
    }

}

