#include "bgmusic.h"
#include <QSound>
#include "mybutton.h"


BGMusic::BGMusic()
{

}

void BGMusic::setBasic(QMainWindow* a, QString s)
{
    window = a;
    address = s;
    sound = new QSound(address);

}

void BGMusic::check()
{

    if (window->isHidden())
        sound->stop();


}

void BGMusic::play()
{
    sound->setLoops(-1);
    sound->play();
}

void BGMusic::playForOnce()
{
    sound->play();
}

void BGMusic::setButton()
{


    //静音按钮1
    mutebutton1 = new MyButton(NO_MUTE1);
    mutebutton1->setParent(window);
    mutebutton1->move(window->width() - mutebutton1->width(), window->height() - mutebutton1->height());

    //静音按钮2
    mutebutton2 = new MyButton(MUTE1);
    mutebutton2->setParent(window);
    mutebutton2->move(window->width() - mutebutton2->width(), window->height() - mutebutton2->height());
    mutebutton2->hide();
    mutebutton2->setAttribute(Qt::WA_TransparentForMouseEvents, true);



    connect(mutebutton1, &MyButton::clicked, [=](){
       mutebutton1->hide();
       mutebutton2->show();
       sound->stop();
       mutebutton2->setAttribute(Qt::WA_TransparentForMouseEvents, false);
    });

    connect(mutebutton2, &MyButton::clicked, [=](){
        mutebutton2->hide();
        mutebutton1->show();
        sound->play();
        mutebutton2->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    });

}
