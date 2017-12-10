/***************************************************

Name: Yap Yung Seng

ID: 1141128589

Email: yungseng1314@hotmail.com; Phone: 0102032628

***************************************************/




#include "Player.hpp"
#include <iostream>
#include <vector>
using namespace std;
Player::Player(string fname,string lname)
{
    this->fname=fname;
    this->lname=lname;
    score=0;
}

Player::Player(string fname,string lname,int score)
{
    this->fname=fname;
    this->lname=lname;
    this->score=score;
}

void Player::addscore(ListInterface<Question*> *quesList ,int element)
{
    score=score+quesList->retrieve(element)->getpoint();

}

void Player::finalresult()
{
    cout<<fname<<" "<<lname<<", your game is over!"<<endl;
    cout<<"Your final score is "<<score<<" points."<<endl;
    cout<<"Better luck next time!\n\n";
}

int Player::getscore()
{
    return score;
}

string Player::getfname()
{
    return fname;
}

string Player::getlname()
{
    return lname;
}
