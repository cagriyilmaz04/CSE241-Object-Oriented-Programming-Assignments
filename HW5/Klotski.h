#ifndef KLOTSKI_H
#define KLOTSKI_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "BoardGame2d.h"

using namespace std;


namespace Cagri_Games{

class Klotski : public BoardGame2D {
public:
    void playUser(string move);
    void playUser();
    void playAuto();
    void playAutoAll();
    bool endGame();
    int boardScore();
    void goToLeft(const int xCoordinate, const int yCoordinate, bool flag) override;
    void goToRight(const int xCoordinate, const int yCoordinate, bool flag) override;
    void goToDown(const int x, const int y, bool flag) override;
    void goToUp(const int xCoordinate, const int yCoordinate, bool flag) override;
    Klotski();
    void setScore() override;
    void initialize();
    void print();
    bool checkOutput(string Directions);
private:
    vector<vector<int>> Board;
    int size;
    int Score;
};


} // end of namespace

#endif