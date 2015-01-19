#ifndef ATOMICCOUNTER_H
#define ATOMICCOUNTER_H

#include<atomic>

class AtomicCounter
{
    public:
        AtomicCounter();

        void increment();
        int get();
    private:
        std::atomic<int> value {0};

};

#endif // ATOMICCOUNTER_H
