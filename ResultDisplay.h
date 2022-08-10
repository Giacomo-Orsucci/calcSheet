//
// Created by giacomo on 10/08/22.
//

#ifndef CALCSHEET_RESULTDISPLAY_H
#define CALCSHEET_RESULTDISPLAY_H

#include "Observer.h"
#include "TextControl.h"
#include <list>

enum class Operation {
    MIN, MAX, MEAN, SUM
};

class ResultDisplay : public Observer {
public:
    ResultDisplay(Subject *cell, Operation operation);

    void subscribeSubject(Subject *s) override;

    void unsubscribeSubject(Subject *s) override;

    void update() override;

    virtual ~ResultDisplay() {};

private:
    std::list<Subject *> subjects;
    Subject *resultCell;
    Operation opr;
};


#endif //CALCSHEET_RESULTDISPLAY_H
