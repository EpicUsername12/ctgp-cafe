#ifndef _SYS_FLAG_ACCESSOR_H
#define _SYS_FLAG_ACCESSOR_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/mush/types.h>

namespace sys {
class FlagAccessor {
  public:
    bool isOpen(mush::EGrandPrixID) const;
};

} // namespace sys

#endif