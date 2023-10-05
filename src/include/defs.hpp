#pragma once

namespace common {
enum {
  // General Error Codes
  STATUS_SUCCESS = 0,    //!< Success status should be zero,
  STATUS_INVALID_PARAM,  //!< Invalid parameter
  STATUS_FAILED_INIT,    //!< Failed to init program
  STATUS_PROPERTY_ERR,   //!< Property error
  STATUS_INIT_LOG,       //!< log error
  STATUS_INIT_THREAD,    //!< failed to init thread
  STATUS_FAILED_JOB,     //!< Failed to do job
  STATUS_FAILED_NETWORK, //!< Network failure

  STATUS_UNKNOW_ERROR,
  STATUS_LAST_ERR //!< last error code
};

static const char FILE_PATH_SPLIT = '/';
static const char FILE_PATH_SPLIT_STR[] = "/";

#define EPSILON (1E-6)
} // namespace common