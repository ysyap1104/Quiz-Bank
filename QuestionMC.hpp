/***************************************************

Name: Yap Yung Seng

ID: 1141128589

Email: yungseng1314@hotmail.com; Phone: 0102032628

***************************************************/


#ifndef QUESTIONMC_HPP
#define QUESTIONMC_HPP
#include "Question.hpp"
#include <vector>
using namespace std;
class QuestionMC: public Question
{
    vector <string> choicesList;  //Multiple choices list will be store in this private attribute
public:
    virtual void display(int i);	//display question and choices
    virtual string getChoicesList(int i);
    virtual void setMCchoices(vector <string> &choicesList);
};
#endif
