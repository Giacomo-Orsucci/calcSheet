//
// Created by giacomo on 09/08/22.
//

#ifndef CALCSHEET_MyApp_H
#define CALCSHEET_MyApp_H

#include <wx/wx.h>
#include "FlexGridSizer.h"
#include <linux/membarrier.h>
#include <sys/syscall.h>
#include <sys/syscall.h>

class MyApp : public wxApp {
public:
    virtual bool OnInit();

    ~MyApp() override = default;
};

#endif //CALCSHEET_MyApp_H
