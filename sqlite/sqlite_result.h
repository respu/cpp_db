#ifndef CPP_DB_SQLITE_RESULT_H
#define CPP_DB_SQLITE_RESULT_H

#include "result_interface.h"
#include "usings.h"

#include "sqlite3.h"

#include <unordered_map>
#include <memory>

namespace cpp_db
{

class sqlite_result : public result_interface
{
public:
    explicit sqlite_result(const shared_statement_ptr &stmt_in);

    void move_next() override;
    void move_first() override;
    bool is_eof() const override;
    int get_column_count() const override;
    std::string get_column_name(int column) const override;
    value get_column_value(int column) const override;
    int get_column_index(const std::string &column_name) const override;
    value get_column_value(const std::string &column_name) const override;

private:
	sqlite3_stmt *get_stmt_handle() const;

private:
	std::shared_ptr<statement_interface> stmt;
    int row_status;
    std::unordered_map<std::string, int> column_names;
};

} // namespace cpp_db

#endif // CPP_DB_SQLITE_RESULT_H
