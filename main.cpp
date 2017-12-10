/***************************************************

Name: Yap Yung Seng

ID: 1141128589

Email: yungseng1314@hotmail.com; Phone: 0102032628

***************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "Question.hpp"
#include "QuestionTF.hpp"
#include "QuestionMC.hpp"
#include "QuestionSA.hpp"
#include "Player.hpp"
#include "HighScore.hpp"
#include "ListInterface.h"
#include "LList.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"
#include <cstring>
using namespace std;

bool operator <(HighScore s1,HighScore s2)
{
    return s1.getMark()<s2.getMark();
}

bool operator >(HighScore s1,HighScore s2)
{
    return s1.getMark()>s2.getMark();
}

bool operator <=(HighScore s1,HighScore s2)
{
    return s1.getMark()<=s2.getMark();
}

bool operator >=(HighScore s1,HighScore s2)
{
    return s1.getMark()>=s2.getMark();
}

int main()
{
    string selection;
    int txt_score,num_choice;
    string txt_question,txt_ans,MCchoice;
    vector<string> MCchoicetemp;
    char file_name[20];
    bool returnquiz = false;
    do{
        //---------------------------------------------pass all question to inside temporary file------------------------------------
            system("cls");
            cout<<endl;
            cout<<" ===================================================";
            cout<<"\n  ========== Quiz Bank Program=========="<<endl;
            cout<<" ===================================================\n\n";
            cout<<"1) Add question to database"<<endl;
            cout<<"2) Remove question to database"<<endl;
            cout<<"3) Edit question in database"<<endl;
            cout<<"4) Track high score"<<endl;
            cout<<"5) Start the game"<<endl;
            cout<<"Q) Exit"<<endl;
            cout<<endl<<"Selection:";
            cin>>selection;
            while (selection!="1" && selection !="2" && selection!="3" && selection!="4" && selection!="5" && selection!="Q" && selection!="q")
            {
                cout<<"\nPlease enter a valid selection:";
                cin>>selection;
            }
            char c=selection[0];
            cin.ignore();
            switch (c)
            {
                case '1':
                {
                    string addType,addQues,addAns,type;
                    int addPoint,sum;
                    ifstream fileOpen;
                    cout<<"\nEnter file name:";
                    cin>>file_name;
                    cin.ignore();
                    fileOpen.open(file_name);
                    if (fileOpen.fail())
                    {
                        cout<<"\nInput file failed, please exit the program!";     //file open failed , quit the program
                        exit(1);
                    }
                    Question *InsertQuesPtr;		//create a Question pointer
                    ListInterface<Question*> *InsertList = new LList<Question*>();
                    fileOpen>>sum;
                    for (int i=0;i<sum;i++)
                    {
                        fileOpen>>type;
                        if (type=="TF")
                        {
                            InsertQuesPtr=new QuestionTF;		//Question pointer poting to QuestionTF
                            fileOpen>>txt_score;
                            fileOpen.ignore();
                            getline(fileOpen,txt_question);
                            fileOpen>>txt_ans;
                            InsertQuesPtr->setQuesType("TF");
                            InsertQuesPtr->setQues(txt_question);
                            InsertQuesPtr->setAns(txt_ans);
                            InsertQuesPtr->setPoint(txt_score);
                            InsertList->insert(InsertList->getLength()+1,InsertQuesPtr);	//store only TF type question in this vector (for practice section)

                        }
                        else{
                            if (type=="SA")
                            {
                                InsertQuesPtr=new QuestionSA;
                                fileOpen>>txt_score;
                                fileOpen.ignore();
                                getline(fileOpen,txt_question);
                                fileOpen>>txt_ans;
                                InsertQuesPtr->setQuesType("SA");
                                InsertQuesPtr->setQues(txt_question);
                                InsertQuesPtr->setAns(txt_ans);
                                InsertQuesPtr->setPoint(txt_score);
                                InsertList->insert(InsertList->getLength()+1,InsertQuesPtr);	//store SA type question in this vector

                            }

                            else{
                                if (type=="MC")
                                {
                                    InsertQuesPtr=new QuestionMC;
                                    fileOpen>>txt_score;
                                    fileOpen.ignore();
                                    getline(fileOpen,txt_question);
                                    fileOpen>>num_choice;
                                    fileOpen.ignore();
                                    for (int i=0;i<num_choice;i++){
                                        getline(fileOpen,MCchoice);
                                        MCchoicetemp.push_back(MCchoice);
                                    }
                                    fileOpen>>txt_ans;
                                    InsertQuesPtr->setQuesType("MC");
                                    InsertQuesPtr->setnumChoices(num_choice);
                                    InsertQuesPtr->setQues(txt_question);
                                    InsertQuesPtr->setAns(txt_ans);
                                    InsertQuesPtr->setPoint(txt_score);
                                    InsertQuesPtr->setMCchoices(MCchoicetemp);
                                    InsertList->insert(InsertList->getLength()+1,InsertQuesPtr);	//store MC type question in this vector
                                    MCchoicetemp.clear();

                                }
                            }
                        }
                    }
                    fileOpen.close();
                    sum++;
                    ofstream print;
                    print.open(file_name);
                    print<<sum<<endl;
                    for (int a=1;a<=InsertList->getLength();a++)
                    {
                        if (InsertList->retrieve(a)->getquesType()=="TF" || InsertList->retrieve(a)->getquesType()=="SA")
                        {
                            print<<InsertList->retrieve(a)->getquesType()<<" "<<InsertList->retrieve(a)->getpoint()<<endl;
                            print<<InsertList->retrieve(a)->getques()<<endl;
                            print<<InsertList->retrieve(a)->getans()<<endl;
                        }
                        else{
                            print<<InsertList->retrieve(a)->getquesType()<<" "<<InsertList->retrieve(a)->getpoint()<<endl;
                            print<<InsertList->retrieve(a)->getques()<<endl;
                            print<<InsertList->retrieve(a)->getnumChoice()<<endl;
                            for (int i=0;i<InsertList->retrieve(a)->getnumChoice();i++)
                            {
                                print<<InsertList->retrieve(a)->getChoicesList(i)<<endl;
                            }

                            print<<InsertList->retrieve(a)->getans()<<endl;
                        }
                    }
                    cout<<"\nEnter Question Type (TF/SA/MC):";
                    getline(cin,addType);
                    while (addType!="TF" && addType!="SA" && addType!="MC")
                    {
                        cout<<"\nPlease enter valid type (TF/SA/MC):";
                        getline(cin,addType);
                    }
                    if (addType=="TF" || addType=="SA")
                    {
                        cout<<endl;
                        cout<<"Enter Question :";
                        getline(cin,addQues);
                        cout<<endl;
                        cout<<"Enter Point :";
                        cin>>addPoint;
                        cin.ignore();
                        cout<<endl;
                        cout<<"Enter Answer :";
                        getline(cin,addAns);
                        print<<addType<<" "<<addPoint<<endl;
                        print<<addQues<<endl<<addAns<<endl;
                        print.close();
                        cout<<"\nInsert Successfully !"<<endl;
                    }
                    else{
                        char letter='A';
                        int totalChoice;
                        string choiceString;
                        vector<string>choices;
                        cout<<endl;
                        cout<<"Enter Question :";
                        getline(cin,addQues);
                        cout<<endl;
                        cout<<"Enter number of choices:";
                        cin>>totalChoice;
                        cin.ignore();
                        for (int i=0;i<totalChoice;i++)
                        {
                            cout<<"\nEnter Choice "<<letter<<":";
                            getline(cin,choiceString);
                            choices.push_back(choiceString);
                            letter++;
                        }
                        cout<<"\nEnter Answer:";
                        cin>>addAns;
                        cout<<endl;
                        cout<<"Enter Point:";
                        cin>>addPoint;
                        print<<addType<<" "<<addPoint<<endl;
                        print<<addQues<<endl<<totalChoice<<endl;
                        for (int i=0;i<choices.size();i++)
                        {
                            print<<choices[i]<<endl;
                        }
                        print<<addAns<<endl;
                        print.close();
                        cout<<"\nInsert Successfully !"<<endl;
                    }
                    break;
                }
                case '2':
                {
                    ifstream RemoveOutput;
                    int SumQues;
                    string quesremovetype;
                    cout<<"\nEnter file name:";
                    cin>>file_name;
                    RemoveOutput.open(file_name);
                    if (RemoveOutput.fail())
                    {
                        cout<<"\nInput file failed, please exit the program!";     //file open failed , quit the program
                        exit(1);
                    }
                    int removeInt;
                    Question *removeQuesPtr;		//create a Question pointer
                    ListInterface<Question*> *removeList = new LList<Question*>();
                    RemoveOutput>>SumQues;
                    for (int i=0;i<SumQues;i++)
                    {
                        RemoveOutput>>quesremovetype;
                        if (quesremovetype=="TF")
                        {
                            removeQuesPtr=new QuestionTF;		//Question pointer poting to QuestionTF
                            RemoveOutput>>txt_score;
                            RemoveOutput.ignore();
                            getline(RemoveOutput,txt_question);
                            RemoveOutput>>txt_ans;
                            removeQuesPtr->setQuesType("TF");
                            removeQuesPtr->setQues(txt_question);
                            removeQuesPtr->setAns(txt_ans);
                            removeQuesPtr->setPoint(txt_score);
                            removeList->insert(removeList->getLength()+1,removeQuesPtr);	//store only TF type question in this vector (for practice section)

                        }
                        else{
                            if (quesremovetype=="SA")
                            {
                                removeQuesPtr=new QuestionSA;
                                RemoveOutput>>txt_score;
                                RemoveOutput.ignore();
                                getline(RemoveOutput,txt_question);
                                RemoveOutput>>txt_ans;
                                removeQuesPtr->setQuesType("SA");
                                removeQuesPtr->setQues(txt_question);
                                removeQuesPtr->setAns(txt_ans);
                                removeQuesPtr->setPoint(txt_score);
                                removeList->insert(removeList->getLength()+1,removeQuesPtr);	//store SA type question in this vector

                            }

                            else{
                                if (quesremovetype=="MC")
                                {
                                    removeQuesPtr=new QuestionMC;
                                    RemoveOutput>>txt_score;
                                    RemoveOutput.ignore();
                                    getline(RemoveOutput,txt_question);
                                    RemoveOutput>>num_choice;
                                    RemoveOutput.ignore();
                                    for (int i=0;i<num_choice;i++){
                                        getline(RemoveOutput,MCchoice);
                                        MCchoicetemp.push_back(MCchoice);
                                    }
                                    RemoveOutput>>txt_ans;
                                    removeQuesPtr->setQuesType("MC");
                                    removeQuesPtr->setnumChoices(num_choice);
                                    removeQuesPtr->setQues(txt_question);
                                    removeQuesPtr->setAns(txt_ans);
                                    removeQuesPtr->setPoint(txt_score);
                                    removeQuesPtr->setMCchoices(MCchoicetemp);
                                    removeList->insert(removeList->getLength()+1,removeQuesPtr);	//store MC type question in this vector
                                    MCchoicetemp.clear();

                                }
                            }
                        }
                    }
                    RemoveOutput.close();
                    cout<<"\nEnter question number to remove:";
                    cin>>removeInt;
                    while (removeInt==0 || removeInt>removeList->getLength())
                    {
                        cout<<"\nPlease enter a valid question number:";
                        cin>>removeInt;
                    }
                    removeList->erase(removeInt);
                    ofstream printRemoveOutput;
                    printRemoveOutput.open("sample.txt");
                    printRemoveOutput<<removeList->getLength()<<endl;
                    for (int a=1;a<=removeList->getLength();a++)
                    {
                        if (removeList->retrieve(a)->getquesType()=="TF" || removeList->retrieve(a)->getquesType()=="SA")
                        {
                            printRemoveOutput<<removeList->retrieve(a)->getquesType()<<" "<<removeList->retrieve(a)->getpoint()<<endl;
                            printRemoveOutput<<removeList->retrieve(a)->getques()<<endl;
                            printRemoveOutput<<removeList->retrieve(a)->getans()<<endl;
                        }
                        else{
                            printRemoveOutput<<removeList->retrieve(a)->getquesType()<<" "<<removeList->retrieve(a)->getpoint()<<endl;
                            printRemoveOutput<<removeList->retrieve(a)->getques()<<endl;
                            printRemoveOutput<<removeList->retrieve(a)->getnumChoice()<<endl;
                            for (int i=0;i<removeList->retrieve(a)->getnumChoice();i++)
                            {
                                printRemoveOutput<<removeList->retrieve(a)->getChoicesList(i)<<endl;
                            }

                            printRemoveOutput<<removeList->retrieve(a)->getans()<<endl;
                        }
                    }
                    cout<<"\nRemove Successfully!"<<endl;
                    break;
                }
                case '3':
                {
                    ifstream editOutput;
                    int totalques;
                    string quesEditType;
                    cout<<"\nEnter file name:";
                    cin>>file_name;
                    editOutput.open(file_name);
                    if (editOutput.fail())
                    {
                        cout<<"\nInput file failed, please exit the program!";     //file open failed , quit the program
                        exit(1);
                    }
                    cin.ignore();
                    editOutput>>totalques;
                    Question *editQuesPtr;
                    ListInterface<Question*> *editList= new LList<Question*>();
                    for (int i=0;i<totalques;i++)
                    {
                        editOutput>>quesEditType;
                        if (quesEditType=="TF")
                        {
                            editQuesPtr= new QuestionTF;
                            editOutput>>txt_score;
                            editOutput.ignore();
                            getline(editOutput,txt_question);
                            editOutput>>txt_ans;
                            editQuesPtr->setQuesType("TF");
                            editQuesPtr->setQues(txt_question);
                            editQuesPtr->setAns(txt_ans);
                            editQuesPtr->setPoint(txt_score);
                            editList->insert(editList->getLength()+1,editQuesPtr);
                        }
                        else{
                            if (quesEditType=="SA")
                            {
                                editQuesPtr= new QuestionSA;
                                editOutput>>txt_score;
                                editOutput.ignore();
                                getline(editOutput,txt_question);
                                editOutput>>txt_ans;
                                editQuesPtr->setQuesType("SA");
                                editQuesPtr->setQues(txt_question);
                                editQuesPtr->setAns(txt_ans);
                                editQuesPtr->setPoint(txt_score);
                                editList->insert(editList->getLength()+1,editQuesPtr);
                            }
                            else{
                                if (quesEditType=="MC")
                                {
                                    editQuesPtr= new QuestionMC;
                                    editOutput>>txt_score;
                                    editOutput.ignore();
                                    getline(editOutput,txt_question);
                                    editOutput>>num_choice;
                                    editOutput.ignore();
                                    for (int i=0;i<num_choice;i++){
                                        getline(editOutput,MCchoice);
                                        MCchoicetemp.push_back(MCchoice);
                                    }
                                    editOutput>>txt_ans;
                                    editQuesPtr->setQuesType("MC");
                                    editQuesPtr->setnumChoices(num_choice);
                                    editQuesPtr->setQues(txt_question);
                                    editQuesPtr->setAns(txt_ans);
                                    editQuesPtr->setPoint(txt_score);
                                    editQuesPtr->setMCchoices(MCchoicetemp);
                                    editList->insert(editList->getLength()+1,editQuesPtr);
                                    MCchoicetemp.clear();
                                }
                            }
                        }
                    }

                    string wordToreplaced,wordToedit;
                    int editInt,checker=0,iteration=0;
                    vector<int> quesNum;
                    bool test=true;
                    cout<<"\nEnter word/phrase to edit:";
                    getline(cin,wordToedit);
                    for (int i=1;i<=editList->getLength();i++)
                    {
                        txt_question=editList->retrieve(i)->getques();
                        if (txt_question.find(wordToedit) != string::npos)
                        {
                            cout<<endl<<"'"<<wordToedit<<"' Found on Question "<<i<<endl;
                            quesNum.push_back(i);
                            iteration++;
                        }
                    }
                    if (iteration!=0)
                    {
                        do{
                            cout<<"\nEnter question number to edit:";
                            cin>>editInt;
                            for (int i=0;i<quesNum.size();i++)
                            {
                                if (editInt==quesNum[i])
                                {
                                    test=false;
                                    break;
                                }
                            }
                            if (test==true)
                            {
                                cout<<"\nInvalid Question Entered. Please re-enter the Question.\n";
                            }
                        }while (test);
                        cin.ignore();
                        cout<<"\nEnter word/phrase to replace '"<<wordToedit<<"':";
                        getline(cin,wordToreplaced);
                        quesEditType=editList->retrieve(editInt)->getquesType();
                        if (quesEditType == "TF" || quesEditType=="SA")
                        {
                            txt_question=editList->retrieve(editInt)->getques();
                            txt_ans=editList->retrieve(editInt)->getans();
                            txt_score=editList->retrieve(editInt)->getpoint();
                        }
                        else{
                            txt_question=editList->retrieve(editInt)->getques();
                            txt_ans=editList->retrieve(editInt)->getans();
                            txt_score=editList->retrieve(editInt)->getpoint();
                            num_choice=editList->retrieve(editInt)->getnumChoice();
                            for (int i=0;i<num_choice;i++)
                            {
                                MCchoicetemp.push_back(editList->retrieve(editInt)->getChoicesList(i));
                            }
                        }
                        while (txt_question.find(wordToedit)!=txt_question.npos)
                        {
                            txt_question.replace(txt_question.find(wordToedit),wordToedit.length(),wordToreplaced);
                        }
                        if (quesEditType=="TF")
                        {
                            editQuesPtr=new QuestionTF;
                            editQuesPtr->setQuesType("TF");
                            editQuesPtr->setQues(txt_question);
                            editQuesPtr->setAns(txt_ans);
                            editQuesPtr->setPoint(txt_score);
                            editList->setEntry(editInt,editQuesPtr);
                        }
                        else{
                            if (quesEditType=="SA")
                            {
                                editQuesPtr=new QuestionSA;
                                editQuesPtr->setQuesType("SA");
                                editQuesPtr->setQues(txt_question);
                                editQuesPtr->setAns(txt_ans);
                                editQuesPtr->setPoint(txt_score);
                                editList->setEntry(editInt,editQuesPtr);
                            }
                            else{
                                if (quesEditType=="MC")
                                {
                                    editQuesPtr=new QuestionMC;
                                    editQuesPtr->setQuesType("MC");
                                    editQuesPtr->setnumChoices(num_choice);
                                    editQuesPtr->setQues(txt_question);
                                    editQuesPtr->setAns(txt_ans);
                                    editQuesPtr->setPoint(txt_score);
                                    editQuesPtr->setMCchoices(MCchoicetemp);
                                    editList->setEntry(editInt,editQuesPtr);

                                }
                            }
                        }
                        MCchoicetemp.clear();
                        ofstream printEditedOutput;
                        printEditedOutput.open(file_name);
                        printEditedOutput<<editList->getLength()<<endl;
                        for (int a=1;a<=editList->getLength();a++)
                        {
                            if (editList->retrieve(a)->getquesType()=="TF" || editList->retrieve(a)->getquesType()=="SA")
                            {
                                printEditedOutput<<editList->retrieve(a)->getquesType()<<" "<<editList->retrieve(a)->getpoint()<<endl;
                                printEditedOutput<<editList->retrieve(a)->getques()<<endl;
                                printEditedOutput<<editList->retrieve(a)->getans()<<endl;
                            }
                            else{
                                printEditedOutput<<editList->retrieve(a)->getquesType()<<" "<<editList->retrieve(a)->getpoint()<<endl;
                                printEditedOutput<<editList->retrieve(a)->getques()<<endl;
                                printEditedOutput<<editList->retrieve(a)->getnumChoice()<<endl;
                                for (int i=0;i<editList->retrieve(a)->getnumChoice();i++)
                                {
                                    printEditedOutput<<editList->retrieve(a)->getChoicesList(i)<<endl;
                                }

                                printEditedOutput<<editList->retrieve(a)->getans()<<endl;
                            }
                        }
                        cout<<"\nEdit Successfully !\n";
                        editOutput.close();
                        printEditedOutput.close();
                    }
                    else{
                        cout<<endl<<"'"<<wordToedit<<"' Cannot be found!\n";
                    }
                    break;
                }
                case '4':
                {
                    string first,last,score,ignore;
                    int printCount=0;
                    char file_name[20];
                    cout<<"\nEnter which file to view top 10 list:";
                    cin>>file_name;
                    ifstream ScoreIn;
                    ScoreIn.open(file_name);
                    if (ScoreIn.fail())
                    {
                        cout<<"\nInput file failed, please exit the program!";     //file open failed , quit the program
                        exit(1);
                    }
                    getline(ScoreIn,ignore);
                    cout<<"       \n------------------------------------TOP TEN HIGH PERFORMANCE PLAYER---------------------------------\n";
                    cout<<endl<<setw(30)<<"|First Name|"<<setw(30)<<"|Last Name|"<<setw(36)<<"|Score(Out Of 100)|"<<endl;
                    while (ScoreIn>>first>>last>>score)
                    {
                        cout<<setw(28)<<first<<setw(30)<<last<<setw(30)<<score<<endl;
                        printCount++;
                        if (printCount==10)
                        {
                            break;
                        }
                    }
                    break;

                }
                case '5':
                {
                    srand(time(NULL));  	//use to generate random number
                    char file_name[20];
                    string setofQuestion;
                    int num1,num2;
                    string first,last;
                    cout<<"\nPlease enter your first name:\n";
                    getline(cin,first);
                    cout<<"\nPlease enter your last name:\n";
                    getline(cin,last);
                    cout<<"\nWhich set of question do you want to select?\n";
                    cout<<"\n1)Science\n\n2)General Knowledge\n\n3)Technology\n";
                    cout<<"\nSelection =>";
                    getline(cin,setofQuestion);
                    while (setofQuestion!="1" && setofQuestion!="2" && setofQuestion!="3")
                    {
                        cout<<"\nPlease enter a valid selection!\n";
                        cout<<"\nSelection =>";
                        getline(cin,setofQuestion);
                    }
                    if (setofQuestion=="1" )
                    {
                        strcpy(file_name,"Science.txt");
                    }
                    else if(setofQuestion=="2")
                    {
                        strcpy(file_name,"sample.txt");
                    }
                    else if(setofQuestion=="3" ){
                       strcpy(file_name,"Technology.txt");
                    }
                    ifstream fin(file_name);
                    if (fin.fail())
                    {
                        cout<<"\nInput file failed, please exit the program!";     //file open failed , quit the program
                        exit(1);
                    }
                    fin>>num2;  		//get total number of question from the file
                    string type,input1;
                    Question *ptr;		//create a Question pointer
                    Player char1(first,last);    //call the overloaded constructor
                    ListInterface<Question*> *TFlist = new LList<Question*>();
                    ListInterface<Question*> *SAlist = new LList<Question*>();
                    ListInterface<Question*> *MClist = new LList<Question*>();
                    ListInterface<Question*> *quesList = new LList<Question*>();
                    for (int i=0;i<num2;i++)
                    {
                        fin>>type;
                        if (type=="TF")
                        {
                            ptr=new QuestionTF;		//Question pointer poting to QuestionTF
                            fin>>txt_score;
                            fin.ignore();
                            getline(fin,txt_question);
                            fin>>txt_ans;
                            ptr->setQues(txt_question);
                            ptr->setAns(txt_ans);
                            ptr->setPoint(txt_score);
                            TFlist->insert(TFlist->getLength()+1,ptr);	//store only TF type question in this vector (for practice section)
                            quesList->insert(quesList->getLength()+1,ptr);	//store all types of question in this vector (for random)
                        }
                        else{
                            if (type=="SA")
                            {
                                ptr=new QuestionSA;
                                fin>>txt_score;
                                fin.ignore();
                                getline(fin,txt_question);
                                fin>>txt_ans;
                                ptr->setQues(txt_question);
                                ptr->setAns(txt_ans);
                                ptr->setPoint(txt_score);
                                SAlist->insert(SAlist->getLength()+1,ptr);	//store SA type question in this vector
                                quesList->insert(quesList->getLength()+1,ptr);
                            }

                            else{
                                if (type=="MC")
                                {
                                    ptr=new QuestionMC;
                                    fin>>txt_score;
                                    fin.ignore();
                                    getline(fin,txt_question);
                                    fin>>num_choice;
                                    fin.ignore();
                                    for (int i=0;i<num_choice;i++){
                                        getline(fin,MCchoice);
                                        MCchoicetemp.push_back(MCchoice);
                                    }
                                    fin>>txt_ans;
                                    ptr->setQues(txt_question);
                                    ptr->setAns(txt_ans);
                                    ptr->setPoint(txt_score);
                                    ptr->setMCchoices(MCchoicetemp);
                                    MClist->insert(MClist->getLength()+1,ptr);	//store MC type question in this vector
                                    quesList->insert(quesList->getLength()+1,ptr);
                                    MCchoicetemp.clear();
                                }
                            }
                        }
                    }
                    //-----------Check whether file input correctly (FOR LECTURER TO TEST)---------------------------------------------------------------------
                    bool correct=true;
                    int n;
                    string choice,s1;
                    do{
                        correct=true;
                        while (correct){
                            cout<<"\nEnter number to display question:\n";
                            getline(cin,s1);
                            if (!(istringstream(s1)>>n)){			//to test whether the input is string or not
                                cout<<"Sorry , that is not valid.\n";
                                correct=true;
                            }
                            else{
                                if (n>num2 || n<=0){
                                    cout<<"Out of question size!\n";
                                    correct=true;
                                }
                                else{
                                    correct=false;
                                }
                            }
                        }
                        quesList->retrieve(n)->display(n-1);
                        cout<<"Answer:"<<quesList->retrieve(n)->getans()<<endl;
                        cout<<"\nDo you want to continue? (N/n to exit) :\n";
                        getline(cin,choice);

                    }while (choice!="N" && choice!="n");
                    //----------------------------Practice Section(Bonus Mark)---------------------------------------------------------
                    char section='P';		//to determine practice section or exam section
                    string typeofques,response;
                    cout<<"\nDo you need some practice on particular type of question? (Press N or n to quit practice section)\n";
                    getline(cin,response);
                    while (response!="N" && response!="n"){
                        cout<<"\nPlease enter type of question (TF/MC/SA) :\n";
                        getline(cin,typeofques);
                        if (typeofques=="TF"){
                            for (int i=1;i<=TFlist->getLength();i++){
                                TFlist->retrieve(i)->display(i-1);		//use TFlist vector to print the all the question inside of it
                                cout<<"\nAnswer:";
                                getline(cin,input1);
                                TFlist->retrieve(i)->checkans(input1,section);
                            }
                        }
                        else{
                            if(typeofques=="MC"){
                                for (int i=1;i<=MClist->getLength();i++){
                                MClist->retrieve(i)->display(i-1);	//use MClist vector to print the all the question inside of it
                                cout<<"\nAnswer:";
                                getline(cin,input1);
                                MClist->retrieve(i)->checkans(input1,section);
                                }
                            }
                            else{
                                if (typeofques=="SA"){
                                    for (int i=1;i<=SAlist->getLength();i++){
                                    SAlist->retrieve(i)->display(i-1);	//use SAlist vector to print the all the question inside of it
                                    cout<<"\nAnswer:";
                                    getline(cin,input1);
                                    SAlist->retrieve(i)->checkans(input1,section);
                                    }
                                }
                                else{
                                    cout<<"Type cannot be found.\n";
                                }
                            }
                        }
                        cout<<"\nContinue to practice? (Press N or n to quit practice section)\n";
                        getline(cin,response);
                    }
                    cout<<endl;
                    //-------------------------MAIN GAME------------------------------------------------------------------------------------------
                    string s;
                    correct=true;
                    while (correct){
                        cout<<"\nHow many questions would you like to have (out of "<<num2<<")\n";
                        getline(cin,s);
                        if (!(istringstream(s)>>num1)){			//check whether input is a string or not
                            cout<<"Sorry , that is not valid.\n";
                            correct=true;

                        }
                        else{
                            if (num1>num2){
                                cout<<"Sorry, that is too many\n";
                                correct=true;
                            }
                            else{
                                if(num1<=0){
                                    cout<<"Sorry, that is not valid.\n";
                                    correct=true;
                                }
                                else{
                                    correct=false;
                                }
                            }
                        }
                    }
                    cout<<endl<<"=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.="<<endl<<"           START GAME              "<<endl<<"=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.="<<endl;
                    section='E';		//determine whether it is practice section or exam section
                    quesList->randomize();
                    //----------------Add all question's point to calculate percentage mark at last part------------------------------------------
                    double totalPoint=0;
                    for (int i=1;i<=num1;i++)
                    {
                        totalPoint=totalPoint+quesList->retrieve(i)->getpoint();
                    }
                    //-----------------------------------------------------------------------------------------------------------------------------
                    for (int i=1;i<=num1;i++){
                        quesList->retrieve(i)->display(i-1);	//display question. If it is MC type question , it will display the choices
                        cout<<"\nAnswer:";
                        getline(cin,input1);
                        quesList->retrieve(i)->checkans(input1,section);	//check the answer from user
                        char1.addscore(quesList,i);			//add point to score
                    }
                    char1.finalresult();		//print the final result
                    cout<<"Enter the file name to store best performance list (File will be created if it is not exist:"<<endl;
                    cin>>file_name;
                    HighScore currentPlayer;
                    double PercentageMark;
                    PercentageMark=(char1.getscore()/totalPoint)*100.0;
                    currentPlayer.setFname(char1.getfname());
                    currentPlayer.setLname(char1.getlname());
                    currentPlayer.setMark(PercentageMark);
                    ListInterface<HighScore> *HighScoreList = new LList<HighScore> ();
                    HighScore Hlist;
                    ifstream openScore;
                    openScore.open(file_name,ios::app);
                    string First,Last,ignore;
                    int Score;
                    getline(openScore,ignore);
                    while (openScore>>First>>Last>>Score)
                    {
                        Hlist.setFname(First);
                        Hlist.setLname(Last);
                        Hlist.setMark(Score);
                        HighScoreList->insert(HighScoreList->getLength()+1,Hlist);
                    }
                    HighScoreList->sortInsertDesc(currentPlayer);
                    ofstream fout;
                    fout.open(file_name);
                    fout<<setw(30)<<right<<"|First Name|"<<setw(30)<<"|Last Name|"<<setw(30)<<right<<"|Score(%)|"<<endl;
                    for (int i=1;i<=HighScoreList->getLength();i++){
                        fout<<setw(30)<<right<<HighScoreList->retrieve(i).getFname()<<setw(30)<<right<<HighScoreList->retrieve(i).getLname()<<setw(30)<<right<<HighScoreList->retrieve(i).getMark()<<endl;			//output score to the file
                    }
                    delete ptr;
                    ptr=NULL;
                    fout.close();
                    openScore.close();
                    break;
                }
                case 'Q':
                {
                    returnquiz=true;
                    break;
                }
                default:
                    cout<<"\nPlease re-enter again !\n";

        }
    cout<<endl;
    system("pause");
    }while (!returnquiz);
}
