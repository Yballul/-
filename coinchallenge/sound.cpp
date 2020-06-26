#include "sound.h"

Sound::Sound(coin* button, QString string)
{
    connect(button, &coin::clicked, [=](){
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
