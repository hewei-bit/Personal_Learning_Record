#include "tv_remote.h"

bool TV::power = 0;
int TV::volume = 50;
int TV::channel = 20;

TV::TV()
{
    cout << " TV() "<<endl;
}

TV::~TV()
{
    cout << " ~TV() "<<endl;
}

void TV::setChannel(int value)
{
    channel = value;
    cout << "The channel is "<< channel <<endl;
}

void TV::setVolume(int value)
{
    volume = value;
    cout << "The volume is "<< volume <<endl;
}

int TV::getChannel()
{
    return channel;
}

int TV::getVolume()
{
    return volume;
}

void TV::setPower()
{
    power = !power;
    if (power == 1)
    {
        cout << "The power is on " <<endl;
    }
    if (power == 0)
    {
        cout << "The power is off " <<endl;
    }

}
