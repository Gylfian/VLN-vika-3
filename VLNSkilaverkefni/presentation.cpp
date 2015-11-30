
#include "presentation.h"
#include "computerscientist.h"
#include "domain.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

Presentation::Presentation() {}

void Presentation::mainPage()
{
    cout << " ________________MAIN_MENU_______________" << endl;
    cout << "|---------What do you want to do?--------|" << endl;
    cout << "|-1) Add computer scientists to the list-|" << endl;
    cout << "|-2) See the list of computer scientists-|" << endl;
    cout << "|-------Press any other key to quit------|" << endl;
    cout << "|________________________________________|" << endl;
    options();
}

void Presentation::options()
{
    char ans = getch();
    system("CLS");

    switch (ans)
    {
        case ('1'):
        {
            addScientist();
        }break;
        case ('2'):
        {
            displayListOptions();
        }break;
        default:
            exit (1);
    }
}

void Presentation::addScientist()
{
    CScientist cSci;
    vector<CScientist> scientists;

    do
    {
        system("CLS");
        scientistData(cSci);
        scientists.push_back(cSci);

    }while(another());
    Domain dom1;
    dom1.addToFile(scientists);
    system("CLS");
    mainPage();
}

void Presentation::scientistData(CScientist cSci)
{
    string name, gender, Dob, Dod;
    name = getInputName();
    gender = getInputGender();
    Dob = getInputDob();
    Dod = getInputDod();

    cSci.setName(name);
    cSci.setGender(gender);
    cSci.setDob(Dob);
    cSci.SetDod(Dod);
}

string Presentation::getInputGender()
{
    string gender;
    cout << "Is the scientist [m]ale or [f]emale ? " << endl;
    char ans = getch();
        switch (ans)
        {
        case ('M'):
        case ('m'):
        {
            gender = "Male";
            cout << gender<<" selected"<< endl;
        }break;
        case ('F'):
        case ('f'):
        {
        gender = "Female";
        cout << gender<<" selected"<< endl;
        }break;
        default:{
        cout << "Please select either male or female"<<endl;
        this->getInputGender();
    }


}
    return gender;
}

string Presentation::getInputName()
{
    string name;
    Domain d1;
    bool namecheck = false;
    cout << "Enter name: ";
    while(namecheck==false)
    {
        getline(cin,name);
        namecheck = d1.normalizeName(name);
    }
    return name;
}


string Presentation::getInputDob()
{
    string Dob;
    cout << "Enter year of birth: ";
    cin >> Dob;
    return Dob;
}

string Presentation::getInputDod()
{
    string Dod;
    cout << "Enter year of death: ";
    cin >> Dod;
    return Dod;
}

bool Presentation::another()
{
    cout << "-------------Person added--------------" << endl;
    cout << "Do you wish to add another person (y/n)" << endl;

    char ans = getch();

    switch (ans)
    {
        case ('Y'):
        case ('y'):
            return true;
            break;
        case ('N'):
        case ('n'):
            return false;
            break;
        default:
            return false;
    }
}

void Presentation::displayListOptions()
{
    cout << " _____________________________________" << endl;
    cout << "|-How do you want the list displayed?-|" << endl;
    cout << "|-1) Alphabetically-------------------|" << endl;
    cout << "|-2) By gender------------------------|" << endl;
    cout << "|-3) By year of birth-----------------|" << endl;
    cout << "|-4) By year of death-----------------|" << endl;
    cout << "|-Press any other key to go back------|" << endl;
    cout << "|_____________________________________|" << endl;
    listOptions();

}

void Presentation::listOptions()
{
    char ans = getch();
    system("CLS");

    switch(ans)
    {
        case('1'):
        {
            alphaAscendingDecending();
        }break;
        case ('2'):
        {
            genderOrder();
        }break;
        case ('3'):
        {

        }break;
        case ('4'):
        {

        }break;
        default:
            mainPage();

    }
}

void Presentation::ascendingDecendingText()
{
    cout << " _____________________________________" << endl;
    cout << "|-In what order do you want the list?-|" << endl;
    cout << "|-1) Ascending order------------------|" << endl;
    cout << "|-2) Decending order------------------|" << endl;
    cout << "|-Press any other key to go back------|" << endl;
    cout << "|_____________________________________|" << endl;
}

void Presentation::alphaAscendingDecending()
{
    ascendingDecendingText();
    char ans = getch();
    system("CLS");

    switch (ans)
    {
        case ('1'):
        {

        }break;
        case('2'):
        {

        }break;
        default:
            displayListOptions();
    }
}

void Presentation::genderOrder()
{
    cout << " _____________________________________" << endl;
    cout << "|-In what order do you want the list?-|" << endl;
    cout << "|-1) Male first-----------------------|" << endl;
    cout << "|-2) Female first---------------------|" << endl;
    cout << "|-Press any other key to go back------|" << endl;
    cout << "|_____________________________________|" << endl;

    char ans = getch();
    system("CLS");

    switch (ans)
    {
        case ('1'):
        {

        }break;
        case ('2'):
        {

        }break;
        default:
            displayListOptions();
    }
}
