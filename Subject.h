//
// Created by giacomo on 10/08/22.
//

#ifndef CALCSHEET_SUBJECT_H
#define CALCSHEET_SUBJECT_H

class Subject {
public:
    virtual void notify() = 0;

    virtual double getValue() = 0;

    virtual void setValue(double v) = 0;

    virtual void printValue() = 0;

    virtual ~Subject();
};

#endif //CALCSHEET_SUBJECT_H