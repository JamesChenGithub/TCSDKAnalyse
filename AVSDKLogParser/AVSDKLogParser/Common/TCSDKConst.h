//
//  TCSDKConst.h
//  AVSDKLogParser
//
//  Created by AlexiChen on 2017/3/20.
//  Copyright © 2017年 AlexiChen. All rights reserved.
//

#ifndef TCSDKConst_h
#define TCSDKConst_h

#include <list>
#include <memory>

using namespace std;
namespace TCSDKLog
{
    
    typedef enum {
        ETCSDKParse_OK,             // 检查正常
        ETCSDKParse_LogNotExisted,  // 日志不存在
        ETCSDKParse_NotSupportLog,  // 不支持的日志
        
    }TCSDKParseErrCode;
    
    // 日志分析结果级别
    typedef enum{
        ETCSDK_OKLog,                                   // 正常结果
        ETCSDK_WarningLog,                              // 警告结果，有潜在错误，需要再排查
        ETCSDK_ErrorLog,                                // 行为有误错误结果
    } TCSDKResultLevel;
    
    // 日志分类
    typedef enum{
        ETCSDK_UnkownLog = 0x01000000,                  // 未知日志
        ETCSDK_AVSDKLog = 0x01000000,                   // AVSDKLog
        ETCSDK_IMSDKLog = 0x02000000,                   // IMSDKLog
        ETCSDK_ILiveLog = 0x04000000,                   // ILiveSDKLog
    } TCSDKLogType;
    
    
    
    // AVSDK事件分析处理
    typedef enum {
        EAVSDKLog_None,                                 // 默认值
       // EAVSDKLog_ISAVSDKLog,                           // 是否是AVSDK的日志
        
        EAVSDKLog_OpenSDK,                              // 日志事件
        EAVSDKLog_StartContex_Begin,                    // StartContext
        EAVSDKLog_StartContex_Succ_Key,                 // StartContext
        EAVSDKLog_StartContex_Succ,                     // StartContext
        EAVSDKLog_StartContex_Failed,                   // StartContext
        EAVSDKLog_StartContex_Analyse_Result,           //
        
        EAVSDKLog_StopContex_Begin,                     // StopContext
        EAVSDKLog_StopContex_Succ,                      // StopContext
        EAVSDKLog_StopContex_Failed,                    // StopContext
        
        EAVSDKLog_LiveRun_EnterRoom_Begin,              // 进房分析
        EAVSDKLog_LiveRun_EnterRoom_Succ,               // 进房分析
        EAVSDKLog_LiveRun_EnterRoom_Failed,             // 进房分析
        
        EAVSDKLog_LiveRun_Event,                        // 核心事件统计
        EAVSDKLog_LiveRun_SendRecv,                     // 发送接收数据统计
        EAVSDKLog_LiveRun_HeartPulse,                   // 心跳包统计
        EAVSDKLog_LiveRun_ExitRoom,                     // 出房分析
        
        EAVSDKLog_Complex_Event = 0x10000000,           // 复合统计事件超值
        
        // 复合分析结果
        EAVSDKLog_AllCount = 0x00FFFFFF
    } TCAVSDKLogEvent;
    
    
    // IMSDK事件分析处理
    typedef enum {
        EIMSDKLog_None,
        EIMSDKLog_ISIMSDKLog,                           // 是否是IMSDK的日志
        
        EIMSDKLog_Complex_Event = 0x10000000,           // 复合统计事件超值
        // 复合分析结果
        EIMSDKLog_AllCount = 0x00FFFFFF
    } TCIMSDKLogEvent;
    
    // ILiveSDK事件分析处理
    typedef enum {
        EILiveSDKLog_None,
        EILiveSDKLog_ISILiveSDKLog,                     // 是否是IMSDK的日志
        
        EILiveSDKLog_Complex_Event = 0x10000000,        // 复合统计事件超值
        // 复合分析结果
        EILiveSDKLog_AllCount = 0x00FFFFFF
    } TCILiveSDKLogEvent;
    
}



#endif /* TCSDKConst_h */
