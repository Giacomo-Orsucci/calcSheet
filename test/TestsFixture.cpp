//
// Created by giacomo on 26/08/22.
//

#include "gtest/gtest.h"
#include "TestMyApp.h"
#include "../ResultDisplay.h"
#include <wx/wx.h>


class TestsFixture : public ::testing::Test {
protected:
    TestMyApp *app;
    TextControl *tC;
    TextControl *tC1;
    TextControl *tC2;
    TextControl *tC3;
    TextControl *tC4;
    ResultDisplay *rDMin;
    ResultDisplay *rDMax;
    ResultDisplay *rDMean;
    ResultDisplay *rDSum;

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
        tC1 = new TextControl(panel, 0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
        tC2 = new TextControl(panel, 0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
        tC3 = new TextControl(panel, 0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
        tC4 = new TextControl(panel, 0, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
        rDMin = new ResultDisplay(tC, Operation::MIN);
        rDMax = new ResultDisplay(tC, Operation::MAX);
        rDMean = new ResultDisplay(tC, Operation::MEAN);
        rDSum = new ResultDisplay(tC, Operation::SUM);
    }

    virtual void TearDown() {
        app->OnExit();
        wxEntryCleanup();
    }

};

TEST_F(TestsFixture, Text_Control_Get_and_Set_right) {
    tC->setValue(5); //simulates the client's input of a number
    double value;
    ASSERT_TRUE(tC->getValue(value));
    ASSERT_EQ(value, 5);
}

TEST_F(TestsFixture, Text_Control_Get_and_Set_wrong) {
    tC->AppendText("adf"); //simulates the wrong client's input
    double value;
    ASSERT_FALSE(tC->getValue(value));
    ASSERT_EQ(value, 0);
}

TEST_F(TestsFixture, Min) {
    tC1->setValue(1);
    tC2->setValue(2);
    tC3->AppendText("adf");
    tC4->setValue(-5);
    rDMin->subscribeSubject(tC1);
    rDMin->subscribeSubject(tC2);
    rDMin->subscribeSubject(tC3);
    rDMin->subscribeSubject(tC4);
    tC4->setObserver(rDMin);
    tC4->notify();
    double value;
    ASSERT_TRUE(tC->getValue(value));
    ASSERT_EQ(value, -5);
}

TEST_F(TestsFixture, Max) {
    tC1->setValue(1);
    tC2->setValue(2);
    tC3->AppendText("adf");
    tC4->setValue(-5);
    rDMax->subscribeSubject(tC1);
    rDMax->subscribeSubject(tC2);
    rDMax->subscribeSubject(tC3);
    rDMax->subscribeSubject(tC4);
    tC4->setObserver(rDMax);
    tC4->notify();
    double value;
    ASSERT_TRUE(tC->getValue(value));
    ASSERT_EQ(value, 2);
}

TEST_F(TestsFixture, Mean) {
    tC1->setValue(2);
    tC2->setValue(2);
    tC3->AppendText("adf");
    tC4->setValue(5);
    rDMean->subscribeSubject(tC1);
    rDMean->subscribeSubject(tC2);
    rDMean->subscribeSubject(tC3);
    rDMean->subscribeSubject(tC4);
    tC4->setObserver(rDMean);
    tC4->notify();
    double value;
    ASSERT_TRUE(tC->getValue(value));
    ASSERT_EQ(value, 3);
}

TEST_F(TestsFixture, Sum) {
    tC1->setValue(1);
    tC2->setValue(2);
    tC3->AppendText("adf");
    tC4->setValue(-5);
    rDSum->subscribeSubject(tC1);
    rDSum->subscribeSubject(tC2);
    rDSum->subscribeSubject(tC3);
    rDSum->subscribeSubject(tC4);
    tC4->setObserver(rDSum);
    tC4->notify();
    double value;
    ASSERT_TRUE(tC->getValue(value));
    ASSERT_EQ(value, -2);
}
