//
// Created by giacomo on 09/08/22.
//

#ifndef CALCSHEET_FLEXGRIDSIZER_H
#define CALCSHEET_FLEXGRIDSIZER_H

#include <wx/wx.h>
#include "Subject.h"
#include "Observer.h"

class FlexGridSizer : public wxFrame {
public:
    FlexGridSizer(const wxString &title, const int windowWidth, const int windowHeight, const int nRows,
                  const int nColumns, const int cellWidth, const int cellHeight, long style);
};

#endif //CALCSHEET_FLEXGRIDSIZER_H