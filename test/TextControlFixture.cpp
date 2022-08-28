//
// Created by giacomo on 26/08/22.
//

#include "gtest/gtest.h"
#include "../TextControl.h"
#include "../FlexGridSizer.h"
#include <wx/wx.h>


class TextControlFixture : public ::testing::Test {
protected:
    virtual void SetUp() {
        static const int NCOLUMNS = 12;
        static const int NROWS = 9;
        static const int CELLWIDTH = 150;
        static const int CELLHEIGHT = 50;
        static const int WINDOWWIGHT = CELLWIDTH * NCOLUMNS;
        static const int WINDOWHEIGHT = CELLHEIGHT * NROWS + 40;
        long style = 0;

        FlexGridSizer *fgs = new FlexGridSizer(wxT("Calc Sheet"), WINDOWWIGHT, WINDOWHEIGHT, NROWS, NCOLUMNS,
                                               CELLWIDTH, CELLHEIGHT, style);

        fgs->Show(true);

        wxPanel *panel = new wxPanel(fgs, 0);
        tC = new TextControl(panel, 0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
        tC->Clear();
        tC->AppendText("");
    }

    TextControl *tC;

};

TEST_F(TextControlFixture, TestMove) {

}
