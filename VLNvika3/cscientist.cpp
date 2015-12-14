#include "cscientist.h"

CScientist::CScientist()
{
    id = -1;
    name = "";
    gender ="";
    dateBorn = "";
    dateDeath = "";
    bio = "";
    quote = "";
    books = "";
    isActive = false;
}

CScientist::CScientist(int cId, string cName, string cGender, string date1, string date2, bool cIsActive)
{
    id = cId;
    name = cName;
    gender = cGender;
    dateBorn = date1;
    dateDeath = date2;
    isActive = cIsActive;
}

/*
CScientist::CScientist(string cName, string cGender, string date1, string date2, bool cIsActive)
{
    name = cName;
    gender = cGender;
    dateBorn = date1;
    dateDeath = date2;
    isActive = cIsActive;
}
*/

int CScientist::getId() const
{
    return id;
}

string CScientist::getName() const
{
    return name;
}

string CScientist::getGender() const
{
   return gender;
}

string CScientist::getDob() const
{
   return dateBorn;
}

string CScientist::getDod() const
{
   return dateDeath;
}

string CScientist::getBio() const
{
    return bio;
}

string CScientist::getQuote() const
{
    return quote;
}

string CScientist::getBooks() const
{
    return books;
}

bool CScientist::getIsActive() const
{
   return isActive;
}

void CScientist::setId(int idToSet)
{
    id=idToSet;
}

void CScientist::setName(string nameToSet)
{
    name=nameToSet;
}

void CScientist::setGender(string genderToSet)
{
    gender=genderToSet;
}

void CScientist::setDob(string dateToSet)
{
    dateBorn=dateToSet;
}

void CScientist::setDod(string dateToSet)
{
    dateDeath=dateToSet;
}

void CScientist::setIsActive(bool isActiveToSet)
{
    isActive=isActiveToSet;
}

void CScientist::setBio(string bioToSet)
{
    bio = bioToSet;
}

void CScientist::setQuote(string quoteToSet)
{
    quote = quoteToSet;
}

void CScientist::setBooks(string booksToSet)
{
    books = booksToSet;
}

