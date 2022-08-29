//
// Created by giacomo on 26/08/22.
//

#include "gtest/gtest.h"
#include "TestMyApp.h"
#include <wx/wx.h>


class TextControlFixture : public ::testing::Test {
protected:
    TestMyApp *app;
    TextControl *tC;

    virtual void SetUp() {
        char appname[] = "wxUnitTest.exe";
        int argc = 1;
        char *argv[1] = {appname};
        app = new TestMyApp();
        wxApp::SetInstance(app);
        wxEntryStart(argc, argv);
        app->OnInit();
        wxPanel *panel = new wxPanel(app->fgs, -1);
        tC = new TextControl(panel, 0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    }

    virtual void TearDown() {
        app->OnExit();
        wxEntryCleanup();
    }

};

TEST_F(TextControlFixture, Get_and_Set) {
    tC->setValue(5);
    double value;
    tC->getValue(value);
    ASSERT_EQ(value, 5);
}
