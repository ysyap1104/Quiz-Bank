/***************************************************

Name: Yap Yung Seng

ID: 1141128589

Email: yungseng1314@hotmail.com; Phone: 0102032628

***************************************************/




#ifndef HIGHSCORE_HPP
#define HIGHSCORE_HPP
#include <string>
#include <iostream>
using namespace std;
class HighScore
{
private:
    string Fname;
    string Lname;
    int Mark;
public:
    void setFname(string Fname);
    void setLname(string Lname);
    void setMark(int Mark);
    string getFname();
    string getLname();
    int getMark();
    void displayData();
};






#endif









