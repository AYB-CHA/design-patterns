#include <iostream>

using namespace std;

class AuditTrail {
public:
  void record(int id);
};
void AuditTrail::record(int id) { cout << "Record Task! id = " << id << endl; }

class Task {
private:
  AuditTrail audit_trail;
  void virtual doExcute() = 0;

public:
  void excute(int id);
};

void Task::excute(int id) {
  this->doExcute();
  this->audit_trail.record(id);
}

class TransformMoney : public Task {
private:
  void doExcute() { cout << "TRANSFORMING MONEY" << endl; }
};

class GenerateReport : public Task {
private:
  void doExcute() { cout << "generating report..." << endl; }
};

int main(int argc, char const *argv[]) {
  TransformMoney transform_money;
  transform_money.excute(500);

  GenerateReport report_generator;
  report_generator.excute(600);
  return 0;
}
