/* XiangGuHuaJi 2016, player.h
 *
 */

#ifndef _XIANGGUHUAJI_PLAYER_H__
#define _XIANGGUHUAJI_PLAYER_H__


#include<string>

#include"definition.h"

#include "ai.h"

namespace XGHJ {

using namespace std;

typedef void (*TPlayerAi)(Info& info); 

class Player
{
public:
    Player();
    Player(string file_name, int id);
    ~Player();

    bool Run(Info &info);

    inline bool     isValid() { return Valid; }

private:
    TPlayerAi       player_ai;
    string          file_name;
    TId             id;
    bool            Valid;
};

}


#endif
