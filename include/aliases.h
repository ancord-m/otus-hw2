#ifndef ALIASES_H_
#define ALIASES_H_

#include <string>
#include <vector>

template<typename T>
using IpAddressPool = std::vector<std::vector<T> >;

template<typename T>
using IpAddress = std::vector<T>;

#endif