//
//  TCSDKLogBaseAnalyzer.cpp
//  AVSDKLogParser
//
//  Created by AlexiChen on 2017/3/20.
//  Copyright © 2017年 AlexiChen. All rights reserved.
//

#include "TCSDKLogBaseAnalyzer.hpp"

namespace TCSDKLog
{
    TCSDKLogBaseAnalyzer::~TCSDKLogBaseAnalyzer()
    {
        _logPath = "";
        
        if (_logStream)
        {
            _logStream.close();
        }
        
        if (_resultStream)
        {
            _resultStream.close();
        }
        
        _globalList.clear();
        _processList.clear();
        _resultList.clear();
    }
    
    
    TCSDKLogBaseAnalyzer::TCSDKLogBaseAnalyzer() : ITCSDKLogAnalyzer()
    {
        
    }
    
    TCSDKLogBaseAnalyzer::TCSDKLogBaseAnalyzer(const string logPath, ITCSDKLogAnalyzerObserver *observer) : TCSDKLogBaseAnalyzer()
    {
        _logPath = logPath;
        _parseObserverRef = observer;
    }
    
    bool TCSDKLogBaseAnalyzer::isTCSDK()
    {
        if (!_hasCheckSupport)
        {
            _hasCheckSupport = true;
            
            bool check = checkSupportLog();
            return check;
        }
        else
        {
            return _isSupportLog;
        }
        
    }
    
    void TCSDKLogBaseAnalyzer::startAnalyseLog()
    {
        _isSupportLog = isTCSDK();
        
        if (_isSupportLog)
        {
            _logStream.open(_logPath);
            
            if (isSupportGlobalAnalyse())
            {
                analyseGlobalLog();
            }
            
            if (isSupportAnalyseByLine())
            {
                analyseLogByLine();
            }
            
            if (isSupportAnalyseByResult())
            {
                analyseLogByResult();
            }
        }
    }
}
