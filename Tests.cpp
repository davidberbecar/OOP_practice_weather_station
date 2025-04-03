//
// Created by David Berbecar on 03.04.2025.
//

#include "Tests.h"

#include <assert.h>
#include <iostream>

#include "Repository.h"
#include "Service.h"

void testAdd() {
    Repository repo;
    WeatherStation ws1{"Location1", "Name1", "Sensor1"};
    WeatherStation ws2{"Location2", "Name2", "Sensor2"};
    repo.add(ws1);
    repo.add(ws2);
    assert(repo.getAll()[0].getLocation() == "Location1");
    assert(repo.getAll()[1].getLocation() == "Location2");
    assert(repo.getAll()[0].getName() == "Name1");
    assert(repo.getAll()[1].getName() == "Name2");

    Service service{repo};
    service.add("Location3", "Name3", "Sensor3");
    assert(repo.getAll()[2].getLocation() == "Location3");

}

void testFilter() {
    Repository repo;
    Service service{repo};
    WeatherStation ws1 {"New York", "Central Park", "Thermometer, Barometer"};
    repo.add(ws1);

    WeatherStation ws2 {"New York", "JFK Airport", "Thermometer, Anemometer, Wind Vane"};
    repo.add(ws2);

    WeatherStation ws3 {"London", "Heathrow Airport", "Thermometer, Anemometer, Wind Vane, Hygrometer"};
    repo.add(ws3);

    WeatherStation ws4 {"London", "Greenwich", "Hygrometer, Rain Gauge"};
    repo.add(ws4);

    WeatherStation ws5 {"Cluj", "Cetatuie", "Thermometer, Barometer"};
    repo.add(ws5);

    std::map<std::string, int> locationCount = service.howManyBySensor("Thermometer");
    for (const auto& ws : repo.getAll()) {
        assert(locationCount["Cluj"] == 1);
        assert(locationCount["New York"] == 2);
        assert(locationCount["London"] == 1);
    }
}

void runAllTests() {
    testAdd();
    std::cout << "All tests passed" << std::endl;
}