//
// Created by giacomo on 10/08/22.
//

#include "ResultDisplay.h"

ResultDisplay::ResultDisplay(Subject *cell, Operation operation) : resultCell(cell), opr(operation) {}

void ResultDisplay::subscribeSubject(Subject *s) {
    subjects.push_back(s);
}

void ResultDisplay::unsubscribeSubject(Subject *s) {
    subjects.remove(s);
}

void ResultDisplay::update() { //it implements the observer function depending on the operation attribute
    double temp = 0;
    double current;

    if (opr == Operation::MIN) {
        (*(subjects.begin()))->getValue(temp);
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++) {
            (*itr)->getValue(current);
            if (current < temp)
                temp = current;
        }
        resultCell->setValue(temp);
    } else if (opr == Operation::MAX) {
        (*(subjects.begin()))->getValue(temp);
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++) {
            (*itr)->getValue(current);
            if (current > temp)
                temp = current;
        }
        resultCell->setValue(temp);
    } else if (opr == Operation::MEAN) {
        double result = 0;
        int i = 0;
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++) {
            if ((*itr)->getValue(temp)) {
                result += temp;
                i++;
            } else
                temp = 0;
        }
        result /= i;
        resultCell->setValue(result);
    } else if (opr == Operation::SUM) {
        double result = 0;
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++) {
            (*itr)->getValue(temp);
            result += temp;
        }
        resultCell->setValue(result);
    }
    resultCell->printValue();
}
