#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "wx/wx.h"
#include "DrawingPanel.h"
#include <vector>

// Unique IDs for toolbar buttons
enum {
    ID_PLAY = 10001,
    ID_PAUSE,
    ID_NEXT,
    ID_CLEAR
};

class MainWindow : public wxFrame {
public:
    MainWindow();
    ~MainWindow();

private:
    int gridSize = 15;
    std::vector<std::vector<bool>> gameBoard;

    int generationCount = 0;
    int livingCellsCount = 0;

    DrawingPanel* drawingPanel = nullptr;
    wxStatusBar* statusBar = nullptr;
    wxToolBar* toolBar = nullptr;

    void InitializeGrid();
    void UpdateStatusBar();
    void OnSizeChange(wxSizeEvent& event);

    // Toolbar event handlers
    void OnPlay(wxCommandEvent& event);
    void OnPause(wxCommandEvent& event);
    void OnNext(wxCommandEvent& event);
    void OnClear(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

#endif // MAINWINDOW_H
