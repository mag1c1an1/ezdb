#pragma once

#include <ostream>
#include <string>

#include "usual/rc.hpp"

namespace Json {
class Value;
}

namespace ezdb {

class FieldMeta;
class TableMeta;

/**
 * @brief 描述一个索引
 * @ingroup Index
 * @details 一个索引包含了表的哪些字段，索引的名称等。
 * 如果以后实现了多种类型的索引，还需要记录索引的类型，对应类型的一些元数据等
 */
class IndexMeta {
public:
  IndexMeta() = default;

  RC init(const char *name, const FieldMeta &field);

public:
  const char *name() const;
  const char *field() const;

  void desc(std::ostream &os) const;

public:
  void to_json(Json::Value &json_value) const;
  static RC from_json(const TableMeta &table, const Json::Value &json_value,
                      IndexMeta &index);

protected:
  std::string name_;  // index's name
  std::string field_; // field's name
};
} // namespace ezdb