#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "BoardGame2d.h"

using namespace std;

namespace Cagri_Games{

class EightPuzzle :public BoardGame2D {
public:
    EightPuzzle();
    void setScore() override;
    inline int getSize() const { return size; }
    inline int getRow() const { return row; }
    inline int getColumn() const { return column; }
    inline void setArray(vector<vector<int>> newDatas) { datas = newDatas; }
    void goToLeft(const int xCoordinate, const int yCoordinate, const bool flag);
    void goToRight(const int xCoordinate, const int yCoordinate, const bool flag);
    void goToDown(const int xCoordinate, const int yCoordinate, const bool flag);
    void goToUp(const int xCoordinate, const int yCoordinate, const bool flag);
    void playUser(string directions);
    void playUser() final;
    bool endGame();
    void initialize();
    void playAuto() override;
    void playAutoAll() final;
    //When we initialize a board that is random we want to be all values are unique
    bool isItUsing(int number);
    void print();
    int boardScore();
    //To check the input is valid or not
    bool checkOutput(string directions);
    inline vector<vector<int>> getArray() const { return datas; }
    inline int getScore() { return score;}

private:
    vector<vector<int>> datas;
};

} // end of namespace

#endif