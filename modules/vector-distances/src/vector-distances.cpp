// Copyright 2023 Titov Egor

#include "include/vector-distances.h"

#include <cmath>
#include <string>
#include <vector>

DistanceCalculator::DistanceCalculator(const std::vector<float>& _data)
    : data(_data) {}

DistanceCalculator::DistanceCalculator(const DistanceCalculator& v)
    : data(v.data) {}

DistanceCalculator& DistanceCalculator::operator=(const DistanceCalculator& v) {
  data = v.data;
  return *this;
}

void DistanceCalculator::setData(const std::vector<float>& v) { data = v; }

void DistanceCalculator::getData(std::vector<float>* v) { *v = data; }

float DistanceCalculator::Linf(DistanceCalculator v) {
  if (data.size() != v.data.size())
    throw std::string("Vectors are of different sizes");
  if (data.size() == 0) throw std::string("Vectors are empty");
  float maxDistance = 0;
  for (unsigned int i = 0; i < data.size(); i++) {
    float distance = std::abs(data[i] - v.data[i]);
    if (distance > maxDistance) maxDistance = distance;
  }
  return maxDistance;
}

float DistanceCalculator::L(int p, DistanceCalculator v) {
  if (data.size() != v.data.size())
    throw std::string("Vectors are of different sizes");
  if (data.size() == 0) throw std::string("Vectors are empty");
  if (p < 1) throw std::string("Incorrect metric");
  float sum = 0;
  for (unsigned int i = 0; i < data.size(); i++) {
    sum += pow(std::abs(data[i] - v.data[i]), p);
  }
  return pow(sum, 1.0f / p);
}
