
#include <iostream>

#include "biosoup/timer.hpp"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

int main(int argc, const char* argv[]) {
  auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic.txt");
  std::cout << "Start" << std::endl;

  biosoup::Timer timer{};
  timer.Start();

  logger->info("Hello, {}!", "World");
}
