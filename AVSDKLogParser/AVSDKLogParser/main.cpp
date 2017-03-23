//
//  main.c
//  AVSDKLogParser
//
//  Created by AlexiChen on 2017/3/20.
//  Copyright © 2017年 AlexiChen. All rights reserved.
//

#include <stdio.h>
#include "TCAVSDKLogAnalyzer.hpp"

using namespace std;
using namespace TCSDKLog;

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
//    TCAVSDKLogAnalyzer("/Users/alexichen/Library/Developer/Xcode/DerivedData/AVSDKLogParser-bckopuoaenqldgfewzdrltxfpgch/Build/Products/Debug/test.log", NULL);
    const string logpath = "/Users/alexichen/Library/Developer/Xcode/DerivedData/AVSDKLogParser-bckopuoaenqldgfewzdrltxfpgch/Build/Products/Debug/test.log";
    TCAVSDKLogAnalyzer *log = new TCAVSDKLogAnalyzer(logpath, NULL);
    log->startAnalyseLog();
    delete log;
    log = NULL;
    
    return 0;
}
