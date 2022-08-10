//
// Created by giacomo on 10/08/22.
//

#ifndef CALCSHEET_OBSERVER_H
#define CALCSHEET_OBSERVER_H

#include "Subject.h"

class Observer {
public:
    virtual void update() = 0;

    virtual void subscribeSubject(Subject *s) = 0;

    virtual void unsubscribeSubject(Subject *s) = 0;

    virtual ~Observer();
};

#endif //CALCSHEET_OBSERVER_H
