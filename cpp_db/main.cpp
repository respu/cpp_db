#include "nullable.h"
#include "nullable_types.h"
#include "key_value_pair.h"

#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{
    std::cout << std::endl;

    try
    {
        cpp_db::nullable_int a, c(815);

        a = 4711;

        if (a==13)
            std::cout << "Strange!!!\n";
        else
            std::cout << "Equal!!!\n";

        int b = a;

        std::cout << "b=" << b << ", c=" << c << std::endl;

        std::cout << cpp_db::coalesce(cpp_db::nullable_int(), cpp_db::nullable_int()) << std::endl;

        cpp_db::null_type null;

        std::cout << "Is null ? " << std::boolalpha << null.is_null() << std::endl;

        std::unique_ptr<cpp_db::connection_option> p(cpp_db::make_key_value_pair(std::string("driver"), std::string("QIBASE")));

        std::cout << p->key<std::string, std::string>()
                  << "=\"" << p->value<std::string, std::string>() << "\""
                  << std::endl;

    }
    catch(const std::exception &ex)
    {
        std::cout << "Exception: " << ex.what() << std::endl;
    }
}
