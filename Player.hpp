/***************************************************

Name: Yap Yung Seng

ID: 1141128589

Email: yungseng1314@hotmail.com; Phone: 0102032628

***************************************************/






#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Question.hpp"
#include <vector>
#include "ListInterface.h"
using namespace std;
class Player
{
    string fname;
    string lname;
    int score;
public:
    Player(string fname,string lname);			//overloaded constructor
    Player(string fname,string lname,int score);	//overloaded constructor (use in storing performance part)
    void addscore(ListInterface<Question*> *quesList ,int element);	//add question point to player score
    void finalresult();		//print player's result
    int getscore();			//return score from player
    string getfname();		//return first name from player
    string getlname();		//return last name from player
};
#endif
