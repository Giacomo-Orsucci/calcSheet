//
// Created by giacomo on 29/08/22.
//

#ifndef CALCSHEET_TESTMYAPP_H
#define CALCSHEET_TESTMYAPP_H


#include "../FlexGridSizer.h"

class TestMyApp : public wxApp {
public:
    virtual bool OnInit();

    FlexGridSizer *fgs;
};


#endif //CALCSHEET_TESTMYAPP_H
