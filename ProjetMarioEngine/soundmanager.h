#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <QDialog>
#include <QMediaPlayer>
#include <QMediaContent>
#include <QMediaResource>
#include <QSoundEffect>

class SoundManager
{
    Q_OBJECT
public:
    explicit SoundManager(QWidget *parent = 0);
    ~SoundManager();

private:
    QMediaPlayer *soundPlayer, *level1;
};

#endif // SOUNDMANAGER_H
