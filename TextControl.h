//
// Created by giacomo on 10/08/22.
//

#ifndef CALCSHEET_TEXTCONTROL_H
#define CALCSHEET_TEXTCONTROL_H


#include <wx/wx.h>
#include <list>
#include "Subject.h"
#include "Observer.h"

class TextControl : public wxTextCtrl, public Subject {
public:
    TextControl(wxWindow *parent, wxWindowID id, const wxString &value = wxEmptyString,
                const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize, long style = 0,
                Observer *obs = nullptr);

    double getValue() override;

    void setValue(double v) override;

    void printValue() override;

    void notify() override;

    ~TextControl();

private:
    double value;
    Observer *observer;
};


#endif //CALCSHEET_TEXTCONTROL_H
