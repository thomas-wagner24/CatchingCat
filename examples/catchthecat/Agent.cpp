#include "Agent.h"

bool Node::operator<(const Node& rhs) const {
  return this->weight < rhs.weight;

}