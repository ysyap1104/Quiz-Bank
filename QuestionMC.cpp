/***************************************************

Name: Yap Yung Seng

ID: 1141128589

Email: yungseng1314@hotmail.com; Phone: 0102032628

***************************************************/





#include "QuestionMC.hpp"
#include <iostream>
#include <vector>
using namespace std;

void QuestionMC::display(int i)
{
    cout<<"\nQuestion "<<i+1<< "( "<<point<<" Point)"<<endl<<ques<<endl;
    char alpha='A';
    for (int i=0;i<choicesList.size();i++){
        cout<<alpha<<") "<<choicesList[i]<<endl;
        alpha++;
    }
}

string QuestionMC::getChoicesList(int i)
{
    return choicesList[i];
}

void QuestionMC::setMCchoices(vector <string> &choicesList)
{
    this->choicesList=choicesList;
}


