/// h5dump.cxx
///
/// Copyright 2012 Mac Radigan
/// All Rights Reserved

  #include "Tree.hxx"
  #include <boost/property_tree/ptree.hpp>
  #include <boost/property_tree/xml_parser.hpp>
  #include <boost/program_options.hpp>
  #include <fstream>
  #include <iostream>
  #include <string>
  #include <streambuf>
  #include <exception>

  #ifdef __CINT__
  #endif

  using namespace rad::hdf5tree;

  int usage(int argc, char* argv[], boost::program_options::options_description &desc) 
  {
    std::cout << desc << std::endl;
    return 1;
  }

  using namespace std;
  namespace po = boost::program_options;
  using namespace boost::property_tree;
  using namespace boost::program_options;
  using namespace org::radigan::malachi;

  int main(int argc, char* argv[]) 
  {
     int embedded;
     string filename;
     po::options_description desc("options");
     po::variables_map vm;
     po::notify(vm);
     desc.add_options()
       ("config,c", po::value<string>(), "configuration file")
       ("file,f", po::value<string>(), "input data file")
       ("help,h", "print this help message")
       ("persist,p", "persist session")
     ;
     po::store(po::parse_command_line(argc,argv,desc),vm);
     if(!vm.count("file")) { cerr << "no input file specified" << endl; exit(1); }
     if(vm.count("help")) { return usage(argc,argv,desc); exit(0); }
     if(vm.count("file")) { filename=string(vm["file"].as<string>()); }
     if(vm.count("config")) {
       ptree pt;
       read_xml("config.xml", pt);
     }
     std::ifstream t(vm["file"].as<string>().c_str());
     std::string cmd((std::istreambuf_iterator<char>(t)),
                     (std::istreambuf_iterator<char>()));
     Tree tree;
     int status;
     try {
       tree.load(vm["file"].as<string>());
     } catch(exception& e) {
       cerr << "exception: " << e.what() << endl;
       throw;
     }
     return status;
  }

/// *EOF*
