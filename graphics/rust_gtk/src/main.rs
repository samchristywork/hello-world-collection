use gtk::prelude::*;
use gtk::{Application, ApplicationWindow, Button};

fn main() {
    let application = Application::builder()
        .build();

    application.connect_activate(|app| {
        let window = ApplicationWindow::builder()
            .application(app)
            .title("GTK Test")
            .default_width(100)
            .default_height(100)
            .build();

        let b = gtk::Box::new(gtk::Orientation::Vertical, 0);
        window.add(&b);
        {
          let button = Button::with_label("Button 1");
          b.add(&button);
          button.connect_clicked(|_| {
              eprintln!("Clicked the first button.");
          });
        }
        {
          let button = Button::with_label("Button 2");
          b.add(&button);
          button.connect_clicked(|_| {
              eprintln!("This is button 2.");
          });
        }
        {
          let button = Button::with_label("Button 3");
          b.add(&button);
          button.connect_clicked(|_| {
              eprintln!("This is the third button.");
          });
        }
        {
          let button = Button::with_label("Button 4");
          b.add(&button);
          button.connect_clicked(|_| {
              eprintln!("Button four!");
          });
        }

        window.show_all();
    });

    application.run();
}
