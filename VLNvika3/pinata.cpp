#include "pinata.h"
#include "ui_pinata.h"
#include <QDialog>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QVideoWidget>

Pinata::Pinata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pinata)
{
    QMediaPlayer *player=new QMediaPlayer;
    QVideoWidget *videowidget=new QVideoWidget;
    QMediaPlaylist *playlist=new QMediaPlaylist;
    playlist->addMedia(QUrl("test.mp4"));
    player->setVideoOutput(videowidget);
    playlist->setCurrentIndex(1);
    player->setPlaylist(playlist);
    player->play();
    videowidget->show();
}

Pinata::~Pinata()
{
    delete ui;
}
