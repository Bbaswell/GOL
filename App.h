#pragma once
#ifndef APP_H
#define APP_H

#include "wx/wx.h"
#include "MainWindow.h"

class App : public wxApp {
private:
    MainWindow* mainWindow;

public:
    virtual bool OnInit();
};

#endif // APP_H
