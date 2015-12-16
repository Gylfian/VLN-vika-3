#include "pinata.h"
#include "ui_pinata.h"
#include <QDialog>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QVideoWidget>
#include <QPixmap>
#include <QMovie>
#include <QLabel>
#include <QGraphicsScene>

Pinata::Pinata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pinata)
{
    ui->setupUi(this);
    setWindowTitle("Piñata");
    QMediaPlayer *audioplayer = new QMediaPlayer;
    audioplayer->setMedia(QUrl::fromLocalFile("pinatasong.mp3"));
    audioplayer->setVolume(50);
    audioplayer->play();
    ui->pinatalabel->setWindowFlags(Qt::FramelessWindowHint);
    QMovie *movie = new QMovie(":/icon/giphy.gif");
    ui->pinatalabel->setMovie(movie);
    movie->start();
    ui->pinatalabel->show();
}

Pinata::~Pinata()
{
    delete ui;
}
