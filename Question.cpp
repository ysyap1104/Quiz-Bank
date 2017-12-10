/***************************************************

Name: Yap Yung Seng

ID: 1141128589

Email: yungseng1314@hotmail.com; Phone: 0102032628

***************************************************/




#include "Question.hpp"
#include <fstream>
#include<string>
#include<iostream>
using namespace std;

string Question::getans()
{
    return ans;
}

void Question::setMCchoices(vector <string> &choicesList)
{

}

void Question::display(int i)
{
}

string Question::getChoicesList(int i)
{
}

void Question::checkans(string input1,char section)
{
    if (section=='E')
    {
        if (input1==ans){
        cout<<"Correct! You get "<<point<<" points."<<endl;
        }
        else{
            cout<<"Incorrect, the answer is "<<ans<<". You lose "<<point<<" points."<<endl;
            point=point*-1;
        }
        cout<<endl;
    }
    else{
        if (section=='P'){
            if (input1==ans){
            cout<<"Correct! You get "<<point<<" points."<<endl;
            }
            else{
                cout<<"Incorrect, the answer is "<<ans<<". You lose "<<point<<" points."<<endl;
            }
            cout<<endl;
        }
    }
}
int Question::getpoint()
{
    return point;
}

string Question::getquesType()
{
    return quesType;
}

string Question::getques()
{
    return ques;
}

int Question::getnumChoice()
{
    return numChoice;
}

void Question::setQues(string ques)
{
    this->ques=ques;
}

void Question::setPoint(int point)
{
    this->point=point;
}

void Question::setAns(string ans)
{
    this->ans=ans;
}

void Question::setQuesType(string quesType)
{
    this->quesType=quesType;
}

void Question::setnumChoices(int numChoice)
{
    this->numChoice=numChoice;
}
