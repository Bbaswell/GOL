#include "App.h"

bool App::OnInit() {
    mainWindow = new MainWindow(); // Instantiate the MainWindow
    mainWindow->Show();           // Show the MainWindow
    return true;                  // Return true to continue running the app
}
