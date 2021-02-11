#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


int some_execute_function(const std::string& code)
{
    const std::string dynamic_filename("dynamic.cpp");
    const std::string dynamic_executable("./dynamic.out");
    const std::string binary_executable("./RunTimeCompiler");
    std::ofstream dynamic(dynamic_filename);
    dynamic << "#include <iostream>\n"
            << "#include <cstdlib>\n"
            << "#include <string>\n"
            << "using namespace std;\n"
            << "string binary_executable("
            << "\"./RunTimeCompiler\");\n"
            << "int main(){\n"
            << code 
            << "\n"
            << "return system(binary_executable.c_str());\n"
            << "return EXIT_SUCCESS;\n"
            << "}\n";
    dynamic.close();

    const std::string build_command("g++ -std=c++14 -O2 -Wall -pedantic -pthread " + dynamic_filename + " -o " + dynamic_executable);    
    bool it_didnt_compile = system(build_command.c_str());
    if(it_didnt_compile)
    {
        
        return system(binary_executable.c_str());
        
        
    }
    else
    {
        return system(dynamic_executable.c_str());
        
    }
}


int main()
{
    
    std::string a;
    std::string b = "exit";

  
    std::cout << "C++: ";
    std::getline(std::cin, a);
    
    if(a == b) {
        std::cout << "\nExited.";
    } else {
    std::string code_string = a;
    
    return some_execute_function(code_string);
    }
    return 0;
    
    
}
