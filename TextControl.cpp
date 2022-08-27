//
// Created by giacomo on 10/08/22.
//

#include "TextControl.h"
#include <string>


bool TextControl::getValue(double &value) { //to get the value inserted in the cell
    wxString string = wxTextCtrl::GetValue();

    if (string.ToDouble(&value))
        return true;
    else {
        value = 0;
        return false;
    }
}

void TextControl::setValue(double v) {
    value = v;
    printValue();
}

void TextControl::printValue() {
    this->Clear();
    this->AppendText(std::to_string(value));
}

void TextControl::setObserver(Observer *o) {
    observer = o;
}

void TextControl::notify() {
    observer->update();
}

void TextControl::OnEnter(wxCommandEvent &event) {
    notify();
}
//event handling
BEGIN_EVENT_TABLE(TextControl, wxTextCtrl)
                EVT_TEXT_ENTER(0, TextControl::OnEnter)
END_EVENT_TABLE()
