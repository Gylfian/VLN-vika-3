#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listoptions.h"
#include "search.h"
#include "addentry.h"
#include "addconnection.h"
#include "restore.h"
#include <QDialog>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QVideoWidget>
#include <QtWidgets>
#include <QGraphicsVideoItem>
#include <qvideowidget.h>
#include <qvideosurfaceformat.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAddEntry_clicked()
{
    AddEntry a1;
    a1.exec();
}

void MainWindow::on_pushButtonAddConnection_clicked()
{
    AddConnection a1;
    a1.exec();
}

void MainWindow::on_pushButtonSearch_clicked()
{
    Search s1;
    s1.exec();
}

void MainWindow::on_pushButtonRestore_clicked()
{
    Restore r1;
    r1.exec();
}

void MainWindow::on_pushButtonExit_clicked()
{
    exit(0);
}

void MainWindow::on_pushButtonListOptions_clicked()
{
    ListOptions listoptions;
    listoptions.exec();
}

void MainWindow::on_pinata_clicked()
{
     QMediaPlayer *player=new QMediaPlayer;
     QMediaPlayer *audioplayer = new QMediaPlayer;
     QVideoWidget *videowidget=new QVideoWidget;
     QMediaPlaylist *playlist=new QMediaPlaylist;
     playlist->addMedia(QUrl("C:/Users/Johanna/Desktop/VLN-vika-3/VLNvika3/HumanPinata.mp4"));
     player->setVideoOutput(videowidget);
     playlist->setCurrentIndex(1);
     player->setPlaylist(playlist);
     player->setMuted(true);
     audioplayer->setMedia(QUrl::fromLocalFile("C:/Users/Johanna/Desktop/VLN-vika-3/VLNvika3/pinatasong.mp3"));
     audioplayer->setVolume(50);
     audioplayer->play();
     player->play();
     videowidget->show();

}
