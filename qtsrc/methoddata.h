#ifndef METHODDATA_H
#define METHODDATA_H

#include <string>

class MethodData
{
    public:
        MethodData(const bool enter,
                   const std::string threadName,
                   const std::string className,
                   const std::string methodName);
        const bool enter;
        const std::string threadName;
        const std::string className;
        const std::string methodName;
};

#endif // METHODDATA_H
