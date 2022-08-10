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

    if (opr == operation::MIN) {
        double app = (*(subjects.begin()))->getValue();
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++) {
            if ((*itr)->getValue() < app)
                app = (*itr)->getValue();
        }
        resultCell->setValue(app);
    } else if (opr == operation::MAX) {
        double app = (*(subjects.begin()))->getValue();
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++) {
            if ((*itr)->getValue() > app)
                app = (*itr)->getValue();
        }
        resultCell->setValue(app);
    } else if (opr == operation::MEAN) {
        double result = 0;
        int i = 0;
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++) {
            result += (*itr)->getValue();
            i++;
        }
        result /= i;
        resultCell->setValue(result);
    } else if (opr == operation::SUM) {
        double result = 0;
        for (auto itr = subjects.begin(); itr != subjects.end(); itr++) {
            result += (*itr)->getValue();
        }
        resultCell->setValue(result);
    }

    resultCell->printValue();
}
