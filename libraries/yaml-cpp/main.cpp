#include "yaml-cpp/include/yaml-cpp/yaml.h"
#include <iostream>

using namespace std;

void traverseAndPrint(YAML::Node root, int depth = 0) {
  if (root.IsMap()) {
    for (YAML::iterator e = root.begin(); e != root.end(); ++e) {
      for (int i = 0; i < depth; i++) {
        cout << "  ";
      }
      cout << e->first.as<string>() << endl;
      traverseAndPrint(e->second, depth + 1);
    }
  }

  if (root.IsSequence()) {
    for (YAML::iterator e = root.begin(); e != root.end(); ++e) {
      traverseAndPrint(*e, depth + 1);
    }
  }

  if (root.IsScalar()) {
    for (int i = 0; i < depth; i++) {
      cout << "  ";
    }
    cout << root.as<string>() << endl;
  }
}

int main() {
  YAML::Node config = YAML::LoadFile("../config.yml");

  cout << "Traversal:" << endl;
  traverseAndPrint(config);
  cout << endl;

  cout << "Friends List:" << endl;
  YAML::Node friends = config["friends"];
  for (YAML::iterator e = friends.begin(); e != friends.end(); ++e) {
    cout << e->first.as<string>() << ", age " << e->second["age"] << endl;
  }
  cout << endl;

  cout << "Picking by Key:" << endl;
  cout << "foo->bar=" << config["foo"]["bar"] << endl;
}
