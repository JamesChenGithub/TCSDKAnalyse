//
//  ITCSDKLogAnalyzer.h
//  AVSDKLogParser
//
//  Created by AlexiChen on 2017/3/20.
//  Copyright © 2017年 AlexiChen. All rights reserved.
//

#ifndef ITCSDKLogAnalyzer_h
#define ITCSDKLogAnalyzer_h

#include <stdio.h>
#include <string>
#include "TCSDKLogResultItem.hpp"

using namespace std;
namespace TCSDKLog
{
    class ITCSDKLogAnalyzer;
    class ITCSDKLogAnalyzerObserver
    {
    public:
        virtual ~ITCSDKLogAnalyzerObserver () {};
        
    public:
        virtual void onITCSDKLogAnalyzerInitCompleted(const ITCSDKLogAnalyzer *analyzer, TCSDKParseErrCode failcode, string errorInfo){};
        virtual void onITCSDKLogAnalyseGlobalCompleted(const ITCSDKLogAnalyzer *analyzer, TCSDKParseErrCode failcode, string errorInfo){};
        virtual void onITCSDKLogAnalyseProcessCompleted(const ITCSDKLogAnalyzer *analyzer, TCSDKParseErrCode failcode, string errorInfo){};
        virtual void onITCSDKLogAnalyseResultCompleted(const ITCSDKLogAnalyzer *analyzer, TCSDKParseErrCode failcode, string errorInfo){};
    };
    
    // 单个日志分析类
    class ITCSDKLogAnalyzer
    {
    protected:
         ITCSDKLogAnalyzerObserver *_parseObserverRef;
    public:
        virtual ~ITCSDKLogAnalyzer () {_parseObserverRef = NULL;}
        
    protected:
        ITCSDKLogAnalyzer(){};
        ITCSDKLogAnalyzer(const string logPath, ITCSDKLogAnalyzerObserver *observer) {_parseObserverRef = observer;};

    public:
        inline void setParseObserver(ITCSDKLogAnalyzerObserver *parseObserver) { _parseObserverRef = parseObserver;}
    public:
        // 是否是腾讯云的日志
        virtual bool isTCSDK() = 0;
        
    public:
        // 分析步骤
        
        virtual void startAnalyseLog() = 0;
        
        // 1. 全局分析
        virtual bool isSupportGlobalAnalyse() const = 0;
        virtual void analyseGlobalLog() = 0;
    
        // 2.逐行分行日志
        virtual bool isSupportAnalyseByLine() const = 0;
        virtual void analyseLogByLine() = 0;
        
        // 3. 当次结果统计分析
        virtual bool isSupportAnalyseByResult() const = 0;
        virtual void analyseLogByResult() = 0;
    };
}


#endif /* ITCSDKLogAnalyzer_h */
