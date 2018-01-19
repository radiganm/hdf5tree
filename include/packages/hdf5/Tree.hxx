/// Tree.hxx
///
/// Copyright 2012 Mac Radigan
/// All Rights Reserved


  #include <string>
  #include "hdf5.h"
  #include <boost/property_tree/ptree.hpp>
  
#pragma once
  
namespace rad::hdf5tree {

  using namespace std;
  using namespace boost::property_tree;
  
  class Tree {
    private:
    protected:
      static const int stringBufferSize;
      ptree tree;
      void initialize();
      void scanGroup(hid_t gid, std::string path);
      void extractDataset(hid_t did, std::string path);
    public:
      Tree(); 
      ~Tree(); 
      void load(std::string filename);
      template<class T> inline T get(std::string path) { return static_cast<T>(tree.get<void*>(path)); };
  };
  
} // namespace

/// *EOF*
