#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_IOS) || defined(DM_PLATFORM_OSX)

namespace dmSignpost {
    
    uint64_t Platform_Start(const char* scopeName);
    void Platform_Stop(uint64_t handle, char* info);
    void Platform_Event(const char* info);

} //namespace

#endif
