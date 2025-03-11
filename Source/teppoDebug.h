#ifdef TEPPODEBUG
#ifndef TEPPODEBUG_H
#define TEPPODEBUG_H

#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <chrono>

// Declare the global variables with external linkage.
//extern std::string g_teppoDebugFileName;
//extern cmsys::ofstream g_teppoDebugFS;

inline std::string currentDateTime() {
  using namespace std::chrono;
  auto now = system_clock::now();
  auto now_time_t = system_clock::to_time_t(now);
  // Extract milliseconds component
  auto us = duration_cast<microseconds>(now.time_since_epoch()) % 1000000;

  // Get local time (note: std::localtime is not thread-safe)
  std::tm* localTime = std::localtime(&now_time_t);

  std::ostringstream oss;
  oss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S")
      << '.' << std::setfill('0') << std::setw(6) << us.count();
  return oss.str();
}
#define TEPPO_SOURCE_ROOT "/Users/teppo.keitaanniemi/work/gitlab.kitware.com/cmake/cmake/"
#define TEPPO_RELPATH_FILE (&__FILE__[sizeof(TEPPO_SOURCE_ROOT) - 1])
#define TEPPO_DEBUG_PRINT(msg) \
  std::cout << "TEPPO\t" << currentDateTime() << "\t" << TEPPO_RELPATH_FILE << "\t" << __LINE__ << "\t" << __func__ <<"\t" << msg << std::endl
#endif //TEPPODEBUG_H
#endif
