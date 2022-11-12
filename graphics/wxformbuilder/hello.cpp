#include "generated_code/noname.h"
#include <wx/wx.h>

class Hello : public wxApp {
public:
  virtual bool OnInit();
};

// Derived class overrides the callbacks of the parent class
class MyFrame2 : public MyFrame1 {
public:
  MyFrame2(wxWindow *parent) : MyFrame1(parent) {}
  void hello_world(wxCommandEvent &event) {
    puts("hi");
  }
};

bool Hello::OnInit() {
  MyFrame2 *frame = new MyFrame2(NULL);
  frame->Show(true);
  return true;
}

wxIMPLEMENT_APP(Hello);
