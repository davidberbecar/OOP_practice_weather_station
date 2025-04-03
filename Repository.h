//
// Created by David Berbecar on 03.04.2025.
//

#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <vector>

#include "WeatherStation.h"


class Repository {
private:
    std::vector<WeatherStation> repo;
public:
    Repository();
    ~Repository();
    void add(WeatherStation &ws);
    std::vector<WeatherStation> getAll() {return repo;};
};



#endif //REPOSITORY_H
