#ifndef TV_REMOTE_H
#define TV_REMOTE_H

#include <iostream>

using namespace std;

class TV
{
public:
    TV();
    ~TV();

    void setChannel(int value);
    int getChannel();

    void setVolume(int value);
    int getVolume();

    void setPower();

private:
    static bool power;
    static int channel;
    static int volume;

};



class Romote:public TV
{
public:
    Romote();
    ~Romote();

    void TVchannelUP();
    void TVchannelDOWN();
    void TVchannelset(int value);
    void TVVolumeUP();
    void TVVolumeDOWN();
    void TVPower();


private:

};




#endif // TV_REMOTE_H
