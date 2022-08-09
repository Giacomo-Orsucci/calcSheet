//
// Created by giacomo on 09/08/22.
//

#include "FlexGridSizer.h"
#include <string.h>


FlexGridSizer::FlexGridSizer(const wxString &title, const int windowWidth, const int windowHeight, const int nRows,
                             const int nColumns, const int cellWidth, const int cellHeight, long style)
        : wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(windowWidth, windowHeight), style) {
    int rowCounter = 1;
    int columnCounter = 65;
    long tCStyle = wxTE_READONLY | wxTE_CENTER;

    wxPanel *panel = new wxPanel(this, -1);
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    wxFlexGridSizer *fgs = new wxFlexGridSizer(nRows, nColumns, 0, 0);

    wxTextCtrl *tC;

    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nColumns; j++) {

            if (j == 0 && i != 0) {
                tC = new wxTextCtrl(panel, i, wxEmptyString, wxDefaultPosition, wxSize(cellWidth, cellHeight), tCStyle);
                tC->AppendText(std::to_string(rowCounter));
                rowCounter++;
            } else if (j == 0 && i == 0) {
                tC = new wxTextCtrl(panel, i, wxEmptyString, wxDefaultPosition, wxSize(cellWidth, cellHeight), tCStyle);
            } else if (i == 0 && j != 0) {
                tC = new wxTextCtrl(panel, i, wxEmptyString, wxDefaultPosition, wxSize(cellWidth, cellHeight), tCStyle);
                tC->AppendText(char(columnCounter));
                columnCounter++;
            } else {
                tC = new wxTextCtrl(panel, i, wxEmptyString, wxDefaultPosition, wxSize(cellWidth, cellHeight));
            }
            fgs->Add(tC);
        }
    
    hbox->Add(fgs, 1, wxALL | wxEXPAND, 0);
    panel->SetSizer(hbox);
    Centre();
}