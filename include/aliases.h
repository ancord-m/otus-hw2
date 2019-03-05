#ifndef ALIASES_H_
#define ALIASES_H_

#include <string>
#include <vector>

using IpAddressType = unsigned int;

template<typename T>
using IpAddress = std::vector<T>;

template<typename T>
using IpAddressPool = std::vector<IpAddress<T>>;

#endif