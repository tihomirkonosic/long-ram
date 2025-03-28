//
// Created by Tiho on 28.3.2025..
//

#ifndef PROGRAM_OPTION_H
#define PROGRAM_OPTION_H



struct ProgramOption {
  const char *long_name;
  char short_name;
  bool has_short_name;
  bool has_additional_parameter = false;
};



#endif //PROGRAM_OPTION_H
