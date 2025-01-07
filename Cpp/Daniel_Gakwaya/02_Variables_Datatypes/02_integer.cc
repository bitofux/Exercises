#include <iostream>

int main () {

  //assignment notation
  int bike_count = 2;
  int truck_count = 7;
  int vehicle_count = bike_count + truck_count;
  int narrowing_conversion_assignment = 2.9;//can implict conversion

  std::cout << "bike_count: " << bike_count << std::endl;
  std::cout << "truck_count: " << truck_count << std::endl;
  std::cout << "vehicle_count: " << vehicle_count << std::endl;
  std::cout << "narrowing_conversion_assignment: " << narrowing_conversion_assignment << std::endl;

  std::cout << "**************************************" << std::endl;

  //functional initialization
  int apple_count(1);
  int orange_count(10);
  int fruit_count(apple_count + orange_count);
  int narrowing_conversion_functional (2.9); //less safe.can implict conversion
  
  std::cout << "apple_count: " << apple_count << std::endl;
  std::cout << "orange_count: " << orange_count << std::endl;
  std::cout << "fruit_count: " << fruit_count << std::endl;
  std::cout << "narrowing_conversion_functional: " << narrowing_conversion_functional << std::endl;

  //use braced initialization
  int elephant_count;//contain random garbage value
  int lion_count{};//initializes to 0
  int dog_count{20};//initializes to 20
  int cat_count{10};//initializes to 10

  int domestricated_animals {dog_count + cat_count};

  int narrowing_conversion{2.9};//compiler errors. not allow to conversion
  std::cout << "elephant_count: " << elephant_count << std::endl;
  std::cout << "lion_count: " << lion_count << std::endl;
  std::cout << "dog_count: " << dog_count << std::endl;
  std::cout << "cat_count: " << cat_count << std::endl;
  std::cout << "domestricated_animals: " << domestricated_animals << std::endl;

  std::cout << "narrowing_conversion: " << narrowing_conversion << std::endl;
}
