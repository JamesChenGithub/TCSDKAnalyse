//
//  AVSDKExecuteInfo.hpp
//  AVSDKLogParser
//
//  Created by AlexiChen on 2017/3/20.
//  Copyright © 2017年 AlexiChen. All rights reserved.
//

#ifndef AVSDKExecuteInfo_hpp
#define AVSDKExecuteInfo_hpp

#include <stdio.h>
#include <string>

using namespace std;

namespace AVSDKLog
{
    //
    class AVSDKEnterRoomInfo
    {
    private:
        bool    _needShow;
        string  _enterRoomTime;         // 进房间说明
        string  _interfaceAddress;      // 接口机地址说明
        string  _connectInfo;           // 连接情况
    };
    
    class AVSDKRunInfo
    {
        
    };
    
    class AVSDKExitRoomInfo
    {
    private:
        bool    _needShow;
        string  _exitRoomTime;         // 进房间说明
    };
    
    
    class AVSDKLiveInfo
    {
    private:
        bool    _needShow;
        string  _exitRoomTime;         // 进房间说明
        
        AVSDKEnterRoomInfo _enterRoomInfo;
        
        AVSDKExitRoomInfo  _exitRoomInfo;
        
        
    };
    
    
    
    class AVSDKExecuteInfo
    {
    private:
        // 单次执行的本信息  startContext - stopContext之间的信息
        string _avsdkVersion;
        string _sdkAppid;
        string _tinyid;
        string _platform;
        
    private:
        // 单次直播中出现的信息
        
        
        
    };

}


#endif /* AVSDKExecuteInfo_hpp */
