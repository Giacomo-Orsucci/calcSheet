//
// Created by giacomo on 29/08/22.
//

#include "TestMyApp.h"

bool TestMyApp::OnInit() { //initialization necessary to use wxWidget during the tests
    //all the necessary constants to draw the graphic window
    static const int NCOLUMNS = 12;
    static const int NROWS = 9;
    static const int CELLWIDTH = 150;
    static const int CELLHEIGHT = 50;
    static const int WINDOWWIGHT = CELLWIDTH * NCOLUMNS;
    static const int WINDOWHEIGHT = CELLHEIGHT * NROWS + 40;
    long style = wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX;

    fgs = new FlexGridSizer(wxT("Calc Sheet"), WINDOWWIGHT, WINDOWHEIGHT, NROWS, NCOLUMNS,
                            CELLWIDTH, CELLHEIGHT, style);
    fgs->Show(false);

    return true;
}