// #include "Var.h"
// #include <memory>
// #include <typeinfo>

// #define sp std::shared_ptr

// int main() {
//     std::cout << "salu" << std::endl;

//     // sp<IVar> var = std::make_shared<Var<bool>>(true);
//     // sp<IVar> var2 = std::make_shared<Var<bool>>(true);

//     sp<IVar> var = std::make_shared<Var<int>>(8);
//     sp<IVar> var2 = std::make_shared<Var<std::string>>("hey");

//     // std::cout << isCompatible_addition_group1<int32_t>::value << std::endl;

//     try {
//         // sp<IVar> var3 = (*var % *var2);
//         if(*var > *var2)
//             std::cout << "oui" << std::endl;
//         else 
//             std::cout << "non" << std::endl;
//         // std::cout << var->asString() << std::endl;
//     } catch (std::string s) {
//         std::cout << s << std::endl;
//     }
    
//     return 0;
// }