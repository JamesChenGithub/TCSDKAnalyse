//
//  TCSDKLogResultItem.cpp
//  AVSDKLogParser
//
//  Created by AlexiChen on 2017/3/20.
//  Copyright © 2017年 AlexiChen. All rights reserved.
//

#include "TCSDKLogResultItem.hpp"

namespace TCSDKLog
{
    TCSDKLogResultItem::~TCSDKLogResultItem()
    {
        _eventName = "";
        _eventTime = "";
        _logText = "";
        _parseResult = "";
        _recommendHandle = "";
    }
    TCSDKLogResultItem::TCSDKLogResultItem(const int eventtype, const int eventID, const string aEventName, const string aEventTime):_resultLevel(ETCSDK_OKLog)
    {
        _eventType = eventtype;
        _eventID = eventID;
        _eventName = aEventName;
        _eventTime = aEventName;
        _parseResult = "";
        _recommendHandle = "无";
    }
    
    void TCSDKLogResultItem::setLogText(const string log)
    {
        _logText = log;
        _parseResult = log;
    }
    
    void TCSDKLogResultItem::setParseResult(const string result)
    {
        _parseResult = result;
    }
    
    string TCSDKLogResultItem::getResultString() const
    {
        // return "事件名称：" + _eventName + " | 时间：" + _eventTime + " | 分析结果：" + _parseResult + " | 推荐处理："+_recommendHandle;
        return _parseResult;
    }
}
