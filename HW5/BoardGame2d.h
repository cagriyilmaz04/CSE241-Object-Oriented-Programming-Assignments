#ifndef BOARDGAME_H
#define BOARDGAME_H


#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

namespace Cagri_Games {

class BoardGame2D {
public:
    BoardGame2D();
    //User enters an input
    virtual void playUser(string directions) = 0;
    // This function is overload the above functions
    virtual void playUser() = 0;
    inline int getSize() const { return size; }
    inline int getRow() const { return row; }
    inline int getColumn() const { return column; }
    inline void setSize(int Size) { this->size = Size; }
    inline int getScore() { return score; }
    virtual void setScore() = 0;
    virtual bool endGame() = 0;
    friend ostream& operator <<(ostream& outputStream, BoardGame2D& ourGame);
    static void playVector(vector <BoardGame2D*> datas);
    virtual void goToLeft(const int xCoordinate, const int yCoordinate, bool flag) = 0;
    virtual void goToRight(const int xCoordinate, const int yCoordinate, bool flag) = 0;
    virtual void goToDown(const int x, const int y, bool flag) = 0;
    virtual void goToUp(const int xCoordinate, const int yCoordinate, bool flag) = 0;
    virtual void initialize() = 0;
    virtual void print() = 0;
    //For computer this functions proves one move
    virtual void playAuto() = 0;
    //This function starts playAuto and finish the game is over
    virtual void playAutoAll() = 0;
    virtual int boardScore() = 0;
protected:
    int size;
    int row;
    int column;
    int score;
    vector <BoardGame2D*> data;

};


} // end of namespace

#endif