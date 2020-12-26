#ifndef ZONE_BUILDER_H
#define ZONE_BUILDER_H

#include "AbstractMapManager.h"

// Fonctions that build zones of cells. Copied based on the dofus source code
class AbstractMapManager;
class ZoneBuilder {
public:
    // Builds a Cross of cells
    static vector<int> Cross(int centerCellId, int minRadius, int maxRadius, AbstractMapManager* mapManager = nullptr);
    // Builds a Lozenge of cells
    static vector<int> Lozenge(int centerCellId, int minRadius, int maxRadius, AbstractMapManager* mapManager = nullptr);
};

#endif