#include <tclap/CmdLine.h>
#include <iostream>
#include <string>

int main()
{
  TCLAP::CmdLine cli{"hello test"};
  TCLAP::UnlabeledValueArg<std::string> msg{"msg", "msg to print", true, "", "string"};
  std::cout << "hello crossed" << std::endl;
  return 0;
}
