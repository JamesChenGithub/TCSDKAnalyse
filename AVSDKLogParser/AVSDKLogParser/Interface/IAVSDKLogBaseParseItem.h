//
//  ITCSDKLogBaseParseItem.h
//  AVSDKLogParser
//
//  Created by AlexiChen on 2017/3/20.
//  Copyright © 2017年 AlexiChen. All rights reserved.
//

#ifndef ITCSDKLogBaseParseItem_h
#define ITCSDKLogBaseParseItem_h

#include <stdio.h>
#include <string>
#include "TCSDKLogResultItem.h"

using namespace std;
namespace TCSDKLog
{
    class ITCSDKLogBaseParseItem
    {
    private:
        string  _parseLog;                   // 待分析的日志
        string  _parsePattern;               // 待分析的日志的模式
        TCSDKLogResultItem *_result;         // 分析结果
    
        
    public:
        virtual ~ITCSDKLogBaseParseItem(){};
        
    public:
        virtual configWith(string logline) = 0;
        
        virtual void parseLog() = 0;
        virtual string getParseResult() const = 0;
        
    private:
        virtual string getPattern() const = 0 ;
    };
}

#endif /* ITCSDKLogBaseParseItem_h */
