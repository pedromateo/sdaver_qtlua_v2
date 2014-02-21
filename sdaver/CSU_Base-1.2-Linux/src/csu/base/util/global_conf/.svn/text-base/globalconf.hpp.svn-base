#ifndef GLOBALCONF_HPP
#define GLOBALCONF_HPP

#include <map>
#include <iostream>
#include <fstream>

#include <boost/algorithm/string.hpp>


namespace csu{
   namespace base{
      namespace util{
         namespace global_conf{

            ///
            /// GlobalConf
            ///
            /// This class read a file (given by the user)
            /// and creates a global std::map<string,string>.
            /// The read file has to have the following
            /// format:
            ///   key = value (return)
            ///

            class GlobalConf
            {
            public:

               GlobalConf() : set_(false)
               {}

               std::string value(const std::string& key)
               {
                  if (set_) return kvMap_[key];
                  return "";
               }

               bool getValuesFromFile(const std::string& path)
               {
                  ///open the file
                  std::ifstream inFile(path.c_str());
                  if (!inFile.is_open())
                  {
                     std::cout << "(GlobalConf::getValuesFromFile) ERROR: Unable to open file "
                           << path << " .";
                     assert(0);//FIXME quitar esto
                     return false;
                  }

                  ///read the file
                  std::string line = "";
                  while (! inFile.eof() )
                  {
                     getline (inFile,line);
                     boost::trim(line);

                     //comments are omitted
                     if (line[0] == '#') continue;

                     //the line is valid if contains a '='
                     std::string::size_type loc = line.find( "=", 0 );
                     if (loc == std::string::npos)
                     {
                        //not found, continue
                        continue;
                     }

                     //get the key and the value
                     std::string key = line.substr(0,loc);
                     boost::trim(key);
                     std::string value = line.substr(loc+1);
                     boost::trim(value);

                     std::cout << "(GlobalConf::getValuesFromFile) Reading parameter: "
                           << key << " = " << value << std::endl;

                     //insert them into the map
                     kvMap_[key] = value;
                  }

                  ///close the file
                  inFile.close();

                  //if everything is ok...
                  set_ = true;
                  return set_;
               }

               const std::map<std::string, std::string>& gmap()
               {
                  return kvMap_;
               }

            private:
               std::map<std::string, std::string> kvMap_;
               bool set_;
            };

         }//global_conf
      }//util
   }//lib
}//csu

#endif // GLOBALCONF_HPP
