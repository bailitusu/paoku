//
//  Entity.h
//  PaoKu
//
//  Created by zc on 14-10-12.
//
//

#ifndef __PaoKu__Entity__
#define __PaoKu__Entity__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class Entity : public CCNode {
public:
    Entity();
    CCSprite * getSprite();
    void bindSprite(CCSprite *sprite);
private:
    CCSprite * msprite;
};

#endif /* defined(__PaoKu__Entity__) */
