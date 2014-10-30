//
//  guaiwuManager.h
//  PaoKu
//
//  Created by zc on 14-10-12.
//
//

#ifndef __PaoKu__guaiwuManager__
#define __PaoKu__guaiwuManager__

#include <stdio.h>
#include "cocos2d.h"
#include "guaiwu.h"
#include "Player.h"
USING_NS_CC;
#define MAX_GUAIWU_NUM 10
class guaiwuManager : public CCNode {
public:
    CREATE_FUNC(guaiwuManager);
    virtual bool init();
    virtual void update(float delta);
    void gwBindPlay(Player* pl);
private:
    void creatGuaiwu();
    Player* mplayer;
    CCArray* mGuaiwuArr;
    
};

#endif /* defined(__PaoKu__guaiwuManager__) */
