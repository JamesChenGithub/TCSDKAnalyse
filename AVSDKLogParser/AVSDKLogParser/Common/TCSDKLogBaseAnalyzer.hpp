//
//  TCSDKLogBaseAnalyzer.hpp
//  AVSDKLogParser
//
//  Created by AlexiChen on 2017/3/20.
//  Copyright © 2017年 AlexiChen. All rights reserved.
//

#ifndef TCSDKLogBaseAnalyzer_hpp
#define TCSDKLogBaseAnalyzer_hpp

#include <stdio.h>
#include <string>
#include <fstream>
#include <list>
#include <memory>

#include "TCSDKLogResultItem.hpp"
#include "ITCSDKLogAnalyzer.h"



using namespace std;
namespace TCSDKLog
{
    class TCSDKLogBaseAnalyzer : public ITCSDKLogAnalyzer
    {
    protected:
        string          _logPath;
        
        mutable bool    _hasCheckSupport;
        bool            _isSupportLog;          // 是否是支持的日志
        ifstream        _logStream;             // 如果是，则使_logStream进行读写
        fstream         _resultStream;
        
        TCResultList    _globalList;
        
        TCResultList    _processList;
        
        TCResultList    _resultList;
        
    public:
        virtual ~TCSDKLogBaseAnalyzer();
        TCSDKLogBaseAnalyzer(const string logPath, ITCSDKLogAnalyzerObserver *observer);
        
    protected:
        TCSDKLogBaseAnalyzer();

        
    public:
        virtual bool checkSupportLog() {return true;}
        
    public:
        // 是否是腾讯云的日志
        virtual bool isTCSDK();
        
    
        
    public:
        // 分析步骤
        virtual void startAnalyseLog();
        // 1. 全局分析
        virtual bool isSupportGlobalAnalyse() const { return true;}
        virtual void analyseGlobalLog() {};
        
        // 2.逐行分行日志
        virtual bool isSupportAnalyseByLine() const {return true;}
        virtual void analyseLogByLine() {};
        
        // 3. 当次结果统计分析
        virtual bool isSupportAnalyseByResult() const { return true;}
        virtual void analyseLogByResult() {};
        
        
    protected:
        const TCResultList& getGlobalAnalyseList() const { return _globalList;}
        const TCResultList& getProcessAnalyseList() const { return _processList;}
        const TCResultList& getResultAnalyseList() const { return _resultList;}
        
    };
}

#endif /* TCSDKLogBaseAnalyzer_hpp */
