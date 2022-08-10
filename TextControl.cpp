//
// Created by giacomo on 10/08/22.
//

#include "TextControl.h"

TextControl::TextControl(wxWindow *parent, wxWindowID id, const wxString &value, const wxPoint &pos, const wxSize &size,
                         long style)
        : wxTextCtrl(parent, id, value, pos, size, style) {
}

double TextControl::getValue() {
    return value;
}

void TextControl::setValue(double v) {
    value = v;
}

void TextControl::printValue() {
    this->AppendText(char(value));
}

void TextControl::setObserver(Observer *o) {
    observer = o;
}

void TextControl::notify() { //TODO CORRECT AND ADJUST
    observer->update();
}

void TextControl::OnEnter(wxKeyEvent &event) {
    wxMessageBox("You pressed a key");
    notify();
}

BEGIN_EVENT_TABLE(TextControl, wxTextCtrl) //TODO FIND THE RIGHT EVENT
        EVT_CHAR_HOOK(TextControl::OnEnter)
END_EVENT_TABLE()
