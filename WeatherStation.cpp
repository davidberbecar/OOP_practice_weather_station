//
// Created by David Berbecar on 03.04.2025.
//

#include "WeatherStation.h"

WeatherStation::WeatherStation(const std::string &location, const std::string &name, const std::string &sensors):
location{location},name{name},sensors{sensors}
{

}

WeatherStation::~WeatherStation() {

}

bool WeatherStation::operator==(const WeatherStation& other) {
    return this->getLocation()==other.getLocation() && this->getName()==other.getName();
}