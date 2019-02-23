#ifndef PRINTER_H_
#define PRINTER_H_

#include "aliases.h"

class Printer {
public:
	static void print_ip(const IpAddress<unsigned int> *);
};

#endif