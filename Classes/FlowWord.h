//
//  FlowWord.h
//  PaoKu
//
//  Created by zc on 14-10-14.
//
//

#ifndef __PaoKu__FlowWord__
#define __PaoKu__FlowWord__

#include <stdio.h>
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
class FlowWord : public CCNode {
public:
    CREATE_FUNC(FlowWord);
    bool init();
    void showWord(const char* text,CCPoint pos);
private:
    CCLabelTTF* mText;
    void flowEnd();
};
#endif /* defined(__PaoKu__FlowWord__) */
