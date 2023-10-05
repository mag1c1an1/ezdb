#pragma once

#include <ostream>
#include <string>

#include "sql/parser/value.hpp"
#include "usual/rc.hpp"

namespace Json {
class Value;
}

namespace ezdb {
class FieldMeta {
 public:
  FieldMeta();
  FieldMeta(const char* name, AttrType attr_type, int attr_offset, int attr_len,
            bool visible);
  ~FieldMeta();

  RC init(const char* name, AttrType attr_type, int attr_offset, int attr_len,
          bool visible);

 public:
  const char* name() const;
  AttrType type() const;
  int offset() const;
  int len() const;
  bool visible() const;

 public:
  void desc(std::ostream& os) const;

 public:
  void to_json(Json::Value& json_value) const;
  static RC from_json(const Json::Value& json_value, FieldMeta& field);

 protected:
  std::string name_;
  AttrType attr_type_;
  int attr_offset_;
  int attr_len_;
  bool visible_;
};
}  // namespace ezdb
