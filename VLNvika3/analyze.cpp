#include "analyze.h"
#include "ui_analyze.h"
#include "domain.h"
#include <QDebug>
#include <string>
#include <sstream>

Analyze::Analyze(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Analyze)
{
    ui->setupUi(this);

    printBasicInfo();
    printDetailedInfo();
    getPicture();

}

Analyze::~Analyze()
{
    delete ui;
}

void Analyze::printBasicInfo()
{
    Domain dom;
    vector<CScientist> scientist;
    dom.sortBy(scientist,'5','1');

    int i = 3;

    string name = scientist[i].getName();
    string gender = "Gender: " + scientist[i].getGender();
    string dob = "Year of birth: " + scientist[i].getDob();
    string dod = scientist[i].getDod();
    string books = scientist[i].getBooks();
    if (dod == "Alive")
    {
        if (scientist[i].getGender() == "Male")
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
        dod = "Year of death: " + scientist[i].getDod() + '\n' + '\n';
    }
    if (books != "")
    {
        books = "Books by " + scientist[i].getName() + ": " + scientist[i].getBooks();
    }
    string tempText = name + '\n' + '\n' + gender  + '\n' + '\n' + dob  + '\n' + '\n' + dod + '\n' + '\n' + books;

    QString text = QString::fromStdString(tempText);
    ui->basicInfoText->setText(text);
}

void Analyze::printDetailedInfo()
{
    int i = 1;
    Domain dom;
    vector<CScientist> scientist;
    dom.sortBy(scientist,'5','1');

    string bio = scientist[i].getBio() + '\n' + '\n' + "Famous words: " + '\n' + " " + scientist[i].getQuote();
    QString text = QString::fromStdString(bio);
    ui->detailedInfoText->setText(text);
}

void Analyze::getPicture()
{
    int sizeX = 270;
    int sizeY = 210;

    int i = 0;
    Domain dom;
    vector<CScientist> scientist;
    dom.sortBy(scientist,'5','1');
    int id = scientist[i].getId();
    stringstream ss;
    ss << id;
    string idi = ss.str();
    string path = "sciPictures/" + idi + ".jpg";
    QString path2 = QString::fromStdString(path);

    QPixmap pixmap(path2);
    pixmap = pixmap.scaled(sizeX, sizeY,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->label->setPixmap(pixmap);
}

void Analyze::on_analyzeOk_accepted()

{
    reject();
}
