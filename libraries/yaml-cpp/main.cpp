#include "yaml-cpp/include/yaml-cpp/yaml.h"
#include <iostream>

using namespace std;

void traverseAndPrint(YAML::Node root, int depth = 0) {
}

int main() {
  YAML::Node config = YAML::LoadFile("../config.yml");
}
