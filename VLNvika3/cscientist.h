#ifndef CSCIENTIST_H
#define CSCIENTIST_H
#include <string>
using namespace std;

class CScientist
{
public:
    CScientist();
    //CScientist(string cName, string cGender, string date1, string date2, bool cIsActive);
    CScientist(int id, string cName, string cGender, string date1, string date2, bool isActive);
    string getName() const;
    int getId() const;
    bool getIsActive() const;
    string getGender() const;
    string getDob() const;
    string getDod() const;
    string getBio() const;
    string getQuote() const;
    string getBooks() const;
    void setName(string nameToSet);
    void setGender(string genderToSet);
    void setDob(string dateToSet);
    void setDod(string dateToSet);
    void setId(int idToSet);
    void setIsActive(bool isActiveToSet);
    void setBio(string bioToSet);
    void setQuote(string quoteToSet);
    void setBooks(string booksToSet);

private:
    int id;
    string name;
    string gender;
    string dateBorn;
    string dateDeath;
    bool isActive;
    string bio;
    string quote;
    string books;

};

#endif // CSCIENTIST_H
