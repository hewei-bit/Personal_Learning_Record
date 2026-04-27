#include "kitty.h"
void kitty::eat()
{
    cout << "吃鱼"<<endl;
    weight += 0.2;

    if(weight >=2.0)
        cout << "你太肥了,你当前体重:" << weight << "kg" << endl;
}

void kitty::sleep()
{
    cout << "睡觉" <<endl;
}

void kitty::actingCute()
{
    cout << "喵喵..."<<endl;
}

void kitty::showInfo()
{
  cout << "体重:" << weight << "kg"<<endl;
  cout << "性别:" << (sex == 'M'?"公":"母") <<endl;
  cout << "毛色:";
  switch (furcolor) {
  case 0:
      cout << "白色";
      break;
  case 1:
      cout << "金色";
      break;
  case 2:
      cout << "棕色";
      break;
  case 3:
      cout << "杂色";
      break;
  }
  cout << endl;
}

void kitty::test()
{

}

float kitty::getWeight() const
{
return weight;
}

void kitty::setWeight(float value)
{
weight = value;
}

char kitty::getSex() const
{
return sex;
}

void kitty::setSex(char value)
{
sex = value;
}

color kitty::getFurcolor() const
{
return furcolor;
}

void kitty::setFurcolor(const color &value)
{
furcolor = value;
}
