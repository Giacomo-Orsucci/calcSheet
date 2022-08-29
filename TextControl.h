//
// Created by giacomo on 10/08/22.
//

#ifndef CALCSHEET_TEXTCONTROL_H
#define CALCSHEET_TEXTCONTROL_H


#include <wx/wx.h>
#include <list>
#include "Subject.h"
#include "Observer.h"
#include "gtest/gtest.h"


class TextControl : public wxTextCtrl, public Subject { //concrete subject
    FRIEND_TEST(TextControlFixture, Get_and_Set);

public:

    //exactly the parameter of the interested wxTextCtrl constructor
    TextControl(wxWindow *parent, wxWindowID id, const wxString &value = wxEmptyString,
                const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style = 0)
            : wxTextCtrl(parent, id, value, pos, size, style) {}

    bool getValue(double &value) override;

    void setValue(double value) override;

    void printValue() override;

    void setObserver(Observer *o);

    void notify() override;

    void OnEnter(wxCommandEvent &event);

    ~TextControl() override = default;

private:
    double value;
    Observer *observer;

DECLARE_EVENT_TABLE(); //to handle events
};

#endif //CALCSHEET_TEXTCONTROL_H
