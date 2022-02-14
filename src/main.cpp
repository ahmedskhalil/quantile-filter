//
// Quantile-Filteer
// Driver/Testing code
// Author: Ahmed Khalil
// Date: 14.02.2021
//

#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

double getFilterValue (const std::vector<std::vector<double>>& filter_matrix, const double q)
{
  if (q > 1.0 || q < 0.0) return -1;
  
  std::vector<double> flattened_filter;
  for (auto && row : filter_matrix) {
    flattened_filter.insert(flattened_filter.end(), row.begin(), row.end());
  }
  
  std::sort(flattened_filter.begin(), flattened_filter.end());
  
  int element_idx = ceil(q * flattened_filter.size());
  
  if (element_idx != 0) element_idx = element_idx-1;
  
  double filter_value = flattened_filter[element_idx];
  
  return filter_value;
}

int main(int, char**) {
  const std::vector<std::vector<double>> filter_matrix {{1,10,3},{7,4,7},{4,2,11}};
  
  assert((getFilterValue(filter_matrix, 0.0)) == 1 && "Filter Value is not correct");
  assert((getFilterValue(filter_matrix, 0.3)) == 3 && "Filter Value is not correct");
  assert((getFilterValue(filter_matrix, 0.5)) == 4 && "Filter Value is not correct");
  assert((getFilterValue(filter_matrix, 0.6)) == 7 && "Filter Value is not correct");
  assert((getFilterValue(filter_matrix, 1.0)) == 11 && "Filter Value is not correct");
  
  assert((getFilterValue(filter_matrix, 3.0)) == -1 && "Filter Value is not correct");
  assert((getFilterValue(filter_matrix, -2.5)) == -1 && "Filter Value is not correct");

  std::cout << ">> Tests passed\n";
  
  return 0;
}
