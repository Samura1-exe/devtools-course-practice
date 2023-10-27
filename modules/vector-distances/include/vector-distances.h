// Copyright 2023 Titov Egor

#ifndef MODULES_VECTOR_DISTANCES_INCLUDE_VECTOR_DISTANCES_H_
#define MODULES_VECTOR_DISTANCES_INCLUDE_VECTOR_DISTANCES_H_

#include <vector>

class DistanceCalculator {
 private:
  std::vector<float> data;

 public:
  explicit DistanceCalculator(const std::vector<float>& _data);
  DistanceCalculator(const DistanceCalculator& v);
  DistanceCalculator& operator=(const DistanceCalculator& v);
  void setData(const std::vector<float>& v);
  void getData(std::vector<float>* v);
  float Linf(DistanceCalculator v);
  float L(int p,
          DistanceCalculator v);  // Calculates distance according to L_p norm
};

#endif  // MODULES_VECTOR_DISTANCES_INCLUDE_VECTOR_DISTANCES_H_
