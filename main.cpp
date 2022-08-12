#include "main.h"
#include "FlexGridSizer.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
    //all the necessary constants to draw the graphic window
    static const int NCOLUMNS = 12;
    static const int NROWS = 9;
    static const int CELLWIDTH = 150;
    static const int CELLHEIGHT = 50;
    static const int WINDOWWIGHT = CELLWIDTH * NCOLUMNS;
    static const int WINDOWHEIGHT = CELLHEIGHT * NROWS + 40;
    long style = wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX;

    FlexGridSizer *fgs = new FlexGridSizer(wxT("Calc Sheet"), WINDOWWIGHT, WINDOWHEIGHT, NROWS, NCOLUMNS,
                                           CELLWIDTH, CELLHEIGHT, style);

    fgs->Show(true);

    return true;
}