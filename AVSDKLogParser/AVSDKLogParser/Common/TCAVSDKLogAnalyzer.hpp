//
//  TCAVSDKLogAnalyzer.hpp
//  AVSDKLogParser
//
//  Created by AlexiChen on 2017/3/20.
//  Copyright © 2017年 AlexiChen. All rights reserved.
//

#ifndef TCAVSDKLogAnalyzer_hpp
#define TCAVSDKLogAnalyzer_hpp

#include <stdio.h>
#include "TCSDKLogBaseAnalyzer.hpp"
#include "TCSDKLogResultItem.hpp"

using namespace std;
namespace TCSDKLog
{
    class TCAVSDKLogAnalyzer : public TCSDKLogBaseAnalyzer
    {
    public:
        TCAVSDKLogAnalyzer(const string logPath, ITCSDKLogAnalyzerObserver *observer);
    protected:
        TCAVSDKLogAnalyzer();
    public:
        virtual bool checkSupportLog();
        
        void analyseGlobalLog();
        
        // 2.逐行分行日志
        
        void analyseLogByLine();
        
        // 3. 当次结果统计分析
        void analyseLogByResult();
    };
    
    
    class TCAVSDKGlobalInfoItem : public TCSDKLogResultItem
    {
        
    };
}

#endif /* TCAVSDKLogAnalyzer_hpp */
