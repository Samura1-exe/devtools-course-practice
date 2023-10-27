// Copyright 2023 Titov Egor

#include "include/bigInt_application.h"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

CLPApplication::CLPApplication() {}

std::string CLPApplication::operator()(int argc, const char** argv) {
  std::ostringstream os;

  if (argc == 1) {
    return this->argument_error();
  }
  if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
    return this->help();
  }

  if (argc == 4) {
    BigInt a(argv[1]);
    BigInt b(argv[3]);

    std::string op = argv[2];

    if (op == "+") {
      os << a + b;
    }
    if (op == "-") {
      os << a - b;
    }
    if (op == "/") {
      os << a / b;
    }
    if (op == "*") {
      os << a * b;
    }
    
    std::cout << os.str() << std::endl;
    return "success";
  }

  return "Wrong argument.";
}

std::string CLPApplication::help() {
  std::string help = "This program solves bigInts";
  return help;
}

std::string CLPApplication::argument_error() {
  std::string error = "Invalid argument amount, try --help or -h commands";
  return error;
}
