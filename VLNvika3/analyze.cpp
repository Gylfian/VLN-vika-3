#include "analyze.h"
#include "ui_analyze.h"

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
    printComBasicInfo();
    printComDetailedInfo();
    getComPicture();
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

    CScientist sci = dom.findScientist(scientist);

    string name = sci.getName();
    string gender = "Gender: " + sci.getGender();
    string dob = "Year of birth: " + sci.getDob();
    string dod = sci.getDod();
    if (dod == "Alive")
    {
        if (sci.getGender() == "Male")
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
        dod = "Year of death: " + sci.getDod() + '\n' + '\n';
    }

    string books = sci.getBooks();
    if (books != "")
    {
        books = "Books by " + sci.getName() + ": " + sci.getBooks();
    }

    string tempText = name + '\n' + '\n' + gender  + '\n' + '\n' + dob + '\n' + '\n' + dod + '\n' + '\n' + books;
    QString text = QString::fromStdString(tempText);
    ui->basicInfoText->setText(text);
}

void Analyze::printSciDetailedInfo()
{
    CScientist sci = dom.findScientist(scientist);
    string bio = "";
    if (sci.getBio() != "")
    {
        bio = sci.getBio() + '\n' + '\n';
        if (sci.getQuote() != "")
        {
            bio = bio + "Famous words: " + '\n' + " " + sci.getQuote();

        }
    }
    else
    {
        bio = "This person has no additional information";
    }
    QString text = QString::fromStdString(bio);
    ui->detailedInfoText->setText(text);
}

void Analyze::getSciPicture()
{
    int sizeX = 180;
    int sizeY = 210;

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
    Computer com = dom.findComputer(computer);
    string name = com.getName();
    string type = com.getType();
    string built = com.getBuilt();

    if (built == "No")
    {
        built = "It was never built";
    }
    else
    {
        built = "It was built in " + com.getYear();
    }

    string tempText = name + '\n' + '\n' + "Type: " + type + '\n' + '\n' + built + '\n' + '\n';
    QString text = QString::fromStdString(tempText);
    ui->basicInfoText->setText(text);

}

void Analyze::printComDetailedInfo()
{
    Computer com = dom.findComputer(computer);
    string about = "";
    if (com.getAbout() != "")
    {
        about = com.getAbout();
    }
    else
    {
        about = "This computer has no additional information";
    }
    QString text = QString::fromStdString(about);
    ui->detailedInfoText->setText(text);
}

void Analyze::getComPicture()
{
    int sizeX = 180;
    int sizeY = 210;

    Computer com = dom.findComputer(computer);
    int id = com.getId();
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
