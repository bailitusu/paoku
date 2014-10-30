//
//  guankaScene.h
//  PaoKu
//
//  Created by zc on 14-10-12.
//
//

#ifndef __PaoKu__guankaScene__
#define __PaoKu__guankaScene__

#include <stdio.h>
#include "cocos2d.h"
#include "Player.h"
#include "cocos-ext.h"
USING_NS_CC;

class guankaScene : public CCLayer {
public:
    static CCScene* scene();
    virtual bool init();
    CREATE_FUNC(guankaScene);
    virtual void update(float fDelta);
    
    void jumpBtn();
    void jumpEvent(CCObject* input,extension::CCControlEvent event);
private:
    void initBground();
    CCAnimate* creatDonghua(float);
    
    CCSprite* msprite1;
    CCSprite* msprite2;
    Player* zhujiao;
    CCAnimate* act;
    CCAnimation* donghua;
    
    float mScore;
    CCLabelTTF* mLabScore;
    extension::CCControlSlider* mHptiao;
    void ScoreLabcreat();
    void HpTiaocreat();
    
};
#endif /* defined(__PaoKu__guankaScene__) */
