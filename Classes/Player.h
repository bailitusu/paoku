//
//  Player.h
//  PaoKu
//
//  Created by zc on 14-10-12.
//
//

#ifndef __PaoKu__Player__
#define __PaoKu__Player__

#include <stdio.h>
#include "Entity.h"
#include "FlowWord.h"
class Player : public Entity {
public:
    Player();
    CREATE_FUNC(Player);
    virtual bool init();
    
    void jump();
    bool isJumping();
    void jumpEnd();
    void hit();
    int getHP();
    CCRect getBoundBox();
    
    
private:
    int jumpTimes;
    int mHP;
};
#endif /* defined(__PaoKu__Player__) */
