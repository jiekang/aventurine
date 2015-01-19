#include "methoddata.h"

MethodData::MethodData(const bool enter,
                       const std::string threadName,
                       const std::string className,
                       const std::string methodName)
    : enter (enter), threadName (threadName), className (className), methodName (methodName)
{
}


