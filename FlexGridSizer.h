//
// Created by giacomo on 09/08/22.
//

#ifndef CALCSHEET_FLEXGRIDSIZER_H
#define CALCSHEET_FLEXGRIDSIZER_H

#include <wx/wx.h>
#include "Subject.h"
#include "Observer.h"
#include "TextControl.h"
#include "ResultDisplay.h"
#include <string>
#include <list>

class FlexGridSizer : public wxFrame {

public:
   explicit FlexGridSizer(const wxString &title, const int windowWidth, const int windowHeight, const int nRows,
                          const int nColumns, const int cellWidth, const int cellHeight, long style);

    ~FlexGridSizer() override;

private:
    //lists to associate correctly subjects and observers
    std::list<TextControl *> tCL2;
    std::list<TextControl *> tCL5;
    std::list<TextControl *> tCL8;
    std::list<TextControl *> tCL11;

    wxPanel *panel;
    wxBoxSizer *hbox;
    wxFlexGridSizer *fgs;
    TextControl *tC;

    //observers
    ResultDisplay *displayMin;
    ResultDisplay *displayMax;
    ResultDisplay *displayMean;
    ResultDisplay *displaySum;

};

#endif //CALCSHEET_FLEXGRIDSIZER_H