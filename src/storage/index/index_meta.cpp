#include "storage/index/index_meta.hpp"

#include "common/lang/string.hpp"
#include "common/log//log.hpp"
#include "json/value.h"

namespace ezdb {
const static ::Json::StaticString FIELD_NAME("name");

RC IndexMeta::init(const char* name, const FieldMeta& field) {
  if (common::is_blank(name)) {
    LOG_ERROR("Failed to init index, name is empty.");
    return RC::INVALID_ARGUMENT;
  }
  name_ = name;
  field_ = field.name();
  return RC::SUCCESS;
}

}  // namespace ezdb