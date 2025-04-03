//
// Created by David Berbecar on 03.04.2025.
//

#ifndef UI_H
#define UI_H
#include "Service.h"


class UI {
private:
    Service& service;
    void printMenu();
    void addWS();
    void showAll();
    void howManyBySensor();
public:
    UI(Service& service);
    ~UI();
    void run();
};



#endif //UI_H
