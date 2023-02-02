#include <iostream>
#include <list>

using namespace std;

class EditorState {
private:
  string content;

public:
  EditorState(string content);
  string getContent();
};

EditorState::EditorState(string content) : content(content){};
string EditorState::getContent() { return this->content; }

class History {
private:
  list<EditorState *> states;

public:
  void push(EditorState *state);
  EditorState *pop();
};

void History::push(EditorState *state) { this->states.push_back(state); }
EditorState *History::pop() {
  this->states.pop_back();
  return this->states.back();
}

class Editor {
private:
  string content;

public:
  Editor() {}
  string getContent(void);
  void setContent(string content);
  EditorState *careteState();
  void restore(EditorState *state);
};

string Editor::getContent(void) { return this->content; }
void Editor::setContent(string content) { this->content = content; }
EditorState *Editor::careteState() {
  return new EditorState(this->getContent());
}
void Editor::restore(EditorState *state) {
  this->content = state->getContent();
}
int main(int argc, char const *argv[]) {
  Editor editor;
  History history;
  editor.setContent("HEY MOME");
  history.push(editor.careteState());
  editor.setContent("HEY DADE");
  history.push(editor.careteState());
  editor.setContent("HEY LOL");
  history.push(editor.careteState());
  editor.restore(history.pop());
  cout << editor.getContent() << endl;
  //   cout << editor.getContent() << endl;
  return 0;
}
