/***************************************************

Name: Yap Yung Seng

ID: 1141128589

Email: yungseng1314@hotmail.com; Phone: 0102032628

***************************************************/






#ifndef QUESTION_HPP
#define QUESTION_HPP
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Question
{
protected:
    string ques;
    int point;
    string ans;
    string quesType;
    int numChoice;
public:
    virtual void display(int i)=0;				//display question. If MC question type , it will print the choices too
    virtual string getChoicesList(int i);
    void checkans(string input1,char section);	//check the user answer with the answer in txtfile
    int getpoint();						//return point for each question
	string getans();							//return ans fdr each question
	string getquesType();
	string getques();
	int getnumChoice();
	void setQues(string ques);
	void setPoint(int point);
	void setAns(string ans);
	void setQuesType(string quesType);
	void setnumChoices(int numChoice);
	virtual void setMCchoices(vector <string> &choicesList);
};


#endif
