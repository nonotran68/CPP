#include <iostream>

int main()
{
   std::cout << "\"This is quoted text\"\n"; // In ra "This is quoted text"
   std::cout << "This string contains a single backslash \\\n"; // In ra "This string contains a single backslash \"
   std::cout << "6F in hex is char '\x6F'\n"; // In ra "6F in hex is char 'o'"
   std::cout << "Print char \vsome another texts\n";
   return 0;
}
