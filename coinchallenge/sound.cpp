#include "sound.h"

Sound::Sound(Coin* button, QString string)
{
    connect(button, &Coin::clicked, [=](){
        static QSound * sound = new QSound(string);
        sound->play();
    });
}

Sound::Sound(MyButton* button, QString string)
{
    connect(button, &MyButton::clicked, [=](){
        static QSound * sound = new QSound(string);
        sound->play();
    });
}
