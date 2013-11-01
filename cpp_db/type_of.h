#ifndef CPP_DB_TYPE_OF_H
#define CPP_DB_TYPE_OF_H

#include <typeinfo>
#include <typeindex>

namespace cpp_db
{

template<typename T>
std::type_index type_of(const T &value)
{
    return typeid(value);
}

}

#endif // CPP_DB_TYPE_OF_H