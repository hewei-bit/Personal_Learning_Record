#include "tv_remote.h"


Romote::Romote():TV()
{
    cout << " Romote()"<<endl;
}

Romote::~Romote(){
    cout << " ~Romote()"<<endl;
}

void Romote::TVchannelUP()
{
    int channel = this->getChannel();
    this->setChannel(++channel);
}

void Romote::TVchannelDOWN()
{
    int channel = this->getChannel();
    this->setChannel(--channel);
}

void Romote::TVchannelset(int value)
{
    int channel = value;
    this->setChannel(--channel);
}

void Romote::TVVolumeUP()
{
    int volume = this->getVolume();
    this->setVolume(++volume);
}

void Romote::TVVolumeDOWN()
{
    int volume = this->getVolume();
    this->setVolume(--volume);
}

void Romote::TVPower()
{
    this->setPower();
}
