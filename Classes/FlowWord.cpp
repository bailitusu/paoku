//
//  FlowWord.cpp
//  PaoKu
//
//  Created by zc on 14-10-14.
//
//

#include "FlowWord.h"
using namespace cocos2d::extension;
bool FlowWord::init() {
    mText = CCLabelTTF::create("", "Arial", 35);
    mText->setColor(ccc3(255, 0, 0));
    mText->setAnchorPoint(ccp(1,0));
    mText->setVisible(false);
    this->addChild(mText);
    return true;
}

void FlowWord::showWord(const char *text, cocos2d::CCPoint pos) {
    mText->setString(text);
    mText->setPosition(pos);
    mText->setVisible(true);
    
    CCActionInterval* scaleBig = CCScaleTo::create(0.3f, 2.5f,2.5f);
    CCActionInterval* scaleSmall = CCScaleTo::create(0.5f, 0.5f, 0.5f);
    
    CCCallFunc* callFun = CCCallFunc::create(this, callfunc_selector(FlowWord::flowEnd));
    CCActionInterval* act = CCSequence::create(scaleBig,scaleSmall,callFun,NULL);
    
    mText->runAction(act);
    
}

void FlowWord::flowEnd() {
    mText->setVisible(false);
    mText->removeFromParentAndCleanup(true);
}