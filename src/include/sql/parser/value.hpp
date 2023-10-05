#pragma once

#include <string>

namespace ezdb {

/**
 * @brief 属性的类型
 *
 */
enum AttrType {
  UNDEFINED,
  CHARS,    ///< 字符串类型
  INTS,     ///< 整数类型(4字节)
  FLOATS,   ///< 浮点数类型(4字节)
  BOOLEANS, ///< boolean类型，当前不是由parser解析出来的，是程序内部使用的
  DATES,
};

const char *attr_type_to_string(AttrType type);
AttrType attr_type_from_string(const char *s);

class Value;

/**
 * @brief 属性的值
 *
 */
class Date {
public:
  Date() = default;
  Date(int year, int month, int day) : year_(year), month_(month), day_(day) {
    val_ = year_ * 10000 + month_ * 100 + day_;
    is_valid_ = CheckValid();
  }
  auto GetVal() const -> int { return val_; }
  auto ToValue() const -> Value;
  auto FromValue() -> Date &;
  auto IsValid() -> bool const { return is_valid_; }
  auto ToString() const -> const std::string;

private:
  auto CheckValid() -> bool;

private:
  int year_;
  int month_;
  int day_;
  int val_;
  bool is_valid_ = false;
};

class Value {
public:
  Value() = default;

  Value(AttrType attr_type, char *data, int length = 4)
      : attr_type_(attr_type) {
    this->set_data(data, length);
  }

  explicit Value(int val);
  explicit Value(float val);
  explicit Value(bool val);
  explicit Value(const char *s, int len = 0);
  explicit Value(const Date &date);

  Value(const Value &other) = default;
  Value &operator=(const Value &other) = default;

  void set_type(AttrType type) { this->attr_type_ = type; }
  void set_data(char *data, int length);
  void set_data(const char *data, int length) {
    this->set_data(const_cast<char *>(data), length);
  }
  void set_int(int val);
  void set_float(float val);
  void set_boolean(bool val);
  void set_string(const char *s, int len = 0);
  void set_date(const Date &date);
  void set_value(const Value &value);

  std::string to_string() const;

  int compare(const Value &other) const;

  const char *data() const;
  int length() const { return length_; }

  AttrType attr_type() const { return attr_type_; }

public:
  /**
   * 获取对应的值
   * 如果当前的类型与期望获取的类型不符，就会执行转换操作
   */
  int get_int() const;
  float get_float() const;
  std::string get_string() const;
  bool get_boolean() const;
  auto get_date() const -> Date;

private:
  AttrType attr_type_ = UNDEFINED;
  int length_ = 0;

  union {
    int int_value_;
    float float_value_;
    bool bool_value_;
    int date_value_;
  } num_value_;
  std::string str_value_;
};

}
