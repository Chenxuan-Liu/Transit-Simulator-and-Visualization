/**
 * @file file_writer_manager.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/file_writer_manager.h"

#include <string>

FileWriter * FileWriterManager::file_writer = NULL;
FileWriter* FileWriterManager :: Getinstance() {
    if (!file_writer) {
        file_writer = new FileWriter;
    }
    return file_writer;
}

void FileWriter::Write(std::string str, std::vector<std::string> str_list) {
    std::ofstream myfile;
    // open the file and set to append mode
    myfile.open(str, std::ios_base::app);
    int count = 0;
    if (str.compare("BusData.csv") == 0) {
        for (auto it = std::begin(str_list); it != std::end(str_list); ++it) {
            myfile << (*it) << ',';
            count++;
            if (count % 12 == 0) {
                myfile << "\r\n";
            }
        }
    }
    if (str.compare("PassData.csv") == 0) {
        for (auto it = std::begin(str_list); it != std::end(str_list); ++it) {
            myfile << (*it) << ',';
            count++;
            if (count % 10 == 0) {
                myfile << "\r\n";
            }
        }
    }
    myfile.close();
}

std::vector<std::string> Util::processOutput(std::ostringstream& output) {
    std::vector<std::string> container;
    std::string content = output.str();
    std::istringstream foo(content);
    std::string temp;
    // parse the message each line
    while (getline(foo, temp, '\n')) {
        std::string concat;
        std::istringstream soo(temp);
        // parse the message based on :
        while (getline(soo, concat, ':')) {
            container.push_back(concat);
        }
    }
    return container;
}
