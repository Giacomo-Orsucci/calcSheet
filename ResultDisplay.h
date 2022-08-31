//
// Created by giacomo on 10/08/22.
//

#ifndef CALCSHEET_RESULTDISPLAY_H
#define CALCSHEET_RESULTDISPLAY_H

#include "Observer.h"
#include "TextControl.h"
#include <list>

enum class Operation { //list of the implemented functions
    MIN, MAX, MEAN, SUM
};

class ResultDisplay : public Observer { //concrete observer
public:
    ResultDisplay(Subject *cell, Operation operation);

    void subscribeSubject(Subject *s) override;

    void unsubscribeSubject(Subject *s) override;

    void update() override;

    ~ResultDisplay() override = default;

private:
    std::list<Subject *> subjects; //list of the cells to observe
    Subject *resultCell; //cell where to write the result
    Operation opr; //function executed by the specific observer
};

#endif //CALCSHEET_RESULTDISPLAY_H
