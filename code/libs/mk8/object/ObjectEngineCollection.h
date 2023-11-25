#ifndef OBJECT_ENGINE_COLLECTION_H
#define OBJECT_ENGINE_COLLECTION_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/object/Race/RaceDirector.h>
#include <mk8/object/Kart/KartDirector.h>

namespace object {

class ObjectEngineCollection {
  public:
    static object::RaceDirector* spRaceDirector;
    static object::KartDirector* spKartDirector;
};

} // namespace object

#endif