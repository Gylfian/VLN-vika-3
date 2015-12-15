#include "domain.h"

Domain::Domain()
{

}

void Domain::sortBy(vector<CScientist> &cSciList, char child, char child2)
{

    if(child == '1') //sort by name
    {
        getName(cSciList, child2);
    }
    else if(child == '2') //sort by gender
    {
        getGender(cSciList, child2);
    }
    else if(child == '3') //sort by year born
    {
        getYear(cSciList, child2);
    }
    else if(child == '4') //sort by year of death
    {
        getYearDeath(cSciList, child2);
    }
    else
    {
        getId(cSciList, child2);
    }
}

void Domain::sortBy(vector<Computer> &cComList, char child, char child2)
{
    if(child == '1') //sort by name
    {
        getComName(cComList, child2);
    }
    else if(child == '2')//sort by type
    {
        getComType(cComList, child2);
    }
    else if(child == '3')//sort by if built
    {
        getComBuilt(cComList, child2);
    }
    else if(child == '4')//sort by year built
    {
        getComYear(cComList, child2);
    }
    else
    {
        getComId(cComList, child2);
    }
}

void Domain::restoreEntry(vector<CScientist> &cSciList)
{
    getActive(cSciList);
}

void Domain::restoreEntry(vector<Computer> &cComList)
{
    getComActive(cComList);
}

void Domain::getComName(vector<Computer> &cComList, char child2)
{
    Computer com;
    data.select(com, 1, charToInt(child2));
    cComList = data.getComVector();
}

void Domain::getComType(vector<Computer> &cComList, char child2)
{
    Computer com;
    data.select(com, 2, charToInt(child2));
    cComList = data.getComVector();
}

void Domain::getComYear(vector<Computer> &cComList, char child2)
{
    Computer com;
    data.select(com, 4, charToInt(child2));
    cComList = data.getComVector();
}

void Domain::getComBuilt(vector<Computer> &cComList, char child2)
{
    Computer com;
    data.select(com, 3, charToInt(child2));
    cComList = data.getComVector();
}

void Domain::getComId(vector<Computer> &cComList, char child2)
{
    Computer com;
    data.select(com, 5, charToInt(child2));
    cComList = data.getComVector();
}

void Domain::getComActive(vector<Computer> &cComList)
{
    data.computerToRestore();
    cComList = data.getComVector();
}

void Domain::getName(vector<CScientist> &cSciList, char child2)
{
    CScientist scientist;
    data.select(scientist, 1, charToInt(child2));
    cSciList = data.getSciVector();
}

void Domain::getGender(vector<CScientist> &cSciList, char child2)
{
    CScientist scientist;
    data.select(scientist, 2, charToInt(child2));
    cSciList = data.getSciVector();
}

void Domain::getId(vector<CScientist> &cSciList, char child2)
{
    CScientist scientist;
    data.select(scientist, 5, charToInt(child2));
    cSciList = data.getSciVector();
}

void Domain::getActive(vector<CScientist> &cSciList)
{
    data.scientistToRestore();
    cSciList = data.getSciVector();
}

void Domain::getYearDeath(vector<CScientist> &cSciList, char child2)
{
    CScientist scientist;
    data.select(scientist, 4, charToInt(child2));
    cSciList = data.getSciVector();
}

void Domain::getYear(vector<CScientist> &cSciList, char child2)
{
    CScientist scientist;
    data.select(scientist, 3, charToInt(child2));
    cSciList = data.getSciVector();
}

void Domain::search(vector<CScientist> &cSciList, CScientist cSci)
{
     data.select(cSci, 5, 1);
     cSciList = data.getSciVector();
}

void Domain::search(vector<Computer> &cComList, Computer cCom)
{
     data.select(cCom, 5, 1);
     cComList = data.getComVector();
}

void Domain::addEntry(CScientist cSci)
{
    data.insert(cSci);
}

void Domain::addEntry(Computer cCom)
{
    data.insert(cCom);
}

void Domain::editEntry(CScientist cSci)
{
    string str = cSci.getName();
    normalizeName(str);
    cSci.setName(str);
    data.update(cSci);
}

void Domain::editEntry(Computer cCom)
{
    string str = cCom.getName();
    string type = cCom.getType();
    normalizeName(type);
    normalizeName(str);
    cCom.setName(str);
    cCom.setType(type);
    data.update(cCom);
}

void Domain::removeRelations(int id)
{
    Relation rel;
    rel.setId(id);
    data.deleteRelation(rel);
}

void Domain::updateEntrySci(string sid)
{
    CScientist cSci;
    cSci.setId(convertToInt(sid));
    data.select(cSci, 1, 1);
    vector<CScientist> cSciList = data.getSciVector();
    for(unsigned int i = 0; i < cSciList.size(); i++)
    {
        if(cSciList[i].getId() == cSci.getId())
        {
            cSci = cSciList[i];
        }
    }
    data.updateStatus(cSci);
}

void Domain::updateEntryCom(string sid)
{
    Computer cCom;
    cCom.setId(convertToInt(sid));
    data.select(cCom, 1, 1);
    vector<Computer> cComList = data.getComVector();
    for(unsigned int i = 0; i < cComList.size(); i++)
    {
        if(cComList[i].getId() == cCom.getId())
        {
            cCom = cComList[i];
        }
    }
    data.updateStatus(cCom);
}

vector<Relation> Domain::findRelation(string filter)
{
    vector<Relation> cRelList;
    data.filterRelation(filter);
    cRelList = data.getRelVector();
    return cRelList;
}

CScientist Domain::findInactiveScientist(CScientist cSci)
{
    vector<CScientist> allScientists;
    data.scientistToRestore();
    allScientists = data.getSciVector();
    for(unsigned int i = 0; i < allScientists.size(); i++)
    {
        if(allScientists[i].getName() == cSci.getName() && allScientists[i].getGender() == cSci.getGender() && allScientists[i].getDob() == cSci.getDob() && allScientists[i].getDod() == cSci.getDod())
        {
            cSci = allScientists[i];
        }
    }
    return cSci;
}

Computer Domain::findInactiveComputer(Computer cCom)
{
    vector<Computer> allComputers;
    data.computerToRestore();
    allComputers = data.getComVector();
    for(unsigned int i = 0; i < allComputers.size(); i++)
    {
        if(allComputers[i].getName() == cCom.getName() && allComputers[i].getType() == cCom.getType() && allComputers[i].getBuilt() == cCom.getBuilt() && allComputers[i].getYear() == cCom.getYear())
        {
            cCom = allComputers[i];
        }
    }
    return cCom;
}

CScientist Domain::findScientist(CScientist cSci)
{
    vector<CScientist> allScientists;
    CScientist empty;
    data.select(empty, 1, 1);
    allScientists = data.getSciVector();
    for(unsigned int i = 0; i < allScientists.size(); i++)
    {
        if(allScientists[i].getName() == cSci.getName() && allScientists[i].getGender() == cSci.getGender() && allScientists[i].getDob() == cSci.getDob() && allScientists[i].getDod() == cSci.getDod())
        {
            cSci = allScientists[i];
        }
    }
    return cSci;
}

Computer Domain::findComputer(Computer cCom)
{
    vector<Computer> allComputers;
    Computer empty;
    data.select(empty, 1, 1);
    allComputers = data.getComVector();
    for(unsigned int i = 0; i < allComputers.size(); i++)
    {
        if(allComputers[i].getName() == cCom.getName() && allComputers[i].getType() == cCom.getType() && allComputers[i].getBuilt() == cCom.getBuilt() && allComputers[i].getYear() == cCom.getYear())
        {
            cCom = allComputers[i];
        }
    }

    return cCom;
}

void Domain::getRelationList(vector<Relation> &cRelList, int active)
{
    vector<Relation> allRelations;
    CScientist sci;
    Computer com;
    Relation rel;
    data.select(rel, active);
    cRelList = data.getRelVector();
    for(unsigned int i = 0; i < allRelations.size(); i++)
    {
         sci = allRelations[i].getScientist();
         com = allRelations[i].getComputer();
         string sstr = sci.getName();
         string cstr = com.getName();
         int id = allRelations[i].getId();
         rel.setScientistName(sstr);
         rel.setComputerName(cstr);
         rel.setId(id);
         cRelList.push_back(rel);
    }
}

int Domain::findConnectionId(string scientist, string computer)
{
    vector<Relation> cRelList;
    Relation rel;
    data.select(rel, 1);
    cRelList = data.getRelVector();
    for(unsigned int i = 0; i < cRelList.size(); i++)
    {
        rel = cRelList[i];
        if(rel.getScientist().getName() == scientist && rel.getComputer().getName() == computer)
        {
            return rel.getId();
        }
    }
    return -1;
}

int Domain::charToInt(char chr)
{
    return (int)chr - 48;

}

int Domain::convertToInt(string str)
{
    int n = 0;
    istringstream buffer(str);
    buffer >> n;
    return n;
}

int Domain::checkStrInput(string str)
{
    int n = 0;
    if(str == "")
        return -1;

    n = convertToInt(str);
    return n;
}

void Domain::addRelation(CScientist cSci, Computer cCom)
{
    data.insert(cCom, cSci);
}

bool Domain::normalizeName(string &name)
{
    if(name.length() <= 0)
    {
        return false;
    }
    for(unsigned int i = 0; i < name.length(); i++)
    {
        name[i] = tolower(name[i]);
    }
    name[0] = toupper(name[0]);
    for(unsigned int j = 0; j < name.length(); j++)
    {
        if(name[j] == ' ')
        {
            if(name[j+1] != ' ')
            {
               name[j+1] = toupper(name[j+1]);
            }
        }
    }
    return true;
}
