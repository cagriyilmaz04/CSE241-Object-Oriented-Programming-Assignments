#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include "BoardGame2d.h"
using namespace std;

namespace Cagri_Games{
void BoardGame2D::playVector(vector <BoardGame2D*> datas){
	int i=0;
	int choice;
	bool flag=true;
	ofstream file("cppoutput.txt");
	for(i=0;i<datas.size();++i){
		while(flag){
			cout << "Computer Play or User (1)/(2)\n";
			if(!(cin>>choice)){
				cout << "Enter a number and it has to be 1 or 2\n";
            cin.clear();
            cin.ignore(10000, '\n');
			
			}else{
				flag=false;
				if(choice==1){
					datas[i]->initialize();
					datas[i]->playAutoAll();
					file << *datas[i];
				}else if(choice==2){
					datas[i]->initialize();
					datas[i]->playUser();
					file << *datas[i];
					
				}
				
				
				
			}
			
		}
		flag=true;
			
	
	}
	
}
	
BoardGame2D::BoardGame2D() {}

ostream& operator<<(ostream& outputStream, BoardGame2D& ourGame) {
    ourGame.print();
    outputStream << "Your Score is " << ourGame.getScore() << endl;
    return outputStream;
}

	
	

}// end of namespace