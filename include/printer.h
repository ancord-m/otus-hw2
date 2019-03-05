#ifndef PRINTER_H_
#define PRINTER_H_

#include "aliases.h"

struct Printer
{
	static void print_ip(const IpAddress<IpAddressType> &ip);
};

#endif