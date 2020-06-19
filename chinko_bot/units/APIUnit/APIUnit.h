#ifndef APIUNIT_H
#define APIUNIT_H

#include "MessagingUnit.h"
#include "TerminalPromptFrame.h"

class APIUnit : public MessagingUnit {
public:
    // Constructor
    APIUnit() : MessagingUnit() {};
    // Copy constructor
    APIUnit(const APIUnit& other) = default;

    // Copy operator
    APIUnit& operator=(const APIUnit& other) = default;
    // Destructor
    ~APIUnit() = default;

    // Initialization of base frames
    void initFrames() override {};
};

#endif