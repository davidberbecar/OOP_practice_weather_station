//
// Created by David Berbecar on 03.04.2025.
//

#include "UI.h"
#include <iostream>
#include "Tests.h"
UI::UI(Service &service):service(service)
{

}
UI::~UI() {

}

void UI::printMenu() {
    std::cout<<"0. Exit"<<std::endl;
    std::cout<<"1. Add Weather Station"<<std::endl;
    std::cout<<"2. Show All"<<std::endl;
    std::cout<<"3. Show by Sensor Type"<<std::endl;
}


void UI :: addWS() {
    std::string location,name, sensors;
    std::cout<<"Enter Weather Station Location: ";
    std::getline(std::cin,location);
    if(location == "") {
        std::cout<<"invalid location"<<std::endl;
        return;
    }

    std::cout<<"Enter Weather Station Name: ";
    std::getline(std::cin,name);
    if(name == "") {
        std::cout<<"invalid name"<<std::endl;
        return;
    }
    std::cout<<"Enter Weather Station Sensors: ";
    std::getline(std::cin,sensors);
    if(sensors == "") {
        std::cout<<"invalid sensors"<<std::endl;
        return;
    }

    try {
        this->service.add(location,name,sensors);
        std::cout<<"Weather Station added"<<std::endl;
    }catch (std::runtime_error& e) {
        std::cout<<e.what()<<std::endl;
    }

}

void UI :: showAll() {
    std::vector<WeatherStation> locations=this->service.getAll();
    for (int i=0;i<locations.size();i++) {
        std::cout<<locations[i].getLocation()<<" | "<<locations[i].getName()<<" | "<<locations[i].getSensors()<<std::endl;
    }
}

void UI::howManyBySensor() {
    std::string sensor;
    std::cout<<"Input Sensor:"<<std::endl;
    std::getline(std::cin,sensor);
    if(sensor == "") {
        std::cout<<"invalid input"<<std::endl;
        return;
    }
    std::map<std::string,int> locations=this->service.howManyBySensor(sensor);
    for (const auto& location:locations) {
        std::cout<<location.first<<" | "<<location.second<<std::endl;
    }
}

void UI::run() {
    runAllTests();
    while (true) {
        this->printMenu();
        std::string command;
        std::cout<<"Input Command:"<<std::endl;
        std::getline(std::cin,command);
        if(command == "0") {
            break;
        } else if(command == "1") {
            this->addWS();
        } else if(command == "2") {
            this->showAll();
        } else if(command == "3") {
            this->howManyBySensor();
        } else {
            std::cout<<"Invalid command"<<std::endl;
        }
    }
}
