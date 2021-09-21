#include <precompiled.h>

#include "ipf_ip.h"



int main(int argc, char** argv)
{
    auto printUsage = []()
    {
        std::cout << "USAGE:" << std::endl;
        std::cout << "  ip_filter" << std::endl;
        std::cout << "  ip_filter <filename>" << std::endl;
    };

    std::vector<ipf::IPv4> aIps;
    auto readIPv4 = [&aIps](const std::string & str)
    {
        std::istringstream ss{ str };
        std::string ipstr;
        ss >> ipstr;

        try
        {
            aIps.emplace_back(ipstr);
        }
        catch (const std::exception & e)
        {
            std::cerr << "Failed to read IPv4 from string \"" << str << "\": " << e.what();
        }
    };

    if (argc == 1)
    {
        for (std::string line; std::getline(std::cin, line);)
        {
            if (line.empty())
                break;

            readIPv4(line);
        }
    }
    else if (argc == 2)
    {
        std::string filename(argv[1]);
        std::ifstream ifs{ filename };
        if (!ifs.is_open())
        {
            std::cerr << "Cannot open file " << filename << ": no such file or directory";
            printUsage();
        }
        
        for (std::string line; std::getline(ifs, line);)
            readIPv4(line);
    }
    else
    {
        std::cerr << "Invalid arguments." << std::endl;
        printUsage();
        return EXIT_FAILURE;
    }

    auto print = [](const auto & arr)
    {
        for (const auto & ip : arr)
            std::cout << ip.toString() << std::endl;
    };

    // sort in reversed lexicographical order
    std::sort(aIps.begin(), aIps.end(), [](const auto & ip1, const auto & ip2)
    {
        return ip2 < ip1;
    });

    // print all
    print(aIps);

    // print all which have first byte == 1
    {
        std::vector<ipf::IPv4> aRes;
        std::copy_if(aIps.cbegin(), aIps.cend(), std::back_inserter(aRes),
            [](const ipf::IPv4 & ip)
        {
            return ip[0] == 1;
        });
        print(aRes);
    }

    // print all which have first byte == 46 and second == 70
    {
        std::vector<ipf::IPv4> aRes;
        std::copy_if(aIps.cbegin(), aIps.cend(), std::back_inserter(aRes), [](const ipf::IPv4 & ip)
        {
            return ip[0] == 46 && ip[1] == 70;
        });
        print(aRes);
    }

    // print all which have any byte == 46
    {
        std::vector<ipf::IPv4> aRes;
        std::copy_if(aIps.cbegin(), aIps.cend(), std::back_inserter(aRes), [](const ipf::IPv4 & ip)
        {
            return std::any_of(ip.cbegin(), ip.cend(), [](const ipf::IPv4::byte & b) { return b == 46; });
        });
        print(aRes);
    }

    return EXIT_SUCCESS;
}
