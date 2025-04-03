//
// Created by David Berbecar on 03.04.2025.
//

#include "Service.h"

#include <map>


void Service::add(const std::string &location,const std::string &name,const std::string &sensors) {

    //Create a new WeatherStation object
    //add it to the repository

    WeatherStation wsToAdd(location,name,sensors);
    this->repo.add(wsToAdd);
}

std::map<std::string, int> Service::howManyBySensor(std::string sensor) {

    // Create a map to count the number of weather stations by location
    //Key: location, Value: number of weather stations

    std::map<std::string, int> locationCount;
    for (const auto& ws : this->repo.getAll()) {
        if (ws.getSensors().find(sensor) != std::string::npos) {
            locationCount[ws.getLocation()]++;
        }
    }
    return locationCount;
}

