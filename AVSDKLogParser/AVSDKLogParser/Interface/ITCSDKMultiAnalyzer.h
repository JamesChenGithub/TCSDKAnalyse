//
//  ITCSDKMultiAnalyzer.h
//  AVSDKLogParser
//
//  Created by AlexiChen on 2017/3/20.
//  Copyright © 2017年 AlexiChen. All rights reserved.
//

#ifndef ITCSDKMultiAnalyzer_h
#define ITCSDKMultiAnalyzer_h


#include <stdio.h>
#include <string>

using namespace std;
namespace TCSDKLog
{
    class ITCSDKLogMultiAnalyzer
    {
    public:
        virtual ~ITCSDKLogMultiAnalyzer () {};
        
    public:
        ITCSDKLogMultiAnalyzer(const string logDir){};
        
    public:
        virtual void analyseByEachFile() = 0;
        
        virtual void mergeAnalyseResult() = 0;
        
        
    };
}

#endif /* ITCSDKMultiAnalyzer_h */
