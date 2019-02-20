#include <iostream>

#include "parser.h"
#include "sorter.h"
#include "printer.h"

int main(int argc, char const *argv[])
{
    Parser parser;
    Sorter sorter;
    Filter filter;

    for(std::string line; std::getline(std::cin, line); )
    {
        auto text = parser.captureTextBeforeFirstTab(line);
        parser.splitIpAddressIntoPartsAndSave(text);
    }

    sorter.sort_inversely_ip_pool(parser.get_raw_ip_pool());

 /*   Printer::print_ip_pool(
        sorter.get_inversley_sorted_ip_pool()
    );*/

    filter.leave_ips_starting_with(sorter.get_inversley_sorted_ip_pool(), 45, 44, 56,77);

   /* Printer::print_ip_pool(
        filter.
    );
*/

 //   printer.printContentsOfIpPool(filter.);

    //sorter.sortInversely_IPs_startingWith(1);
    //printer.printContentsOfIpPool(sorter.getSortedIpPool());

    //sorter.sortInversely_IPs_startingWith(46, 70);
    //printer.printContentsOfIpPool(sorter.getSortedIpPool());

    //sorter.sortInversely_IPs_containing(46);
    //printer.printContentsOfIpPool(sorter.getSortedIpPool());

    return 0;
}
