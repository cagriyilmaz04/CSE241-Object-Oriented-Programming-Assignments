#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
 
using namespace std;
enum class Situation { empty, peg, space };
class PegSolitaire {
public:
	class Cell {
	public:
		void setCoordinate();
		Cell(Situation name);
		Cell();
		Cell(int x, int y, int direction);
		inline	Situation getCell() { return name; }
		inline int getX() { return column; }
		inline int getY() { return row; }
		inline int getDirections() { return direction; }
		void setX(int x) { column = x; }
		void setY(char y) { row = y; }
		void setDirection(char direct) { direction = direct; }
		void setCell(Cell cell);
	private:
		Situation name;
		int column;
		char row;
		char direction;
	};
	PegSolitaire(int typeOfBoard);
	//Default constructor
	PegSolitaire();
	PegSolitaire(string fileName);
	bool comparasion(PegSolitaire other);
	void play();
	void play(Cell cell);
	void setToShape();
	inline void setUserChoice(int number) { userChoice = number; }
	int getPegNumber();
	int getEmptyNumber();
	int getPegNumberThatTakesOut();
	void playGame(int id);
	void display() const;
	void displayAllShape();
	void  moveOn(int x, int y, int directions);
	void writeToFile(const string fileName);
	void readFromFile(const string fileName);
	bool isItSuitable();
	bool checkSituation(int x, int y);
	bool moveToTheRight(const int x, const int y, const int direction);
	bool moveToTheLeft(const int x, const int y, const int direction);
	bool moveToTheUp(const int x, const int y, const int direction);
	bool moveToTheDown(const int x, const int y, const int direction);
	int setWhoPlayGame(int player);
	inline int getUser() { return user; }
	inline void setUser(int User) { user = User; };
	inline void setFlagForComputer(bool value) { flagForComputer = value; }
	inline int getUserChoice() { return userChoice; }
	inline bool getComputerFlag() { return flagForComputer; }
	inline void setPlayFromFile(bool value) { playFromFile = value; }
	void setChoose(bool value) { alreadyChoosen = value; }
	bool getChoose() { return alreadyChoosen; }
	static int returnAllPegs(vector<PegSolitaire> games);
	inline void setBoard(vector <vector<Cell>> temp) { board = temp; }
	inline vector <vector<Cell>> getBoard() { return board; }
	static int gameNum() { return gameNums; }

private:
	static int gameNums;
	vector <vector<Cell>> board;
	int user;
	int userChoice = -1;
	bool flag = true;
	bool flagForComputer = false;
	int pegNumber;
	bool playFromFile = false;
	bool alreadyChoosen = false;
	int emptyNumber;
	int pegNumberThatTakesOut;
};
int PegSolitaire::gameNums = 0;
void PegSolitaire::displayAllShape() {
	vector <vector<Cell>> temp = { {Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::empty),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)} };

	board = temp;
	display();
	cout << "\n";
	vector <vector<Cell>> temp1 = { {Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::empty),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)} };
	board = temp1;
	display();
	cout << "\n";
	vector <vector<Cell>> temp2 = { {Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::empty),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)} };
	board = temp2;
	display();
	cout << "\n";
	vector <vector<Cell>> temp3 = { {Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)},
			{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)},
			{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
			{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::empty),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
			{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
			{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)},
			{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)} };

	board = temp3;
	display();
	cout << "\n";
	vector <vector<Cell>> temp4 =
	{ {Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
	{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
	{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)},
	{Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space)},
	{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::empty),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
	{Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space)},
	{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)},
	{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
	{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)} };

	board = temp4;
	display();
	vector <vector<Cell>> temp5 = {
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::empty),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space)},
		{Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg)}
	};
	board = temp5;
	display();

}
bool PegSolitaire::isItSuitable() {
	unsigned int i = 0, j = 0;
	bool flag = false;
	int x = 0;
	for (i = 0; i < board.size(); ++i) {
		for (j = 0; j < board[i].size(); ++j) {
			PegSolitaire::Cell temp = board[i][j];
			if (temp.getCell() != Situation::space) {
				if (checkSituation(i, j)) {
					j = board[i].size() + 1;
					i = board.size() + 1;
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
bool PegSolitaire::checkSituation(int x, int y) {
	bool flag = false;
	if (getUserChoice() == 6) {
		if ((y >= 4) && (board[x][y].getCell() == Situation::empty && board[x][y - 2].getCell() == Situation::peg && board[x][y - 4].getCell() == Situation::peg)) {
			flag = true;
		}
		else if ((4 >= y) && board[x][y].getCell() == Situation::empty && board[x][y + 2].getCell() == Situation::peg && board[x][y + 4].getCell() == Situation::peg) {
			flag = true;
		}
		else  if ((((x + 2 < board.size() && y - 2 >= 0) && board[x][y].getCell() == Situation::empty && board[x + 1][y - 1].getCell() == Situation::peg && board[x + 2][y - 2].getCell() == Situation::peg) || ((x + 2 < board.size() && y + 1 < board[0].size()) && board[x][y].getCell() == Situation::empty && board[x + 1][y + 1].getCell() == Situation::peg && board[x + 2][y + 2].getCell() == Situation::peg))) {
			flag = true;
		}
		else if (((x >= 2 && y + 1 < board[0].size()) && board[x][y].getCell() == Situation::empty && (board[x - 1][y + 1].getCell() == Situation::peg && board[x - 2][y + 2].getCell() == Situation::peg) || ((x >= 2 && y - 2 >= 0) && board[x][y].getCell() == Situation::empty && board[x - 1][y - 1].getCell() == Situation::peg && board[x - 2][y - 2].getCell() == Situation::peg))) {
			flag = true;
		}
	}
	if (getUserChoice() != 6) {

		if ((y >= 2) && (board[x][y].getCell() == Situation::empty && board[x][y - 1].getCell() == Situation::peg && board[x][y - 2].getCell() == Situation::peg)) {
			flag = true;
		}
		else if ((board[0].size() > y + 2) && board[x][y].getCell() == Situation::empty && board[x][y + 1].getCell() == Situation::peg && board[x][y + 2].getCell() == Situation::peg) {
			flag = true;
		}
		else if ((x < board.size() - 2) && board[x][y].getCell() == Situation::empty && board[x + 1][y].getCell() == Situation::peg && board[x + 2][y].getCell() == Situation::peg) {
			flag = true;
		}
		else if ((x >= 2) && board[x][y].getCell() == Situation::empty && board[x - 1][y].getCell() == Situation::peg && board[x - 2][y].getCell() == Situation::peg) {
			flag = true;
		}
	}
	else {
	}
	return flag;
}
PegSolitaire::Cell::Cell(int x, int y, int directions) :column(x), row(y), direction(directions) {}
PegSolitaire::PegSolitaire() {
	gameNums++;
}
void PegSolitaire::Cell::setCell(Cell cell) {
	name = cell.getCell();
}
PegSolitaire::Cell::Cell(Situation name) : name(name) {}
PegSolitaire::Cell::Cell() {}
bool PegSolitaire::comparasion(PegSolitaire other) {
	int a = getPegNumber();
	int b = other.getPegNumber();
	cout << "First board has " << a << " Second board has " << b << endl;
	return a > b;
}
int PegSolitaire::returnAllPegs(vector<PegSolitaire> games)
{
	int count = 0;
	for (int i = 0; i < games.size(); i++)
		count += games[i].getPegNumber();

	return count;
}
bool PegSolitaire::moveToTheRight(const int x, const int y, const int direction) {
	bool flag = false;
	if (getUserChoice() != 6) {
		if ((y + 2 >= board[x].size())) {
		}
		else if (board[x][y].getCell() == Situation::peg && board[x][y + 1].getCell() == Situation::peg && board[x][y + 2].getCell() == Situation::empty) {
			board[x][y + 2].setCell(Cell(Situation::peg));
			board[x][y + 1].setCell(Cell(Situation::empty));
			board[x][y].setCell(Cell(Situation::empty));
			flag = true;
			if (getUser() == 1) {
				cout << "Moved Successfully\n";
			}
			else { setFlagForComputer(true); }
		}
		else {
			if (getUser() == 1) {
				cerr << "Cannot Move\n";
			}
			else {
				setFlagForComputer(false);
			}
		}
	}
	else {
		if (y <= 4 && (board[x][y + 4].getCell() == Situation::empty && board[x][y + 2].getCell() == Situation::peg && board[x][y].getCell() == Situation::peg)) {
			board[x][y + 4] = Cell(Situation::peg);
			board[x][y + 2] = Cell(Situation::empty);
			board[x][y] = Cell(Situation::empty);
			flag = true;
			if (getUser() == 1) {
				cout << "Moved Successfully\n";
			}
			else { setFlagForComputer(true); }
		}
		else {
			if (getUser() == 1) {
				cerr << "Cannot Move\n";
			}
			else { setFlagForComputer(false); }
		}
	}
	return flag;
}
bool PegSolitaire::moveToTheLeft(const int x, const int y, const int direction) {
	bool flag = false;
	if (getUserChoice() != 6) {
		if (!(y > 2)) {
		}
		else if (((y >= 2)) && (board[x][y].getCell() == Situation::peg && board[x][y - 1].getCell() == Situation::peg && board[x][y - 2].getCell() == Situation::empty)) {

			board[x][y - 2] = Cell(Situation::peg);
			board[x][y - 1] = Cell(Situation::empty);
			board[x][y] = Cell(Situation::empty);
			flag = true;
			if (getUser() == 1) {
				cout << "Moved Successfully\n";
			}
			else { setFlagForComputer(true); }
		}
		else {
			if (getUser() == 1) {
				cerr << "Cannot move\n";
			}
			else {
				setFlagForComputer(false);
			}
		}
	}
	else {
		if ((y >= 4) && board[x][y - 4].getCell() == Situation::empty && board[x][y - 2].getCell() == Situation::peg && board[x][y].getCell() == Situation::peg) {
			board[x][y] = Cell(Situation::empty);
			board[x][y - 2] = Cell(Situation::peg);
			board[x][y - 4] = Cell(Situation::peg);
			flag = true;
			if (getUser() == 1) {
				cout << "Moved Successfully\n";
			}
			else { setFlagForComputer(true); }

		}
		else {
			if (getUser() == 1) {
				cerr << "Cannot move\n";
			}
			else {
				setFlagForComputer(false);
			}

		}
	}
	return flag;
}
bool PegSolitaire::moveToTheDown(const int x, const int y, const int direction) {
	bool flag = false;
	if (getUserChoice() != 6) {
		if (x + 1 >= (board[x].size() - 1)) {}
		else if (x + 2 < board.size() && board[x][y].getCell() == Situation::peg && board[x + 1][y].getCell() == Situation::peg && board[x + 2][y].getCell() == Situation::empty) {
			board[x + 2][y] = Cell(Situation::peg);
			board[x + 1][y] = Cell(Situation::empty);
			board[x][y] = Cell(Situation::empty);
			flag = true;
			if (getUser() == 1) {
				cout << "Successfully\n";
			}
			else { setFlagForComputer(true); }
		}
		else {
			flag = false;
			if (getUser() == 1) {
				cerr << "Cannot move\n";
			}
			else {
				setFlagForComputer(false);
			}
		}
	}
	else {
		if ((board.size() > x + 2 && y >= 2) && board[x][y].getCell() == Situation::peg && board[x + 1][y - 1].getCell() == Situation::peg && board[x + 2][y - 2].getCell() == Situation::empty) {
			board[x + 2][y - 2] = Cell(Situation::peg);
			board[x + 1][y - 1] = Cell(Situation::empty);
			board[x][y] = Cell(Situation::empty);
			flag = true;
			if (getUser() == 1) {
				cout << "Successfully\n";
			}
			else { setFlagForComputer(true); }
		}
		else  if ((board.size() > x + 2 && y >= 2) && board[x][y].getCell() == Situation::peg && board[x + 1][y + 1].getCell() == Situation::peg && board[x + 2][y + 2].getCell() == Situation::empty) {
			board[x + 2][y + 2] = Cell(Situation::peg);
			board[x + 1][y + 1] = Cell(Situation::empty);
			board[x][y] = Cell(Situation::empty);
			flag = true;
			if (getUser() == 1) {
				cout << "Successfully\n";
			}
			else { setFlagForComputer(false); }
		}
		else {
			flag = false;
			if (getUser() == 1) {
				cerr << "Cannot move\n";
			}
			else {
				setFlagForComputer(false);
			}
		}
	}
	return flag;
}
bool PegSolitaire::moveToTheUp(const int x, const int y, const int direction) {
	bool flag = false;
	if (getUserChoice() != 6) {
		if (!(x > 1)) {}
		else if ((board[x][y].getCell() == Situation::peg && board[x - 1][y].getCell() == Situation::peg && board[x - 2][y].getCell() == Situation::empty)) {
			board[x - 2][y] = Cell(Situation::peg);
			board[x - 1][y] = Cell(Situation::empty);
			board[x][y] = Cell(Situation::empty);
			flag = true;
			if (getUser() == 1) {
				cout << "Moved Successfully\n";
			}
			else { setFlagForComputer(true); }
		}
		else {
			flag = false;
			if (getUser() == 1) {
				cerr << "Cannot move\n";
			}

		}
	}
	else {
		if (!(x > 1)) {}
		else if ((x >= 2 && y + 1 < board[0].size()) && (board[x][y].getCell() == Situation::peg && board[x - 1][y + 1].getCell() == Situation::peg && board[x - 2][y + 2].getCell() == Situation::empty)) {
			board[x - 2][y + 2] = Cell(Situation::peg);
			board[x - 1][y + 1] = Cell(Situation::empty);
			board[x][y] = Cell(Situation::empty);
			flag = true;
			//Determine user or computer
			if (getUser() == 1) {
				cout << "Moved Successfully\n";
			}
			else { setFlagForComputer(true); }
		}
		else if ((x >= 2 && y - 2 >= 0) && (board[x][y].getCell() == Situation::peg && board[x - 1][y - 1].getCell() == Situation::peg && board[x - 2][y - 2].getCell() == Situation::empty)) {
			board[x - 2][y - 2] = Cell(Situation::peg);
			board[x - 1][y - 1] = Cell(Situation::empty);
			board[x][y] = Cell(Situation::empty);
			flag = true;
			if (getUser() == 1) {
				cout << "Moved Successfully\n";
			}
			else { setFlagForComputer(true); }
		}
		else {
			if (getUser() == 1) {
				cerr << "Cannot move\n";
			}
			else {
				setFlagForComputer(false);
			}


			flag = false;
		}
	}
	return flag;
}
void PegSolitaire::display() const {
	int i, j;
	int a = 0;
	cout << "  ";
	while (a < board[0].size()) {
		cout << char('a' + a) << ' ';
		++a;
	}
	cout << "\n";
	for (i = 0;i < board.size();++i) {
		cout << i << ' ';
		for (j = 0;j < board[i].size();++j) {
			PegSolitaire::Cell temp = board[i][j];
			if (temp.getCell() == Situation::empty) {
				cout << '.' << " ";
			}
			if (temp.getCell() == Situation::space) {
				cout << ' ' << " ";
			}
			if (temp.getCell() == Situation::peg) {
				cout << 'P' << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}
int PegSolitaire::setWhoPlayGame(int player) {
	cin >> player;
	user = player;
	return player;
}
void PegSolitaire::play() {
	bool Flag = true;
	int x, y, c;
	if (getUser() == 3) {

	}
	if (getUser() == 2) {
		display();
		//setToShape();
	}
	while (Flag) {
		if (isItSuitable()) {
			PegSolitaire::Cell cagri;
			x = rand() % (getBoard().size());
			y = rand() % (getBoard()[x].size());
			c = rand() % 4;
			moveOn(x, y, c);
			if (flagForComputer == true) {
				display();
			}
			else {
			}
		}
		else {
			Flag = false;
			getPegNumberThatTakesOut();
		}
	}
}
void PegSolitaire::play(Cell cell) {
	if (isItSuitable()) {
		auto y = cell.getY();
		decltype(y) direct = cell.getDirections();
		int directions;
		if (direct == 'R') {
			directions = 0;
		}
		else if (direct == 'L') {
			directions = 1;
		}
		else if (direct == 'D') {
			directions = 3;
		}
		else if (direct == 'U') {
			directions = 2;
		}
		int ay = y - 65;
		moveOn(cell.getX(), ay, directions);
		display();
		cout << "Do you want to save board that you are currently playing yes(Y) \\ no(N)\n";
		char a;
		bool flag1 = true;
		do {
			cin >> a;
			if (a != 'Y' && a != 'N') {
				cerr << "You must enter Y or N\n";
			}
			else {
				flag1 = false;
			}

		} while (flag1);

		if (a == 'Y') {
			string file;
			cout << "Enter the filename\n";
			cin >> file;
			writeToFile(file);
		}
	}
}
void PegSolitaire::writeToFile(const string fileName) {
	ofstream myFile;
	myFile.open(fileName);
	int i = 0, j = 0, z = 0;
	string line;
	vector <vector<char>> newStr;
	for (i = 0;i < board.size();++i) {
		vector <char> temp;
		newStr.push_back(temp);
		for (j = 0;j < board[i].size();++j) {
			PegSolitaire::Cell tempClass = board[i][j];
			if (tempClass.getCell() == Situation::peg) {
				newStr[i].push_back('P');
			}
			if (tempClass.getCell() == Situation::empty) {
				newStr[i].push_back('.');
			}
			if (tempClass.getCell() == Situation::space) {
				newStr[i].push_back(' ');
			}
		}
	}
	for (i = 0;i < newStr.size();++i) {
		vector<char> temp;
		for (int z = 0;z < newStr[i].size();++z) {
			temp.push_back(newStr[i][z]);
		}
		for (int z = 0;z < temp.size();++z) {
			myFile << temp[z];
		}
		myFile << "\n";
	}
	myFile << getUserChoice();
	cout << "Saved Successfully\n";
	myFile.close();
}
void PegSolitaire::playGame(int id) {
	cout << "Who plays the game User (1) Computer(2)\n";
	int decided;

	bool flag = true;
	do {
		if (!(cin >> decided)) {
			cerr << "You need to enter a numeric value. It has to be 1 or 2\n";
			cin.clear();
			cin.ignore(100000, '\n');
		}
		else if (!(decided == 1 || decided == 2)) {
			cerr << "1 or 2\n";
		}
		else {
			flag = false;
			setUser(decided);
		}
	} while (flag);
	if (id == 1) {}
	else if (id == 2) {
		setToShape();
	}
	if (getUser() == 1) {
		Cell cellDetail;
		flag = true;
		int a;
		char b, c;
		if (isItSuitable()) {
			cout << "Coordinate x\n";
			bool flag = true;
			do {
				if (!(cin >> a)) {
					cerr << "Enter a number and it has to be between 0 and " << board.size() << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}
				else if (a >= board.size()) {
					cerr << "The number that you entered needs to be between 0 and " << board.size() << endl;
				}
				else {
					flag = false;
				}

			} while (flag);

			cout << "Coordinate y\n";
			flag = true;
			do {
				cin >> b;
				if (!(b >= 'A' && b <= 'Z')) {
					cerr << "You need to enter Uppercase Letter\n";
				}
				if (b >= 'A' && b <= char((int)'A' + board.size())) {
					flag = false;
				}

			} while (flag);
			flag = true;
			cout << "Enter direction\n";
			do {
				cin >> c;
				if (!(c >= 'A' && c <= 'Z')) {
					cerr << "You need to enter uppercase";
				}
				if (c != 'D' || c != 'U' || c != 'L' || c != 'R') {
					flag = false;
				}

			} while (flag);
			cellDetail.setX(a);
			cellDetail.setY(b);
			cellDetail.setDirection(c);
			play(cellDetail);

		}
		else {
			flag = false;
		}

	}
	else if (getUser() == 2) {
		play();
	}
}
void PegSolitaire::Cell::setCoordinate() {
	cout << "Enter a column\n";
	cin >> column;
	cout << "Enter a row\n";
	cin >> row;
	cout << "Enter a directions\n";
	cin >> direction;
}
void PegSolitaire::setToShape() {

	vector <vector<Cell>> temp = { {Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::empty),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space)},
	{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)} };
	board = temp;
	vector <vector<Cell>> temp1 = { {Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::empty),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)} };
	board = temp1;
	vector <vector<Cell>> temp2 = { {Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::empty),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)} };
	board = temp2;
	vector <vector<Cell>> temp3 = { {Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)},
			{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)},
			{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
			{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::empty),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
			{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
			{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)},
			{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)} };

	board = temp3;
	cout << "\n";
	vector <vector<Cell>> temp4 =
	{ {Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
	{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
	{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)},
	{Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space)},
	{Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::empty),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg)},
	{Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space)},
	{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)},
	{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
	{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)} };

	board = temp4;
	vector <vector<Cell>> temp5 = {
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::empty),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::space)},
		{Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space)},
		{Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg),Cell(Situation::space),Cell(Situation::peg)}
	};
	board = temp5;
	int val;
	if (getUserChoice() == -1) {
		displayAllShape();
		cout << "Choose a map\n";
		bool flag = true;
		do {
			if (!(cin >> val)) {
				cerr << "Enter a number and it has to be between 1 and 6\n";
				cin.clear();
				cin.ignore(100000, '\n');
			}
			else if (!(val >= 1 && val <= 6)) {
				cerr << "Enter a value that is between 1-6\n";
			}
			else {
				flag = false;
			}


		} while (flag);

		setUserChoice(val);
	}
	else {
	}

	if (getChoose() == false) {
		if (getUserChoice() == 1) {

			setBoard(temp);
		}
		else if (getUserChoice() == 2) {
			setBoard(temp1);
		}
		else if (getUserChoice() == 3) {
			setBoard(temp2);
		}
		else if (getUserChoice() == 4) {
			setBoard(temp3);
		}
		else if (getUserChoice() == 5) {
			setBoard(temp4);
		}
		else if (getUserChoice() == 6) {
			setBoard(temp5);
		}
		else {
			board.resize(0);
		}
	}
}
void PegSolitaire::moveOn(int x, int y, int direction) {
	switch (direction)
	{
	case 0:
		moveToTheRight(x, y, direction);
		break;
	case 1:
		moveToTheLeft(x, y, direction);
		break;
	case 2:
		moveToTheUp(x, y, direction);
		break;
	case 3:
		moveToTheDown(x, y, direction);
		break;
	default:
		break;
	}
}
void PegSolitaire::readFromFile(const string fileName) {
	string text;
	ifstream MyReadFile;
	int i = 0, j = 0;
	board.clear();
	MyReadFile.open(fileName);
	if (MyReadFile) {
		while (getline(MyReadFile, text)) {
			vector <Cell> temp;
			board.push_back(temp);
			while (j < text.length()) {
				if (text[j] == 'P') {
					board[i].push_back(Cell(Situation::peg));
				}
				else if (text[j] == ' ') {
					board[i].push_back(Cell(Situation::space));
				}
				else if (text[j] == '.') {
					board[i].push_back(Cell(Situation::empty));
				}
				else {
					setUserChoice(text[j] - 48);

				}
				++j;
			}
			j = 0;
			++i;
		}
		MyReadFile.close();
		board.pop_back();
	}
	else {
		cerr << "There is no file\n";
	}
}
int PegSolitaire::getPegNumber() {
	int count = 0;
	int i, j;
	for (i = 0;i < board.size();++i) {
		for (j = 0;j < board[i].size();++j) {
			if (board[i][j].getCell() == Situation::peg) {
				++count;
			}
		}
	}
	pegNumber = count;
	return pegNumber;
}
int PegSolitaire::getEmptyNumber() {
	int count = 0;
	int i, j;
	for (i = 0;i < board.size();++i) {
		for (j = 0;j < board[i].size();++j) {
			if (board[i][j].getCell() == Situation::empty) {
				++count;
			}
		}
	}
	emptyNumber = count;
	return emptyNumber;

}
int PegSolitaire::getPegNumberThatTakesOut() {
	int countEmpty = 0;
	int i, j;
	for (i = 0;i < board.size();++i) {
		for (j = 0;j < board[i].size();++j) {
			if (board[i][j].getCell() == Situation::empty) {
				++countEmpty;
			}
		}
	}
	pegNumberThatTakesOut = countEmpty - 1;
	return pegNumberThatTakesOut;
}
PegSolitaire::PegSolitaire(string fileName) {
	readFromFile(fileName);
	display();
	setFlagForComputer(true);

}
PegSolitaire::PegSolitaire(int boardType) {

	setUserChoice(boardType);
	setToShape();
	gameNums = getPegNumber();
	
	display();
}

void helper(vector <PegSolitaire>& Arr) {
	bool flag = true;
	cout << "Enter value\n";
	int val = 0;
	int sayi;
	int indeks;
	int fileIndeks = -1;
	bool flag_for_cin = true;
	do {
		cout << "\n0-)Play Game That From a File\n1-)Play Game That Random Value\n2-)Play a game that give another filename\n3-)Play a game that you enter a filename\n4-)Play a game to choose a board\n5-)Compare\n6-)Exit\n";
		do {
			if (!(cin >> sayi)) {

				cerr << "You need to enter a numberic value and it has to be between 0 and 5\n";
				cin.clear();
				cin.ignore(100000, '\n');
			}
			else if (!(sayi >= 0 && sayi <= 6)) {
				cerr << "Enter a value and it has to be between 0-6\n";
			}
			else {
				flag_for_cin = false;
			}

		} while (flag_for_cin);
		cout << "\n";
		if (sayi == 0) {
			Arr[sayi].display();
			Arr[sayi].playGame(1);
		}
		if (sayi == 1) {
			Arr[sayi].display();
			Arr[sayi].playGame(1);
			Arr[sayi].setChoose(true);
		}
		if (sayi == 2) {
			Arr[sayi].display();
			Arr[sayi].playGame(1);
		}
		if (sayi == 3) {
			string cagri;
			cout << "Enter a filename\n";
			cin >> cagri;
			if (fileIndeks == -1) {
				
				Arr.push_back(PegSolitaire(cagri));
				Arr[Arr.size() - 1].playGame(1);
				fileIndeks = Arr.size() - 1;
			}
			else {
				Arr.erase(Arr.begin() + fileIndeks);
				Arr.push_back(PegSolitaire(cagri));
				Arr[Arr.size() - 1].playGame(1);
				fileIndeks = Arr.size() - 1;
			}
			
		}
		if (sayi == 4) {
			if (val == 0) {

				Arr.push_back(PegSolitaire());
				indeks = Arr.size() - 1;
				Arr[Arr.size() - 1].setToShape();
				Arr[Arr.size() - 1].setChoose(true);
				val = 1;
			}
			else if (val == 1) {
				cout << "Do you want to change board yes(Y) no(N)\n";
				char decided;
				cin >> decided;
				if (decided == 'N') {

				}
				else if (decided == 'Y') {
					Arr.erase(Arr.begin()+indeks);
					Arr.push_back(PegSolitaire());
					Arr[Arr.size() - 1].setToShape();
					Arr[Arr.size() - 1].setChoose(true);
					val = 1;
				}

			}
			Arr[Arr.size() - 1].playGame(1);
			Arr[Arr.size() - 1].display();
		}
		if (sayi == 5) {
			cout << "Compare\n";
			int first, second;
			cout << "Which board do you want to prefer\n";
			cin >> first;
			while (first>2) {
				cout << "You need to be enter a new value\n";
				cin >> first;
			}
			cout << "Second\n";
			cin >> second;
			while (second>2) {
				cout << "You need to be enter a new value\n";
				cin >> second;
			}
			if (Arr[first].comparasion(Arr[second])) {
				cout << "The first board has more peg than the second one\n";
			}
		}
		if (sayi == 6) {
			flag = false;
			cout << "See You...\n";
		}
		cout << "Total Peg Number in all active games is " << PegSolitaire::returnAllPegs(Arr)<< endl;
	} while (flag);
}
int main() {
	srand(time(NULL));
	vector <PegSolitaire> arr1;
	arr1.push_back(PegSolitaire("shape.txt"));
	arr1.push_back(PegSolitaire(4));
	arr1.push_back(PegSolitaire("shape1.txt"));
	helper(arr1);
	return 0;
}
