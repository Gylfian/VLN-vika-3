#include "addentry.h"
#include "ui_addentry.h"

using namespace std;

AddEntry::AddEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEntry)
{
    ui->setupUi(this);
}

AddEntry::~AddEntry()
{
    delete ui;
}

void AddEntry::on_whichToPick_currentIndexChanged(const QString &arg1)
{
    string option = arg1.toStdString();
    if (option == "Scientist")
    {
        ui->whichToAdd->setCurrentIndex(1);
    }
    else if (option == "Computer")
    {
       ui->whichToAdd->setCurrentIndex(0);
    }
}

void AddEntry::on_sciDeadButton_clicked(bool checked)
{
    if (checked)
    {
        ui->sciDeathInput->setEnabled(true);
        int min = ui->sciBirthInput->value();
        ui->sciDeathInput->setMinimum(min);
    }
}

void AddEntry::on_sciAlivButton_clicked(bool checked)
{
    if(checked)
    {
        ui->sciDeathInput->setEnabled(false);
    }
}

void AddEntry::on_sciBirthInput_valueChanged(int arg1)
{
    if(ui->sciDeathInput->isEnabled())
    {
        ui->sciDeathInput->setMinimum(arg1);
    }
}

void AddEntry::on_comNotBuiltButton_clicked(bool checked)
{
    if(checked)
    {
        ui->comYearBuiltInput->setEnabled(false);
    }
}

void AddEntry::on_comBuiltButton_clicked(bool checked)
{
    if(checked)
    {
        ui->comYearBuiltInput->setEnabled(true);
    }
}

void AddEntry::on_addOrCancelSci_accepted()
{
    if (sciErrorCheck())
    {
        QMessageBox::warning(this, "WARNING!", "You must fill out all the necessary information!");
    }
    else
    {
        CScientist cSci = getSciData();
        Domain dom;
        dom.addEntry(cSci);
        accept();
    }
}

CScientist AddEntry::getSciData()
{
    string name = ui->sciNameInput->text().toStdString();
    string Dob = ui->sciBirthInput->text().toStdString();
    string gender, Dod, bio, quote, books;
    if (ui->sciMaleButton->isChecked())
    {
        gender = "Male";
    }
    else
    {
        gender = "Female";
    }

    if(ui->sciAlivButton->isChecked())
    {
        Dod = "Alive";
    }
    else
    {
        Dod = ui->sciDeathInput->text().toStdString();
    }

    QString Qbio = ui->sciBioInput->toPlainText();
    bio = Qbio.toStdString();

    quote = ui->sciQuotInput->text().toStdString();
    books = ui->sciBooksInput->text().toStdString();

    CScientist cSci(0, name, gender, Dob, Dod, 1);
    cSci.setBio(bio);
    cSci.setQuote(quote);
    cSci.setBooks(books);

    return cSci;

}

void AddEntry::on_addOrCancelCom_accepted()
{
    if (comErrorCheck())
    {
        QMessageBox::warning(this, "WARNING!", "You must fill out all the necessary information!");
    }
    else
    {
        Computer com = getComData();
        Domain dom;
        dom.addEntry(com);
        accept();
    }
}

Computer AddEntry::getComData()
{
    string name = ui->comNameInput->text().toStdString();
    string type = ui->comTypeInput->text().toStdString();
    string built, year, about;
    if (ui->comBuiltButton->isChecked())
    {
        built = "Yes";
        year = ui->comYearBuiltInput->text().toStdString();
    }
    else
    {
        built = "No";
        year = "";
    }

    QString Qabout = ui->comAboutInput->toPlainText();
    about = Qabout.toStdString();

    Computer com(0, name, year, type, built);
    com.setAbout(about);
    return com;
}

void AddEntry::on_addOrCancelCom_rejected()
{
    reject();
}

void AddEntry::on_addOrCancelSci_rejected()
{
    reject();
}

bool AddEntry::sciErrorCheck()
{
    if (ui->sciNameInput->text().size() == 0)
    {
        return true;
    }
    if (!ui->sciMaleButton->isChecked() && !ui->sciFemaleButton->isChecked())
    {
        return true;
    }
    if (!ui->sciAlivButton->isChecked() && !ui->sciDeadButton->isChecked())
    {
        return true;
    }

    return false;

}

bool AddEntry::comErrorCheck()
{
    if (ui->comNameInput->text().size() == 0)
    {
        return true;
    }
    if (ui->comTypeInput->text().size() == 0)
    {
        return true;
    }
    if (!ui->comBuiltButton->isChecked() && !ui->comNotBuiltButton->isChecked())
    {
        return true;
    }

    return false;
}
