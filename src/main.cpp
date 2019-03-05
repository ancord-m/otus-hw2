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

    sorter.sort_inversely_ip_pool(parser.get_ip_pool());

    filter.set_ip_pool_to_be_filtered(parser.get_ip_pool());

    filter.show_ips_as_is();
    filter.show_ips_starting_with(1);
    filter.show_ips_starting_with(46, 70);
    filter.show_ips_containing(46);

    return 0;
}
