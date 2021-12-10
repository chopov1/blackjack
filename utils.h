//#pragma once
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <stack>

//class Card;

static bool failed = false;

// template <class T>
// constexpr void assert_equal(const T &expected, std::function<void(stack<Card>)>& func) {
//   if (expected != func.size()) {
//     std::cout << "Result\tError\tExpected: " << expected << " actual "
//               << func.size() << std::endl;
//     failed = true;
//   } else {
//     std::cout << "Result\tOK" << std::endl;
//   }
// }

template <class T>
constexpr void assert_equal(const T &expected, const T &testvalue) {
  if (expected != testvalue) {
    std::cout << "Result\tError\tExpected: " << expected << " actual "
              << testvalue << std::endl;
    failed = true;
  } else {
    std::cout << "Result\tOK" << std::endl;
  }
}

class AbstractTestHarness {
private:
  std::map<std::string, std::function<void()>> testFuncs;

protected:
  void register_test_func(const std::string &&name,
                          std::function<void()> &&func) {
    this->testFuncs.insert(
        std::pair<std::string, std::function<void()>>(name, func));
  }

public:
  AbstractTestHarness() {
    this->testFuncs = std::map<std::string, std::function<void()>>();
  }
  void execute() {
    std::cout << "Found " << testFuncs.size() << " Tests" << std::endl;
    for (auto f : testFuncs) {
      std::cout << "Executing Test " << f.first << std::endl;
      f.second();
    }
  }
};

class TestManager {
private:
  std::map<std::string, AbstractTestHarness> tests;

protected:
  void add_test(const std::string &&name, AbstractTestHarness &&test) {
    this->tests.insert(std::pair<std::string, AbstractTestHarness>(name, test));
  }

public:
  TestManager() { this->tests = std::map<std::string, AbstractTestHarness>(); }
  void execute() {
    std::cout << "Found " << tests.size() << " Test Harnesses" << std::endl;
    for (auto t : tests) {
      std::cout << "Executing Test Harness " << t.first << std::endl;
      t.second.execute();
    }
    if (failed) {
      std::cout << "tests failed" << std::endl;
      exit(1);
    }
  }
};
