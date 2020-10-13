#include "IVar.h"

IVar::IVar(const IVar& other) { 
    this->delete_value();

    this->type = other.type; 
    this->value = other.get_value_copy(); 
}

IVar& IVar::operator=(const IVar& other) {
    this->delete_value();

    this->type = other.type; 
    this->value = other.get_value_copy(); 

    return *this;
}

IVar::IVar(IVar&& other) {
    this->delete_value();

    this->type = other.type; 
    this->value = other.value; 

    other.type = NONE; 
    other.value = nullptr; 
}

IVar& IVar::operator=(IVar&& other) { 
    this->delete_value();

    this->value = other.value;
    this->type = other.type;

    other.type = NONE;
    other.value = nullptr;

    return *this;
}

void* IVar::get_value_copy() const {
    void *copy = nullptr;

    switch (this->type)
    {
    case BOOL:
            COPY_DATA_FROM_POINTER_TO(bool, this->value, copy);
            break;
    case INT8:
            COPY_DATA_FROM_POINTER_TO(int8_t, this->value, copy);
            break;
    case UINT8:
            COPY_DATA_FROM_POINTER_TO(uint8_t, this->value, copy);
            break;
    case INT32:
            COPY_DATA_FROM_POINTER_TO(int32_t, this->value, copy);
            break;
    case UINT32:
            COPY_DATA_FROM_POINTER_TO(uint32_t, this->value, copy);
            break;
    case DOUBLE:
            COPY_DATA_FROM_POINTER_TO(double, this->value, copy);
            break;
    case CHAR:
            COPY_DATA_FROM_POINTER_TO(char, this->value, copy);
            break;
    case STRING:
            COPY_DATA_FROM_POINTER_TO(std::string, this->value, copy);
            break;
    default:
        break;
    }

    return copy;  
}

std::string IVar::typeToString(VarType type) {
    switch (type)
    {
    case BOOL:
        return "bool";

    case INT8:
        return "int8_t";

    case UINT8:
        return "uint8_t";

    case INT32:
        return "int32_t";

    case UINT32:
        return "uint32_t";

    case DOUBLE:
        return "double";

    case CHAR:
        return "char";

    case STRING:
        return "std::string";

    case NONE:
    default:
        return "undifined";
    }
} 