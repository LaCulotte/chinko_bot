#ifndef ZONE_BUILDER_H
#define ZONE_BUILDER_H

#include "AbstractMapManager.h"

class AbstractMapManager;
class ZoneBuilder {
public:
    static vector<int> Cross(int centerCellId, int minRadius, int maxRadius, AbstractMapManager* mapManager = nullptr);
    static vector<int> Lozenge(int centerCellId, int minRadius, int maxRadius, AbstractMapManager* mapManager = nullptr);
};

#endif