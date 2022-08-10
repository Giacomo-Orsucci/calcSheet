//
// Created by giacomo on 10/08/22.
//

#include "ResultDisplay.h"

void ResultDisplay::subscribeSubject(Subject *s) {
    subjects.push_back(s);
}

void ResultDisplay::unsubscribeSubject(Subject *s) {
    subjects.remove(s);
}

void ResultDisplay::update() {
    double result = 0;
    for (auto itr = subjects.begin(); itr != subjects.end(); itr++) {
        result += (*itr)->getValue();
    }
    resultCell->setValue(result);
    resultCell->printValue();
}
