#include "AllyCenter.h"
#include "Observer.h"

/***********   AllyCenter    ****************/
AllyCenter::AllyCenter()
{
    cout << "大吉大利，今晚吃鸡!" << endl;
}

// 加入玩家
void AllyCenter::join(Observer *player)
{
    if (playerList.size() == 4)
    {
        cout << "玩家已满" << endl;
        return;
    }
    cout << "玩家" << player->getName().c_str() << "加入" << endl;
    playerList.push_back(player);
    if (playerList.size() == 4)
    {
        cout << "组队成功，不要怂，一起上！" << endl;
    }
}
// 移除玩家
void AllyCenter::remove(Observer *player)
{
    printf("玩家 %s 退出\n", player->getName().c_str());
    int i = 0;
    for (auto pl : playerList)
    {
        if (pl->getName() == player->getName())
        {
            break;
        }
        i++;
    }
    for (; i < playerList.size(); i++)
    {
        playerList[i] = playerList[i + 1];
    }
    playerList.pop_back();
    //
    // for (vector<Observer *>::iterator iter = playerList.begin(); iter != playerList.end();)
    // { //从vector中删除指定的某一个元素
    //     if (*iter == player)
    //     {
    //         iter = playerList.erase(iter);
    //     }
    //     else
    //     {
    //         iter++;
    //     }
    // }
}
/***********   AllyCenter    ****************/

/**********   AllyCenterController    *******/
AllyCenterController::AllyCenterController()
{
}
// 实现通知方法
void AllyCenterController::notify(INFO_TYPE infoType, std::string name)
{
    switch (infoType)
    {
    case RESOURCE:
        for (Observer *obs : playerList)
        {
            if (obs->getName() != name)
            {
                ((Player *)obs)->come();
            }
        }
        break;
    case HELP:
        for (Observer *obs : playerList)
        {
            if (obs->getName() != name)
            {
                ((Player *)obs)->help();
            }
        }
        break;
    default:
        printf("Nothing\n");
    }
}
/**********   AllyCenterController    *******/