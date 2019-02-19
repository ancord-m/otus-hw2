#include <iostream>

#include "parser.h"
#include "sorter.h"
#include "printer.h"

int main(int argc, char const *argv[])
{
    Parser parser;
    Sorter sorter(&parser);
    Printer printer;

    for(std::string line; std::getline(std::cin, line); )
    {
        auto text = parser.captureTextBeforeFirstTab(line);
        parser.splitIpAddressIntoPartsAndSave(text);
    }

    sorter.sortInversely_AllIPs();
    printer.printContentsOfIpPool(sorter.getSortedIpPool());

    //sorter.sortInversely_IPs_startingWith(1);
    filter
    printer.printContentsOfIpPool(sorter.getSortedIpPool());

    //sorter.sortInversely_IPs_startingWith(46, 70);
    printer.printContentsOfIpPool(sorter.getSortedIpPool());

    //sorter.sortInversely_IPs_containing(46);
    printer.printContentsOfIpPool(sorter.getSortedIpPool());

    return 0;
}
