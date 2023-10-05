#pragma once

#include <ostream>
namespace common {
/**
 * Through this type to determine object type
 */
enum {
  MESSAGE_BASIC = 100,
  MESSAGE_BASIC_REQUEST = 1000,
  MESSAGE_BASIC_RESPONSE = -1000
};
class Deserializable {
public:
  /*
   * deserialize buffer to one object
   * @param[in]buffer,     buffer to store the object serialized bytes
   * @return *             object
   */
  virtual void *deserialize(const char *buffer, int bufLen) = 0;
};
class Serializable {
public:
  virtual int serialize(std::ostream &os) const = 0;

  virtual int deserialize(std::istream &is) = 0;

  virtual int get_serial_size() const = 0;

  /**
   * this function will generalize one output string
   */
  virtual void to_string(std::string &output) const = 0;
};
} // namespace common