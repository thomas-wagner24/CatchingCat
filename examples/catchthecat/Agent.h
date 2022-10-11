#ifndef AGENT_H
#define AGENT_H
#include "Point2D.h"
#include <unordered_map>


class World;

struct Node
{
  Point2D from;
  bool visited;
  bool inQueue;
  bool isBlocked;
  int weight;
  bool operator<(const Node& rhs) const;
};

class Agent {
public:
  explicit Agent()= default;;
  virtual Point2D Move(World*)=0;


};

#endif  // AGENT_H
