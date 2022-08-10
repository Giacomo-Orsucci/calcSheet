//
// Created by giacomo on 10/08/22.
//

#ifndef CALCSHEET_RESULTDISPLAY_H
#define CALCSHEET_RESULTDISPLAY_H

#include "Observer.h"
#include <list>

class ResultDisplay : public Observer {
public:
    ResultDisplay(Subject *cell);

    void subscribeSubject(Subject *s) override;

    void unsubscribeSubject(Subject *s) override;

    void update() override;

    virtual ~ResultDisplay() {};

private:
    std::list<Subject *> subjects;
    Subject *resultCell;
};


#endif //CALCSHEET_RESULTDISPLAY_H
