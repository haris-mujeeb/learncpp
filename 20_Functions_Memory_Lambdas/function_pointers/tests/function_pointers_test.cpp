#include <gtest/gtest.h>
#include "calculator.hpp"
#include <string>
#include <iostream>
#include <algorithm>

std::map<std::string, MathOperation> mathOperationsMap;

double compute(double x, std::string operation, double y) {
  if (mathOperationsMap.find(operation) != mathOperationsMap.end()) {
    return mathOperationsMap[operation](x, y);
    
  } else {
    std::cerr << "No operation found for " << operation << std::endl;
    return 0.0;
  }
}



std::vector<double> transform_array(std::vector<double> vec, MathOperation operation, double scalar) {
  std::vector<double> new_vec;
  for (const auto& element : vec) {
    new_vec.push_back(operation(element, scalar));
  }
  return new_vec;
}

class FunctionPointerTests : public ::testing::Test{
protected:
  void SetUp() override {    
    mathOperationsMap.insert({"+", add});
    mathOperationsMap["-"] = subtract;
    mathOperationsMap["*"] = multiply;
  }

  void TearDown() override {}
};

TEST_F(FunctionPointerTests, MapInitialization) {
  EXPECT_EQ(compute( 1, "+", 1), 2);
  EXPECT_EQ(compute(0, "-", 1), -1);
  EXPECT_DOUBLE_EQ(compute(0.5, "*", 0.5), 0.25);
}

TEST_F(FunctionPointerTests, TransfromArrayTest) {
  std::vector<double> vec = {1, 2, 3, 4, 5};
  double scalar = 2;

  std::vector<double> transfromed_vec = transform_array( vec , multiply , 2);

  // vec * scalar
  std::transform(vec.begin(), vec.end(), vec.begin(),[scalar](int n){ return n * scalar;});
 
  for (size_t i = 0; i < vec.size(); i++) {
    ASSERT_EQ(transfromed_vec[i], vec[i]);
  }
}
