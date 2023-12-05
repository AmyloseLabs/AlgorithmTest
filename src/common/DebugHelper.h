/********************************************************
 ** @file : DebugHelper.h
 ** @author : Amylose <amyloselabs@naver.com>
 ** @date : 2023-04-06
 ** @version : NA
********************************************************/
#ifndef DEBUGHELPER_H
#define DEBUGHELPER_H

//////////////////////////////////////////////////////////
//// SECTION : Standard Header Includes
//////////////////////////////////////////////////////////
#include <iostream>
#include <mutex>
#include <iomanip>

//////////////////////////////////////////////////////////
//// SECTION : Console Display Sync mutex Defines
//////////////////////////////////////////////////////////
inline std::mutex &sync_mutex() {
    static std::mutex g_debugMutex;
    return g_debugMutex;
}

//////////////////////////////////////////////////////////
//// SECTION : Variable to String convertion
//////////////////////////////////////////////////////////
#define Var2Str(arg)        #arg

//////////////////////////////////////////////////////////
//// SECTION : Console Blank Defines
//////////////////////////////////////////////////////////
#define BL2_     "  "
#define BL3_     "   "
#define BL4_     "    "
#define BL5_     "     "
#define BL6_     "      "
#define BL7_     "       "
#define BL8_     "        "
#define TAB_     BL4_

//////////////////////////////////////////////////////////
//// SECTION : Console Display Color Defines
//////////////////////////////////////////////////////////
#define ARG_RED(arg)        "\033[31m" << arg << "\033[0m"
#define ARG_GREEN(arg)      "\033[32m" << arg << "\033[0m"
#define ARG_YELLOW(arg)     "\033[33m" << arg << "\033[0m"
#define ARG_BLUE(arg)       "\033[34m" << arg << "\033[0m"
#define ARG_MAGENTA(arg)    "\033[35m" << arg << "\033[0m"
#define ARG_CYAN(arg)       "\033[36m" << arg << "\033[0m"

#define STR_RED(arg)        "\033[31m" #arg "\033[0m"
#define STR_GREEN(arg)      "\033[32m" #arg "\033[0m"
#define STR_YELLOW(arg)     "\033[33m" #arg "\033[0m"
#define STR_BLUE(arg)       "\033[34m" #arg "\033[0m"
#define STR_MAGENTA(arg)    "\033[35m" #arg "\033[0m"
#define STR_CYAN(arg)       "\033[36m" #arg "\033[0m"

//////////////////////////////////////////////////////////
//// SECTION : Console Display Sync Guard Defines
//////////////////////////////////////////////////////////
#define SYNC_ST                     {std::lock_guard<std::mutex> lock(sync_mutex());
#define SYNC_EN                     }

//////////////////////////////////////////////////////////
//// SECTION : Debug Log Message Display function Defines
//////////////////////////////////////////////////////////
#define LOGD(MSG)                       SYNC_ST \
                                        std::cout << STR_CYAN([DBG]) << " " << MSG << std::endl;\
                                        SYNC_EN

#define LOGI(MSG)                       SYNC_ST \
                                        std::cout << STR_MAGENTA([INF]) << " " << MSG << std::endl;\
                                        SYNC_EN

#define LOGW(MSG)                       SYNC_ST \
                                        std::cout << STR_YELLOW([WRN]) << " " << MSG << std::endl;\
                                        SYNC_EN

#define LOGE(MSG)                       SYNC_ST \
                                        std::cout << STR_RED([ERR]) << " " << MSG << std::endl;\
                                        SYNC_EN

//////////////////////////////////////////////////////////
//// SECTION : Debug Message Elements
//////////////////////////////////////////////////////////
#define MSG_FAIL_PASS(boolean)          ( boolean ? STR_GREEN([PASS]) : STR_RED([FAIL]) )
#define MSG_TRUE_FALSE(boolean)         ( boolean ? STR_GREEN(True) : STR_RED(False) )
#define MSG_ENA_DIS(boolean)            ( boolean ? STR_GREEN([ENABLE]) : STR_RED([DISABLE]) )

//////////////////////////////////////////////////////////
//// SECTION : Implement of Debug Helper functions
//////////////////////////////////////////////////////////
inline void getTaskProgress(const char *str, size_t nNowCount, size_t nTotalCount) {
    static size_t s_nRetOld = 0xffff;
    size_t nRet = static_cast<size_t>(
                (static_cast<double>(nNowCount)/static_cast<double>(nTotalCount)) * 100.0
                );
    if (nRet != s_nRetOld) {
        switch (nRet) {
            case 0:
                LOGD("" << str << " is " << nRet << "% completed..!");
                break;
            case 25:
                LOGD("" << str << " is " << nRet << "% completed..!");
                break;
            case 50:
                LOGD("" << str << " is " << nRet << "% completed..!");
                break;
            case 75:
                LOGD("" << str << " is " << nRet << "% completed..!");
                break;
            case 100:
                LOGD("" << str << " is " << nRet << "% completed..!");
                break;
        }
    }
    s_nRetOld = nRet;
}

template <typename Typ>
inline std::string int2Hex(Typ a_arg) {
    std::stringstream ss;
    auto szTyp = sizeof(Typ);

    ss << "0x" << std::setfill('0') << std::setw(szTyp) << std::hex << a_arg;

    return ss.str();
}

//////////////////////////////////////////////////////////
//// SECTION : Progress Display Function Defines
//////////////////////////////////////////////////////////
#define GET_TASK_PROGRESS(STR, NOW, TOT)   getTaskProgress(STR, NOW, TOT)


#endif // DEBUGHELPER_H