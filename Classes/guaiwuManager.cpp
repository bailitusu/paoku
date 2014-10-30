//
//  guaiwuManager.cpp
//  PaoKu
//
//  Created by zc on 14-10-12.
//
//

#include "guaiwuManager.h"

bool guaiwuManager::init() {
    creatGuaiwu();
    this->scheduleUpdate(); //开启update函数调用
    return true;
}

void guaiwuManager::creatGuaiwu() {
    mGuaiwuArr = CCArray::create();
    mGuaiwuArr->retain();
    
    guaiwu* monster = NULL;
    for (int i = 0; i<MAX_GUAIWU_NUM;i++) {
        monster = guaiwu::create();
        monster->bindSprite(CCSprite::create("qian.png"));
        monster->reset();
        this->addChild(monster);
        mGuaiwuArr->addObject(monster);
    }

}

void guaiwuManager::update(float delta) {
    CCObject* obj = NULL;
    guaiwu* gw = NULL;
    CCARRAY_FOREACH(mGuaiwuArr, obj){
        gw = (guaiwu*)obj;
        if (gw->isRun()) {
            gw->setPositionX(gw->getPositionX()-4);
            if (gw->getPositionX()<0) {
                gw->hide();
            }
            else if (gw->isPengZhuang(mplayer)) {
                mplayer->hit();
                gw->hide();
            }
        }else {
            gw->show();
        }

    }
    
}

void guaiwuManager::gwBindPlay(Player *pl) {
    mplayer = pl;
}
