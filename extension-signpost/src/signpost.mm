#if defined(DM_PLATFORM_IOS) || defined(DM_PLATFORM_OSX)
#include "signpost_private.h"
#include <os/signpost.h>
#import <Foundation/Foundation.h>

namespace dmSignpost {
    os_log_t logHandle = 0x0;
    
    uint64_t Platform_Start(const char* scopeName)
    {
        if (logHandle == 0x0)
        {
            logHandle = os_log_create("Lua", OS_LOG_CATEGORY_POINTS_OF_INTEREST);
        }
        os_signpost_id_t identifier = os_signpost_id_generate(logHandle);
        os_signpost_interval_begin(logHandle, identifier, "Lua", "%s", scopeName);
        return identifier;
    }
    
    void Platform_Stop(uint64_t identifier, char* info)
    {
        os_signpost_interval_end(logHandle, identifier, "Lua", "%s", info);
    }

    void Platform_Event(const char* info)
    {
        os_signpost_event_emit(logHandle, OS_SIGNPOST_ID_EXCLUSIVE, "Lua", "%s", info);
    }
    
} //namespace
#endif
