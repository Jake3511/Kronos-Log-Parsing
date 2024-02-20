// Copyright 2023
// By Jake Shick
// Regex for PS7
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <boost/regex.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int main(int argc, char** argv) {
    std::ifstream inData;
    std::ofstream outData;
    boost::regex log("^\\d{4}-\\d{2}-\\d{2} \\d{2}:\\d{2}:\\d{2}: "
    "\\(log\\.c\\.166\\) server started $");
    boost::regex oejs("^(\\d{4}-\\d{2}-\\d{2} \\d{2}:\\d{2}:\\d{2}\\.\\d+)"
    ":INFO:oejs\\.AbstractConnector:Started SelectChannelConnector@"
    "(\\d+\\.\\d+\\.\\d+\\.\\d+):(\\d+)$");
    boost::regex date_of_complete("^(\\d{4}-\\d{2}-\\d{2} "
    "\\d{2}:\\d{2}:\\d{2})");
    boost::posix_time::ptime start_time;
    std::string str;
    int count = 1;
    bool flag = false;
    inData.open(argv[1]);
    if (!inData) {
        std::cout << "NOPE" << std::endl;
        return -1;
    }
    std::string name_of_log_file = argv[1];
    name_of_log_file.append(".rpt");
    outData.open(name_of_log_file);
    if (!outData) {
        std::cout << "NOPE" << std::endl;
        return -1;
    }
    while (getline(inData, str)) {
        if (regex_match(str, log)) {
            boost::smatch m;
            if (flag) {
                outData << "**** Incomplete boot ****" << std::endl << std::endl;
            } else {
                flag = true;
            }
            regex_search(str, m, date_of_complete);
            outData << "=== Device boot ===" << std::endl;
            outData << count << "(" << argv[1] << "): " << m.str() <<
                " " << "Boot Start" << std::endl;
            std::stringstream ss(m.str());
            boost::posix_time::time_facet* ofacet =
                new boost::posix_time::time_facet("%Y-%m-%d %H-%M-%S");
            boost::posix_time::time_input_facet* ifacet =
                new boost::posix_time::time_input_facet("%Y-%m-%d %H-%M-%S");
            ss.imbue(std::locale(ss.getloc(), ifacet));
            std::cout.imbue(std::locale(std::cout.getloc(), ofacet));
            ss >> start_time;
        }
        if (regex_match(str, oejs)) {
            boost::posix_time::ptime end_time;
            boost::smatch m;
            regex_search(str, m, date_of_complete);
            outData << count << "(" << argv[1] << "): "
            << m.str() << " " << "Boot Completed" << std::endl;
            std::stringstream ss(m.str());
            boost::posix_time::time_facet* ofacet =
                new boost::posix_time::time_facet("%Y-%m-%d %H-%M-%S");
            boost::posix_time::time_input_facet* ifacet =
                new boost::posix_time::time_input_facet("%Y-%m-%d %H-%M-%S");
            ss.imbue(std::locale(ss.getloc(), ifacet));
            std::cout.imbue(std::locale(std::cout.getloc(), ofacet));
            ss >> end_time;
            boost::posix_time::time_duration diff = end_time - start_time;
            outData << "    " << "Boot time: "
            << diff.total_milliseconds() << "ms" << std::endl << std::endl;
            flag = false;
        }
        count++;
    }
    inData.close();
    outData.close();
    return 0;
}
