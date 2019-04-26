#include <iostream>

using namespace std;

int main() {
  double consumption, leak, tank_capacity,  prev_tank_capacity;
  double distance, fuel_distance, leak_distance, gas_distance;
  string event;

  consumption = leak = tank_capacity = prev_tank_capacity =  0;
  distance = fuel_distance = leak_distance = gas_distance = 0;
  while(1) {
    cin >> distance >> event;
    // cout << "event: " << event << endl; // debug

    if(event == "Fuel") {
      tank_capacity += consumption / 100 * (distance - fuel_distance);
      cin >> event >> consumption;
      if(distance + consumption == 0)
        return 0;
      if(fuel_distance != distance)
        fuel_distance = distance;
    } else if (event == "Leak") {
      tank_capacity += leak * (distance - leak_distance);
      leak++;
      // cout << "leak: " << leak << endl; // debug
      if(leak_distance != distance)
        leak_distance = distance;
    } else if(event == "Gas") {
      cin >> event;
      tank_capacity += leak * (distance - leak_distance);
      tank_capacity += consumption / 100 * (distance - fuel_distance);
      if(gas_distance != distance)
        gas_distance = distance;
      if(prev_tank_capacity < tank_capacity)
        prev_tank_capacity = tank_capacity;
      tank_capacity = 0;
      leak_distance = fuel_distance = distance;
    } else if(event == "Mechanic") {
      if(gas_distance > leak_distance)
        tank_capacity += leak * (distance - gas_distance);
      else
        tank_capacity += leak * (distance - leak_distance);
      leak = 0;
      leak_distance = distance;
    } else if(event == "Goal") {
      tank_capacity += consumption / 100 * (distance - fuel_distance);
      // cout << "tank_capacity: " << tank_capacity << endl; // debug
      tank_capacity += leak * (distance - leak_distance);
      double result = prev_tank_capacity > tank_capacity ? prev_tank_capacity : tank_capacity;
      // cout << "prev_tank_capacity: " << prev_tank_capacity << endl; // debug
      // cout << "result: "; // debug
      printf("%.3lf\n", prev_tank_capacity > tank_capacity ? prev_tank_capacity : tank_capacity);
      // cout << endl; //debug
      leak = tank_capacity = prev_tank_capacity =  0;
      distance = gas_distance = fuel_distance = leak_distance = 0;
    }

    // cout << "tank_capacity: " << tank_capacity << ", prev_tank_capacity: " << prev_tank_capacity << endl << endl; // debug
  }

  return 0;
}
