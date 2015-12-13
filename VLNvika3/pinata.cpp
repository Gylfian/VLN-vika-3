#include "pinata.h"
#include "ui_pinata.h"
#include <QDialog>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>

Pinata::Pinata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pinata)
{
    ui->setupUi(this);
}

Pinata::~Pinata()
{
    delete ui;
}
