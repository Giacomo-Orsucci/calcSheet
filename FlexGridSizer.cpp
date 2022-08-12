//
// Created by giacomo on 09/08/22.
//

#include "FlexGridSizer.h"
#include "TextControl.h"
#include "ResultDisplay.h"
#include <string>
#include <list>
//TODO CLEAN THE CODE
FlexGridSizer::FlexGridSizer(const wxString &title, const int windowWidth, const int windowHeight, const int nRows,
                             const int nColumns, const int cellWidth, const int cellHeight, long style)
        : wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(windowWidth, windowHeight), style) {
    int rowCounter = 1;
    int columnCounter = 65;
    long tCStyle = wxTE_READONLY | wxTE_CENTER;
    std::list<TextControl *> tCL2;
    std::list<TextControl *> tCL5;
    std::list<TextControl *> tCL8;
    std::list<TextControl *> tCL11;


    wxPanel *panel = new wxPanel(this, -1);
    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    wxFlexGridSizer *fgs = new wxFlexGridSizer(nRows, nColumns, 0, 0);
    TextControl *tC;
    ResultDisplay *displayMin;
    ResultDisplay *displayMax;
    ResultDisplay *displayMean;
    ResultDisplay *displaySum;

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
                    switch (j) {
                        case 1:
                            tC = new TextControl(panel, i * nColumns + j, wxEmptyString, wxDefaultPosition,
                                                 wxSize(cellWidth, cellHeight), tCStyle);
                            tC->AppendText("MIN: ");
                            break;
                        case 2:
                            tC = new TextControl(panel, i * nColumns + j, wxEmptyString, wxDefaultPosition,
                                                 wxSize(cellWidth, cellHeight));
                            displayMin = new ResultDisplay(tC, Operation::MIN);
                            break;
                        case 4:
                            tC = new TextControl(panel, i * nColumns + j, wxEmptyString, wxDefaultPosition,
                                                 wxSize(cellWidth, cellHeight), tCStyle);
                            tC->AppendText("MAX: ");
                            break;
                        case 5:
                            tC = new TextControl(panel, i * nColumns + j, wxEmptyString, wxDefaultPosition,
                                                 wxSize(cellWidth, cellHeight));
                            displayMax = new ResultDisplay(tC, Operation::MAX);
                            break;
                        case 7:
                            tC = new TextControl(panel, i * nColumns + j, wxEmptyString, wxDefaultPosition,
                                                 wxSize(cellWidth, cellHeight), tCStyle);
                            tC->AppendText("MEAN: ");
                            break;
                        case 8:
                            tC = new TextControl(panel, i * nColumns + j, wxEmptyString, wxDefaultPosition,
                                                 wxSize(cellWidth, cellHeight));
                            displayMean = new ResultDisplay(tC, Operation::MEAN);
                            break;
                        case 10:
                            tC = new TextControl(panel, i * nColumns + j, wxEmptyString, wxDefaultPosition,
                                                 wxSize(cellWidth, cellHeight), tCStyle);
                            tC->AppendText("SUM: ");
                            break;
                        case 11:
                            tC = new TextControl(panel, i * nColumns + j, wxEmptyString, wxDefaultPosition,
                                                 wxSize(cellWidth, cellHeight));
                            displaySum = new ResultDisplay(tC, Operation::SUM);
                            break;
                        default:
                            tC = new TextControl(panel, i * nColumns + j, wxEmptyString, wxDefaultPosition,
                                                 wxSize(cellWidth, cellHeight));
                    }
                } else {
                    long style = wxTE_PROCESS_ENTER;
                    int id = 0;
                    tC = new TextControl(panel, i * nColumns + j, wxEmptyString, wxDefaultPosition,
                                         wxSize(cellWidth, cellHeight), style);
                        if (i > 0 && i < nRows - 1) {
                            if (j == 2) {
                                tC->AppendText(std::to_string(0));
                                tC->setValue(0);
                                tC->SetId(id);
                                tCL2.push_back(tC);
                            }
                            if (j == 5) {
                                tC->AppendText(std::to_string(0));
                                tC->setValue(0);
                                tC->SetId(id);
                                tCL5.push_back(tC);
                            }
                            if (j == 8) {
                                tC->AppendText(std::to_string(0));
                                tC->setValue(0);
                                tC->SetId(id);
                                tCL8.push_back(tC);
                            }
                            if (j == 11) {
                                tC->AppendText(std::to_string(0));
                                tC->setValue(0);
                                tC->SetId(id);
                                tCL11.push_back(tC);
                            }
                        }
                }
            }
            fgs->Add(tC);
        }

    for (auto itr = tCL2.begin(); itr != tCL2.end(); itr++) {
        displayMin->subscribeSubject((*itr));
        (*itr)->setObserver(displayMin);
    }
    for (auto itr = tCL5.begin(); itr != tCL5.end(); itr++) {
        displayMax->subscribeSubject((*itr));
        (*itr)->setObserver(displayMax);
    }

    for (auto itr = tCL8.begin(); itr != tCL8.end(); itr++) {
        displayMean->subscribeSubject((*itr));
        (*itr)->setObserver(displayMean);
    }

    for (auto itr = tCL11.begin(); itr != tCL11.end(); itr++) {
        displaySum->subscribeSubject((*itr));
        (*itr)->setObserver(displaySum);
    }

    hbox->Add(fgs, 1, wxALL | wxEXPAND, 0);
    panel->SetSizer(hbox);
    Centre();
}
