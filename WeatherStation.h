//
// Created by David Berbecar on 03.04.2025.
//

#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H
#include <string>


class WeatherStation {
private:
    std::string location,name,sensors;
public:
    WeatherStation(const std::string& location, const std::string& name, const std::string& sensors);
    ~WeatherStation();
    std::string getLocation() const {return this->location;}
    std::string getName() const {return this->name;};
    std::string getSensors() const {return this->sensors;};
    bool operator==(const WeatherStation& other);
};



#endif //WEATHERSTATION_H
