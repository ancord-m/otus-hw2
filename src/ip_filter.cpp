#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "parser.h"
#include "sorter.h"
#include "printer.h"

/*    char words[N][30], cur[30];
    cout<<"Your words:\n";
    for(i=0;i<N;i++)
        cin.getline(words[i],30);
    
   
    
 
    for(i=0;i<N-1;i++)
        for(j=i+1;j<N;j++)
            if(strcmp(words[i],words[j])>0)
            {   strcpy(cur,words[i]);
                strcpy(words[i],words[j]);
                strcpy(words[j],cur);
            }
    cout<<"Results:\n";
    for(i=0;i<N;i++)
        cout<<words[i]<<"\n";*/


int main(int argc, char const *argv[])
{
    try
    {
      /*  std::vector<std::vector<std::string> > ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }
        */

  /*  std::vector<std::vector<std::string> > ip_pool =
        {
                { "85", "254", "10", "197" },
                { "23", "240", "215", "189" },
                { "1",  "29", "168", "152" },
                { "185", "69", "186", "168" },
                { "110", "152", "103", "161" },
                { "68", "45", "152", "82" },
                { "185", "182", "81", "131" },
                { "114", "221", "179", "117" },
                { "185", "89", "100", "249" },
                { "46", "70", "113", "73" },
                { "185", "69", "0", "38" }
        };*/

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
      
      

     //   sorter.sortInversely_IPs_startingWith(1);


/*      

        auto ip_pool = parser.getIpPool();

*/
        // TODO reverse lexicographically sort

  /*      for(std::vector<std::vector<std::string> >::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
        {
            for(std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
            {
                if (ip_part != ip->cbegin())
                {
                    std::cout << ".";

                }
                std::cout << *ip_part;
            }
            std::cout << std::endl;
        } */

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        // ip = filter(1)

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
