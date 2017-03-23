//
//  TCSDKLogResultItem.hpp
//  AVSDKLogParser
//
//  Created by AlexiChen on 2017/3/20.
//  Copyright © 2017年 AlexiChen. All rights reserved.
//

#ifndef TCSDKLogResultItem_hpp
#define TCSDKLogResultItem_hpp

#include <stdio.h>
#include <string>
#include "TCSDKConst.h"

using namespace std;
namespace TCSDKLog
{
    class TCSDKLogResultItem
    {
    private:
        int    _eventType;  // 事件类型，对应TCSDKLogType
        int    _eventID;    // 事件ID，对应TCAVSDKLogEvent, TCIMSDKLogEvent, TCILiveSDKLogEvent
        TCSDKResultLevel    _resultLevel;   // 行为结果
    private:
        string _eventName;          // 事件名
        string _eventTime;          // 时间
        string _parseResult;        // 执行结果
        string _recommendHandle;    // 推荐处理结果
        
    public:
        ~TCSDKLogResultItem();
    private:
        TCSDKLogResultItem(){};
        
    public:
        TCSDKLogResultItem(const int eventType, const int eventID, const string aEventName, const string aEventTime);
        
        void setParseResult(const string result);
        
        string getResultString() const;
    };
    
    typedef list<shared_ptr<TCSDKLogResultItem>> TCResultList;
}

#endif /* TCSDKLogResultItem_hpp */
