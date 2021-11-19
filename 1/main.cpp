#include "boost/program_options.hpp"
#include <iostream>

#include "Status.h"
#include "Hasher.h"

namespace po = boost::program_options;
int main(int argc, char* argv[])
{
    try {
        po::options_description desc("Possible Commands");
        desc.add_options()
                ("help,h", "Help screen!!!")
                ("mode,m", po::value<std::string>(), "Hash Mode [hash64, adler32]")
                ("filename,f", po::value<std::string>(), "Files to proceed");

        po::positional_options_description p;
        p.add("filename", -1);

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).
                options(desc).positional(p).run(), vm);
        po::notify(vm);

        const std::map<std::string, HashMode> um = { {"hash64", HashMode::_Hash64},
                                                     {"adler32", HashMode::_Adler32} };

        HashMode hm;
        std::string input_file;

        if (vm.count("mode"))
        {
            std::cout << "Hash mode is: "
                      << vm["mode"].as<std::string>() << std::endl;
            try
            {
                hm = um.at(vm["mode"].as<std::string>());
            }
            catch (const std::exception& e)
            {
                std::cerr << "Invalid hash mode" << std::endl;
                std::cerr << e.what();
                return -1;
            }
        }
        if (vm.count("filename"))
        {
            std::cout << " Input files are: ";
            input_file = vm["filename"].as<std::string>();
                std::cout << input_file << std::endl;
        }
        if (vm.count("help"))
        {
            std::cout << desc << std::endl;
            return 0;
        }
        return hashProccessing(input_file.c_str(), hm) == Status::_SUCCESS ? 0 : -1;
    }
    catch (po::error& e) {
        std::cerr << e.what();
        return -1;
    }
}





