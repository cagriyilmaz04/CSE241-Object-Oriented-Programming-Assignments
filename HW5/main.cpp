#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "BoardGame2d.h"
#include "Klotski.h"
#include "EightPuzzle.h"
#include "PegSolitaire.h"

using namespace std;
using namespace Cagri_Games;


void HelperFunction();

int main() {


    HelperFunction();
    return 0;
}
void HelperFunction() {
    cout << "Welcome Our Game\n";
    vector<BoardGame2D*> data;
	data.push_back(new Klotski);
	data.push_back(new Klotski);
	data.push_back(new PegSolitaire);
	data.push_back(new PegSolitaire);	
	data.push_back(new EightPuzzle);
	data.push_back(new EightPuzzle);
	BoardGame2D::playVector(data);

}