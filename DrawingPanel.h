#ifndef DRAWINGPANEL_H
#define DRAWINGPANEL_H

#include "wx/wx.h"
#include <vector>

class DrawingPanel : public wxPanel {
public:
    DrawingPanel(wxWindow* parent, std::vector<std::vector<bool>>& gameBoardRef);
    ~DrawingPanel();

    void SetSize(const wxSize& newSize);
    void SetGridSize(int newGridSize);

private:
    void OnPaint(wxPaintEvent& event);
    void OnMouseUp(wxMouseEvent& event); // Mouse event handler

    int gridSize = 15; // Default grid size
    std::vector<std::vector<bool>>& gameBoard; // Reference to the game board

    wxDECLARE_EVENT_TABLE(); // Declare the event table
};

#endif // DRAWINGPANEL_H