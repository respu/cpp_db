#ifndef CPP_DB_RESULT_H
#define CPP_DB_RESULT_H

#include "value.h"

#include <memory>
#include <string>

namespace cpp_db
{

class result
{
public:
    ~result();

    result(const result &) = delete;
    result &operator=(const result &) = delete;
    result(result &&);
    result &operator=(result &&);

	int get_column_count() const;

	bool is_eof() const;

	void move_first();
	void move_next();
	void move_prev();

	value get_column_value(int column) const;
	value get_column_value(const std::string &column_name) const;

	std::string get_column_name(int column) const;
	int get_column_index(const std::string &column_name) const;

private:
    using statement_handle = std::shared_ptr<void>;
    explicit result(const statement_handle &stmt_handle);
    friend class statement;

    struct impl;
	std::unique_ptr<impl> pimpl;
};

}

#endif