//
// Created by giacomo on 09/08/22.
//

#include "FlexGridSizer.h"
#include "TextControl.h"
#include <string>

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
                tC = new TextControl(panel, i * nColumns + j, wxEmptyString, wxDefaultPosition,
                                     wxSize(cellWidth, cellHeight),
                                     tCStyle);
                tC->AppendText(std::to_string(rowCounter));
                rowCounter++;
            } else if (j == 0 && i == 0) {
                tC = new TextControl(panel, i * nColumns + j, wxEmptyString, wxDefaultPosition,
                                     wxSize(cellWidth, cellHeight),
                                     tCStyle);
            } else if (i == 0 && j != 0) {
                tC = new TextControl(panel, i * nColumns + j, wxEmptyString, wxDefaultPosition,
                                     wxSize(cellWidth, cellHeight),
                                     tCStyle);
                tC->AppendText(char(columnCounter));
                columnCounter++;
            } else {
                if (i == nRows - 1) {
                    tC = new TextControl(panel, i * nColumns + j, wxEmptyString, wxDefaultPosition,
                                         wxSize(cellWidth, cellHeight), tCStyle);
                    switch (j) {
                        case 1:
                            tC->AppendText("MIN: ");
                            break;
                        case 4:
                            tC->AppendText("MAX: ");
                            break;
                        case 7:
                            tC->AppendText("MEAN: ");
                            break;
                        case 10:
                            tC->AppendText("SUM: ");
                            break;
                    }
                } else {
                    tC = new TextControl(panel, i * nColumns + j, wxEmptyString, wxDefaultPosition,
                                         wxSize(cellWidth, cellHeight));
                    if (j == 2 || j == 5 || j == 8 || j == 11) {
                        if (i > 0 && i < nRows - 1) {
                            tC->AppendText(std::to_string(0));
                        }
                    }
                }
            }
            fgs->Add(tC);
        }
    hbox->Add(fgs, 1, wxALL | wxEXPAND, 0);
    panel->SetSizer(hbox);
    Centre();
}
