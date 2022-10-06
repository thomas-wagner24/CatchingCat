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
/*
struct queueEntry {
  Point2D position;
  int weight;
  bool operator < (const queueEntry& rhs) const;
};
*/
class Agent {
public:
  explicit Agent()= default;;
  virtual Point2D Move(World*)=0;

  //std::unordered_map<int, std::unordered_map<int, bool>> visited;

  //std::unordered_map<int, std::unordered_map<int, Point2D>> from; //where the agent has come from, the path

};

#endif  // AGENT_H
