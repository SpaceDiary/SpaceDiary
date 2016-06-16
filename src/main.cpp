#include "Menu.h"
#include "widget.h"

#include <QApplication>
//#include <phonon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDir mainDir;
    mainDir.setPath("/home/tolik/Dropbox/University/6/Software Design/Strategy");
    QDir::setCurrent(mainDir.path());

    Menu* menu = new Menu(mainDir);
    QObject::connect(menu->findChild<QObject*>("exit"), SIGNAL(clicked()), &a, SLOT(quit()));

//    Phonon::MediaObject media;
//    Phonon::AudioOutput ao(Phonon::MusicCategory);
//    Phonon::createPath(&media, &ao);
//    media.setCurrentSource(Phonon::MediaSource("Music/ttp.mp3"));
    //media.play();
//    QObject::connect(&media, SIGNAL(finished()), &media, SLOT(play()));

    return a.exec();
}
