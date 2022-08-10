//
// Created by giacomo on 10/08/22.
//

#include "TextControl.h"

TextControl::TextControl(wxWindow *parent, wxWindowID id, const wxString &value, const wxPoint &pos, const wxSize &size,
                         long style, Observer *obs)
        : wxTextCtrl(parent, id, value, pos, size, style) {
    observer = obs;
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

void TextControl::notify() {
    observer->update();
}

void TextControl::OnEnter(wxCommandEvent &event) {
    notify();
}

wxBEGIN_EVENT_TABLE(TextControl, wxTextCtrl)
                EVT_COMMAND_ENTER(wxEVT_TEXT_ENTER, TextControl::OnEnter)
wxEND_EVENT_TABLE()
