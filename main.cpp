#include "main.h"
#include "FlexGridSizer.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
    static const int nColumns = 12;
    static const int nRows = 9;
    static const int cellWidth = 150;
    static const int cellHeight = 50;
    static const int windowWidth = cellWidth * nColumns;
    static const int windowHeight = cellHeight * nRows + 40;
    long style = wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX;

    FlexGridSizer *fgs = new FlexGridSizer(wxT("Open Source Excel"), windowWidth, windowHeight, nRows, nColumns,
                                           cellWidth, cellHeight, style);

    fgs->Show(true);

    return true;
}