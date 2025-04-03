//
// Created by David Berbecar on 03.04.2025.
//

#include "Repository.h"

Repository::Repository() {

}

Repository::~Repository() {

}


void Repository::add(WeatherStation &ws) {
    // Check if the weather station already exists in the repository
    // if it does, throw an exception, otherwise add it
    for (int i=0; i<repo.size(); i++) {
        if (repo.at(i)==ws) {
            throw std::runtime_error("this weather station already exists already exists");
        }
    }
    repo.push_back(ws);
}

