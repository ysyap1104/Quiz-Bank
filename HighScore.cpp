/***************************************************

Name: Yap Yung Seng

ID: 1141128589

Email: yungseng1314@hotmail.com; Phone: 0102032628

***************************************************/




#include "HighScore.hpp"

void HighScore::setFname(string Fname)
{
    this->Fname=Fname;
}

void HighScore::setLname(string Lname)
{
    this->Lname=Lname;
}

void HighScore::setMark(int Mark)
{
    this->Mark=Mark;
}

void HighScore::displayData()
{
    cout<<Fname<<" "<<Lname<<" "<<Mark;
}

int HighScore::getMark()
{
    return Mark;
}

string HighScore::getFname()
{
    return Fname;
}

string HighScore::getLname()
{
    return Lname;
}
