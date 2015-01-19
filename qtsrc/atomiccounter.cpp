#include "atomiccounter.h"

AtomicCounter::AtomicCounter()
{

}

void AtomicCounter::increment() {
    ++(this->value);
}

int AtomicCounter::get() {
    return (this->value).load();
}

