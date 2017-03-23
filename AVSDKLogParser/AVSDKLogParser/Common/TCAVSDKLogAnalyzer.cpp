//
//  TCAVSDKLogAnalyzer.cpp
//  AVSDKLogParser
//
//  Created by AlexiChen on 2017/3/20.
//  Copyright © 2017年 AlexiChen. All rights reserved.
//

#include "TCAVSDKLogAnalyzer.hpp"

#include <cctype>
#include <algorithm>
#include <string>
#include <iostream>

namespace TCSDKLog
{
    
    TCAVSDKLogAnalyzer::TCAVSDKLogAnalyzer(const string logPath, ITCSDKLogAnalyzerObserver *observer) : TCSDKLogBaseAnalyzer(logPath, observer)
    {
        
    }
    TCAVSDKLogAnalyzer::TCAVSDKLogAnalyzer() : TCSDKLogBaseAnalyzer()
    {
        
    }
    
    bool TCAVSDKLogAnalyzer::checkSupportLog()
    {
        ifstream checkStream;
        checkStream.open(_logPath);
        
        if (!checkStream)
        {
            if (_parseObserverRef)
            {
                _parseObserverRef->onITCSDKLogAnalyzerInitCompleted(this, ETCSDKParse_LogNotExisted, "文件不存在");
            }
            return false;
        }
        else
        {
            const int keysCount = 5;
            string keywords[keysCount] = {"opensdk","startcontex", "enterroom", "exitroom", "avdata"};
            string line;
            bool isFind = false;
            while (getline(checkStream, line))
            {
                if (line.length() > 0)
                {
                    transform(line.begin(), line.end(), line.begin(), ::tolower);
                    
                    int index = 0;
                    while (index < keysCount)
                    {
                        string key = keywords[index++];
                        string::size_type idx = line.find(key);
                        if (idx != string::npos)
                        {
                            isFind = true;
                            cout << line << "找到关键字" << key << endl;
                            break;
                        }
                        
                    }
                    
                    if (isFind)
                    {
                        break;
                    }
                }
            }
            
            checkStream.close();
            
            if (!isFind)
            {
                if (_parseObserverRef)
                {
                    _parseObserverRef->onITCSDKLogAnalyzerInitCompleted(this, ETCSDKParse_NotSupportLog, "不是AVSDK的日志");
                }

            }
            return isFind;
        }
    }
    
    void TCAVSDKLogAnalyzer::analyseGlobalLog()
    {
        cout << "开始全局分析:主要查找关键全局的信息（帐号信息，执行startContext次数）" << endl;
        
        if ()
        {
        
        }
        
    }
    
    // 2.逐行分行日志
    
    void TCAVSDKLogAnalyzer::analyseLogByLine()
    {
        cout << "开始逐行分析" << endl;
    }
    
    // 3. 当次结果统计分析
    void TCAVSDKLogAnalyzer::analyseLogByResult()
    {
        cout << "开始统计分析" << endl;
    }
}
