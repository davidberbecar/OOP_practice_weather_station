#include<iostream>

#include "Repository.h"
#include "Service.h"
#include "UI.h"

void populateRepo(Repository &repo) {
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

}

int main() {

    Repository repo;
    Service service{repo};
    UI ui {service};

    populateRepo(repo);
    ui.run();
}
