//
//  guaiwu.h
//  PaoKu
//
//  Created by zc on 14-10-12.
//
//

#ifndef __PaoKu__guaiwu__
#define __PaoKu__guaiwu__

#include <stdio.h>
#include "cocos2d.h"
#include "Entity.h"
#include "Player.h"
USING_NS_CC;

class guaiwu : public Entity {
public:
    guaiwu();
    CREATE_FUNC(guaiwu);
    virtual bool init();

    void show();
    void hide();
    void reset();
    bool isRun();
    bool isPengZhuang(Player* zj);
private:
    bool misRun;//标记怪物是否在运动
};

#endif /* defined(__PaoKu__guaiwu__) */
