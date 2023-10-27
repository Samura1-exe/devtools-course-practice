// Copyright 2023 Titov Egor

#ifndef MODULES_BIGINT_INCLUDE_BIGINT_APPLICATION_H_
#define MODULES_BIGINT_INCLUDE_BIGINT_APPLICATION_H_

#include <string>

#include "include/bigInt.h"

class CLPApplication {
 public:
  CLPApplication();
  std::string operator()(int argc, const char** argv);

 private:
  std::string help();
  std::string argument_error();
};

#endif  // MODULES_BIGINT_INCLUDE_BIGINT_APPLICATION_H_
