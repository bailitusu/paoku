//
//  guankaScene.cpp
//  PaoKu
//
//  Created by zc on 14-10-12.
//
//

#include "guankaScene.h"
using namespace cocos2d::extension;
#include "guaiwuManager.h"
CCScene* guankaScene::scene() {
    CCScene* scene = CCScene::create();
    guankaScene *gklayer = guankaScene::create();
    scene->addChild(gklayer);
    return scene;
}

bool guankaScene::init() {
    CCSize ScreenSize = CCDirector::sharedDirector()->getVisibleSize();

    CCLabelTTF* pLabel = CCLabelTTF::create("天天酷跑", "Arial", 40);
    pLabel->setPosition(ccp(ScreenSize.width/2, ScreenSize.height-50));
    this->addChild(pLabel, 2);

    zhujiao = Player::create();
    zhujiao->bindSprite(CCSprite::create("zhujiao1.png"));
    zhujiao->setPosition(ccp(200, ScreenSize.height/4));
    this->addChild(zhujiao,1);
    zhujiao->getSprite()->runAction(creatDonghua(0.02f));
    this->scheduleUpdate();
    initBground();
    jumpBtn();

    
    guaiwuManager* GwManager = guaiwuManager::create();
    GwManager->gwBindPlay(zhujiao);
    this->addChild(GwManager,4);
    
    ScoreLabcreat();
    HpTiaocreat();
    return true;
}

CCAnimate* guankaScene::creatDonghua(float speed) {
    int Picnum = 13;
    CCSpriteFrame* spFrame = NULL;
    CCArray* frameArray = CCArray::create();
    for (int i = 1; i<=Picnum; i++) {
        spFrame = CCSpriteFrame::create(CCString::createWithFormat("zhujiao%d.png",i)->getCString(), CCRectMake(0, 0, 200, 200));
        frameArray->addObject(spFrame);
    }
    
    donghua = CCAnimation::createWithSpriteFrames(frameArray);
    
    donghua->setLoops(-1);
    donghua->setDelayPerUnit(speed);
    

    act = CCAnimate::create(donghua);
    
    return act;
}


void guankaScene::initBground() {
    CCSize ScreenSize = CCDirector::sharedDirector()->getVisibleSize();

    msprite1 = CCSprite::create("guankaBG.jpg");
    msprite1->setPosition(ccp(ScreenSize.width/2, ScreenSize.height/2));
    this->addChild(msprite1,0);

    msprite2 = CCSprite::create("guankaBG.jpg");
    msprite2->setPosition(ccp(ScreenSize.width+ScreenSize.width/2, ScreenSize.height/2));
    msprite2->setFlipX(true);
    this->addChild(msprite2,0);
    
}

void guankaScene::update(float fDelta) {
    int posX1 = msprite1->getPositionX();
    int posX2 = msprite2->getPositionX();
    
    int speed = (mScore/50+1) * 10;

    
    posX1 = posX1-speed;
    posX2 = posX2-speed;
    
    CCSize mapSize = msprite1->getContentSize();
    if(posX1<-mapSize.width/2) {
        posX2 = mapSize.width/2;
        posX1 = mapSize.width+mapSize.width/2;
    }
    if (posX2<-mapSize.width/2) {
        posX1 = mapSize.width/2;
        posX2 = mapSize.width+mapSize.width/2;
    }
    
    msprite1->setPositionX(posX1);
    msprite2->setPositionX(posX2);
    
    mScore = mScore+0.2f;
    mLabScore->setString(CCString::createWithFormat("Score:%.0f",mScore)->getCString());
    
    mHptiao->setValue(zhujiao->getHP());
    

}

void guankaScene::jumpBtn() {
    CCSize screenSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCLabelTTF* jumptext = CCLabelTTF::create("Jump!!", "Arial", 40);
    CCScale9Sprite* noDownbtn = CCScale9Sprite::create("button.png");
    CCScale9Sprite* downbtn = CCScale9Sprite::create("buttonDown.png");
    CCControlButton* Btnjump = CCControlButton::create(jumptext, noDownbtn);
    Btnjump->setPosition(ccp(screenSize.width-80, 50));
    Btnjump->setBackgroundSpriteForState(downbtn, extension::CCControlStateHighlighted);
    Btnjump->addTargetWithActionForControlEvents(this, cccontrol_selector(guankaScene::jumpEvent),CCControlEventTouchDown);
    this->addChild(Btnjump,1);
}

void guankaScene::jumpEvent(CCObject* input,extension::CCControlEvent event) {
    zhujiao->jump();
}

void guankaScene::ScoreLabcreat() {
    mScore = 0;
    CCSize PmuSize = CCDirector::sharedDirector()->getVisibleSize();
    mLabScore = CCLabelTTF::create("Score:0", "Arial", 35);
    mLabScore->setPosition(ccp(0, PmuSize.height));
    mLabScore->setAnchorPoint(ccp(0, 1));
    this->addChild(mLabScore,2);
}

void guankaScene::HpTiaocreat() {
    CCSize pMuSize = CCDirector::sharedDirector()->getVisibleSize();
    
    mHptiao = CCControlSlider::create(CCSprite::create("xuetiaoBg.png"), CCSprite::create("xuetiao.png"), CCSprite::create("111.png"));
    mHptiao->setPosition(ccp(mHptiao->getContentSize().width/2, pMuSize.height-mHptiao->getContentSize().height-mLabScore->getContentSize().height));
    mHptiao->setTouchEnabled(false);
    mHptiao->setMaximumValue(1000);
    mHptiao->setMinimumValue(0);
    mHptiao->setValue(1000);
    this->addChild(mHptiao,3);
}


