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
#include <map>
#include <stack>

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
            const int keysCount = 6;
            string keywords[keysCount] = {"opensdk", "startcontex", "enterroom", "exitroom", "avdata", "stopcontext"};
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
        _logStream.seekg(0, ios::beg);
        const int keysCount = 5;
        // TODO : 使用map
        
        map<string, int> globalMap;
        globalMap.insert(pair<string, int>("opensdk", EAVSDKLog_OpenSDK));
        globalMap.insert(pair<string, int>("******StartContexting...", EAVSDKLog_StartContex_Begin));
        globalMap.insert(pair<string, int>("enterroom", EAVSDKLog_LiveRun_EnterRoom));
        globalMap.insert(pair<string, int>("exitroom", EAVSDKLog_LiveRun_ExitRoom));
        globalMap.insert(pair<string, int>("stopcontext", EAVSDKLog_StopContex));
        
        
        map<string, int>::iterator gmi;
        
        string line;
        bool isFind = false;
        while (getline(_logStream, line))
        {
            if (line.length() > 0)
            {
                transform(line.begin(), line.end(), line.begin(), ::tolower);
                for (gmi = globalMap.begin(); gmi != globalMap.end(); gmi++)
                {
                    string key = gmi->first;
                    string::size_type idx = line.find(key);
                    if (idx != string::npos)
                    {
                        isFind = true;
                        cout << line << "找到关键字" << key << endl;
                        // 创建一个分析词条
                        string logtime = line.substr(1,23);
                        
                        shared_ptr<TCSDKLogResultItem> item(new TCSDKLogResultItem(ETCSDK_AVSDKLog, gmi->second, gmi->first, logtime));
                        item->setLogText(line);
                        _globalList.push_back(item);
                        break;
                    }
                }
            }
        }
        
        
        // TODO : 预分析结果
        TCResultList::iterator iter;
        int index = 0;
        for (iter = _globalList.begin(); iter != _globalList.end(); iter++)
        {
            // TCSDKLogResultItem item = (TCSDKLogResultItem)(*iter);
            shared_ptr<TCSDKLogResultItem> item = *iter;
            cout << index++ << " : " <<item->getResultString() << endl;
        }
        
        if (!isFind)
        {
            if (_parseObserverRef)
            {
                _parseObserverRef->onITCSDKLogAnalyzerInitCompleted(this, ETCSDKParse_NotSupportLog, "不是AVSDK的日志");
            }
            
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
