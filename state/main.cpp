#include <iostream>

using namespace std;

// this is an abstarct class
class Tool {
public:
  virtual void mouseUp() = 0;
  virtual void mouseDown() = 0;
};

class SelectionTool : public Tool {
  void mouseDown();
  void mouseUp();
};

void SelectionTool::mouseDown() { cout << "show selection icon" << endl; }
void SelectionTool::mouseUp() { cout << "draw a rectengle" << endl; }

class BrushTool : public Tool {
  void mouseDown();
  void mouseUp();
};

void BrushTool::mouseDown() { cout << "show brush icon" << endl; }
void BrushTool::mouseUp() { cout << "draw a line" << endl; }

class Canvas {
private:
  Tool *currentTool;

public:
  void mouseUp();
  void mouseDown();
  void setTool(Tool *tool);
};

void Canvas::mouseDown() { this->currentTool->mouseDown(); }
void Canvas::mouseUp() { this->currentTool->mouseUp(); }
void Canvas::setTool(Tool *tool) { this->currentTool = tool; }

int main(int argc, char const *argv[]) {
  Canvas canva;
  canva.setTool(new SelectionTool);
  canva.mouseDown();
  canva.mouseUp();
  canva.setTool(new BrushTool);
  canva.mouseDown();
  canva.mouseUp();
  return 0;
}
