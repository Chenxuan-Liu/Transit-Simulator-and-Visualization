/**
 * @file file_writer_manager.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_FILE_WRITER_MANAGER_H_
#define SRC_FILE_WRITER_MANAGER_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

// using namespace std;


/**
 * @brief This class writes the parsed data from the container to a file.
 *
 * Calls to \ref Write function to write message from ostringstream to file.
 */
class FileWriter{
 public:
/**
  * @brief Function write ostringstream into file
  *
  *
  * @param[in] file name
  * @param[in] processed output message.
  *
  */
  void Write(std::string str, std::vector<std::string> str_list);
};


/**
 * @brief This class is used to implement the singleton pattern.
 *
 * Calls to \ref Getinstance function to generate FileWriter object.
 */
class FileWriterManager{
 private:
  static FileWriter* file_writer;
 public:
/**
  * @brief Function generate FileWriter object
  *
  * This is an static function and used to implement singleton pattern.
  * It creates FileWrite object.
  *
  * @return A FileWriter object pointer
  *
  */
  static FileWriter* Getinstance();
};


/**
 * @brief This class is used to parse the string returned by the ostringstream object 
 * and stores parsed data into a container to be able to write the data to a file.
 *
 * Calls to \ref processOutput function to parse the string.
 */

class Util{
 public:
/**
  * @brief Function parse the string and store them in a verctor.
  *
  *
  * @param[in] ostringstream string from the report function.
  *
  * @return a vector of string contains the pared message and read to be write into files.
  *
  */
  static std::vector<std::string> processOutput(std::ostringstream& output);
};
#endif  // SRC_FILE_WRITER_MANAGER_H_
