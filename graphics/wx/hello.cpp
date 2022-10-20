/*
 * Please note that this example was taken from:
 *
 * https://docs.wxwidgets.org/latest/overview_helloworld.html
 */

#include <wx/wx.h>

class Hello : public wxApp {
public:
  virtual bool OnInit();
};

class Frame : public wxFrame {
public:
  Frame();

private:
  void OnHello(wxCommandEvent &event);
  void OnExit(wxCommandEvent &event);
  void OnAbout(wxCommandEvent &event);
};

enum {
  ID_Hello = 1
};

bool Hello::OnInit() {
  Frame *frame = new Frame();
  frame->Show(true);
  return true;
}

Frame::Frame() : wxFrame(nullptr, wxID_ANY, "Hello, World!") {
  wxMenu *menuFile = new wxMenu;
  menuFile->Append(ID_Hello, "&Hello\tCtrl-H", "Status bar message.");
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);

  wxMenu *menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT, "&About\tCtrl-A");

  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  menuBar->Append(menuHelp, "&Help");

  SetMenuBar(menuBar);

  CreateStatusBar();
  SetStatusText("Hello, World!");

  Bind(wxEVT_MENU, &Frame::OnHello, this, ID_Hello);
  Bind(wxEVT_MENU, &Frame::OnAbout, this, wxID_ABOUT);
  Bind(wxEVT_MENU, &Frame::OnExit, this, wxID_EXIT);
}

void Frame::OnExit(wxCommandEvent &event) {
  Close(true);
}

void Frame::OnAbout(wxCommandEvent &event) {
  wxMessageBox("Hello, World!", "About", wxOK | wxICON_INFORMATION);
}

void Frame::OnHello(wxCommandEvent &event) {
  wxLogMessage("Hello world from wxWidgets!");
}

wxIMPLEMENT_APP(Hello);
