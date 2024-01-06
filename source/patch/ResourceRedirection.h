#pragma once

#define CTGP_RESOURCE_PATH "ctgp.szs"

#include <cafe.h>

#include <mk8/ui/UIEngine.h>
#include <mk8/nw/lyt/Resource.h>
#include <resource/seadSZSDecompressor.h>

#include "utils/ScopedHeapUsage.h"
#include "utils/Filesystem.h"
#include "CourseRedirection.h"

namespace ctgp {
void InitResourceRedirection();
}
