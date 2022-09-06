//
// Created by giacomo on 10/08/22.
//

#ifndef CALCSHEET_SUBJECT_H
#define CALCSHEET_SUBJECT_H

class Subject { //abstract observer
public:
    virtual void notify() const = 0;

    virtual bool getValue(double &value) const = 0;

    virtual void setValue(double v) = 0;

    virtual void printValue() = 0;

    virtual ~Subject() {};
};

#endif //CALCSHEET_SUBJECT_H