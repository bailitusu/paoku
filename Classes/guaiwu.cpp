//
//  guaiwu.cpp
//  PaoKu
//
//  Created by zc on 14-10-12.
//
//

#include "guaiwu.h"

guaiwu::guaiwu() {
    misRun = false;
}

bool guaiwu::init() {
    return true;
}

void guaiwu::show() {
    if (getSprite()!= NULL) {
        setVisible(true);
        misRun = true;
    }
}

void guaiwu::hide() {
    if (getSprite() != NULL) {
        setVisible(false);
        reset();
        misRun = false;
    }
}

void guaiwu::reset() {
    if (getSprite() != NULL) {
        setPosition(ccp(1136+CCRANDOM_0_1()*2000, 500-CCRANDOM_0_1()*300));
    }
}

bool guaiwu::isRun() {
    return  misRun;
}

bool guaiwu::isPengZhuang(Player *zj){
    CCRect playerRect = zj->getBoundBox();
    CCPoint guaiwuPos = getPosition();
//    std::cout<< guaiwuPos.x << std::endl;
    return playerRect.containsPoint(guaiwuPos);
}




