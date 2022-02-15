#ifndef PEGSOLITAIRE_H
#define PEGSOLITAIRE_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "BoardGame2d.h"

using namespace std;

namespace Cagri_Games{

class PegSolitaire : public BoardGame2D {

public:
    PegSolitaire();
    void initialize();
    void playUser(string directions) override;
    void playUser() override final;
    inline int getSize() const { return size; }
    inline int getRow() const { return row; }
    inline int getColumn() const { return column; }
    inline vector<vector<int>> getArray() const { return datas; }
    inline void setArray(vector<vector<int>> dizi) { this->datas = dizi; }
    inline void setRow(int Row) { this->row = Row; }
    inline void setColumn(int Column) { this->column = Column; }
    inline void setChoice(int choice) { this->userChoice = choice; }
    //To choose a board
    inline int getChoice() const { return userChoice; }
    bool checkSituation(const int xCoordinate, const int yCoordinate) const;
    bool checkOutput(string directions) const;
    void setScore() override;
    bool endGame()override;
    void goToLeft(const int xCoordinate, const int yCoordinate, bool flag) override;
    void goToRight(const int xCoordinate, const int yCoordinate, bool flag) override;
    void goToDown(const int x, const int y, bool flag) override;
    void goToUp(const int xCoordinate, const int yCoordinate, bool flag) override;
    void print() override;
    void playAuto() ;
    inline bool getFlag() { return flag; }
    inline void setFlag(bool Flag) { this->flag = Flag; }
    void playAutoAll() final;
    int boardScore();
private:
    int userChoice;
    vector<vector<int>> datas;
    bool flag;

};


} // end of namespace

#endif