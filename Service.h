//
// Created by David Berbecar on 03.04.2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include <map>

#include "Repository.h"


class Service {
private:
    Repository& repo;
public:
    Service(Repository& repo) : repo(repo) {}
    //~Service();
    void add(const std::string &location, const std::string &name, const std::string &sensors);
std::map<std::string, int> howManyBySensor(std::string sensor);
    std::vector<WeatherStation> getAll() {return repo.getAll();};
};



#endif //SERVICE_H
