#include "analyze.h"
#include "ui_analyze.h"
#include "domain.h"
#include <QDebug>
#include <sstream>

void Analyze::setScientist(CScientist scientistToSet)
{
    scientist = scientistToSet;
    printSciBasicInfo();
    printSciDetailedInfo();
    getSciPicture();
}

void Analyze::setComputer(Computer computerToSet)
{
    computer = computerToSet;
}

Analyze::Analyze(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Analyze)
{
    ui->setupUi(this);
}

Analyze::~Analyze()
{
    delete ui;
}

void Analyze::printSciBasicInfo()
{
    string name = scientist.getName();
    string gender = "Gender: " + scientist.getGender();
    string dob = "Year of birth: " + scientist.getDob();
    string dod = scientist.getDod();
    string books = scientist.getBooks();
    if (dod == "Alive")
    {
        if (scientist.getGender() == "Male")
        {
            dod = "He is alive";
        }
        else
        {
            dod = "She is alive";
        }
    }
    else
    {
        dod = "Year of death: " + scientist.getDod() + '\n' + '\n';
    }
    if (books != "")
    {
        books = "Books by " + scientist.getName() + ": " + scientist.getBooks();
    }
    string tempText = name + '\n' + '\n' + gender  + '\n' + '\n' + dob  + '\n' + '\n' + dod + '\n' + '\n' + books;

    QString text = QString::fromStdString(tempText);
    ui->basicInfoText->setText(text);
}

void Analyze::printSciDetailedInfo()
{
    Domain dom;
    CScientist sci = dom.findScientist(scientist);
    string bio = sci.getBio() + '\n' + '\n' + "Famous words: " + '\n' + " " + sci.getQuote();
    QString text = QString::fromStdString(bio);
    ui->detailedInfoText->setText(text);
}

void Analyze::getSciPicture()
{
    int sizeX = 270;
    int sizeY = 210;

    Domain dom;
    CScientist sci = dom.findScientist(scientist);
    int id = sci.getId();
    stringstream ss;
    ss << id;
    string idi = ss.str();
    string path = "sciPictures/" + idi + ".jpg";
    QString path2 = QString::fromStdString(path);

    QPixmap pixmap(path2);
    pixmap = pixmap.scaled(sizeX, sizeY,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(pixmap);
}

void Analyze::printComBasicInfo()
{

}

void Analyze::printComDetailedInfo()
{

}

void Analyze::getComPicture()
{
    int sizeX = 270;
    int sizeY = 210;

    Domain dom;
    Computer sci = dom.findComputer(computer);
    int id = sci.getId();
    stringstream ss;
    ss << id;
    string idi = ss.str();
    string path = "comPictures/" + idi + ".jpg";
    QString path2 = QString::fromStdString(path);

    QPixmap pixmap(path2);
    pixmap = pixmap.scaled(sizeX, sizeY,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(pixmap);
}

void Analyze::on_analyzeOk_accepted()
{
    reject();
}
