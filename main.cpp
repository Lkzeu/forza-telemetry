#include <iostream>
#include "src/application.hpp"


int main() {
   try {
      application app;
      app.run();
   }
   catch (std::exception& ex) {
      std::cout << ex.what() << std::endl;
   }
   return 0;

}
