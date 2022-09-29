#include "Cat.h"
#include "World.h"
#include <stdexcept>
#include <algorithm>


Point2D Cat::Move(World* world) {

  visited.clear();
  from.clear();
  std::vector<queueEntry> queue;
  queue.push_back({world->getCat(), 0});

  while (!queue.empty()) {
    std::sort(queue.begin(), queue.end());

    auto head = queue(0);
    queue.erase(queue.begin());
    visited[head.position.x][head.position.y] = true;
    // remove the head (first element)
    //mark head as visited
    //for each neighbor, 
    //  if it is not visited (and is not blocked off by catcher), add to queue with one unit of weight increased (currnt weight + 1)
    //  mark where this element came from (current position, current weight)

  }


  //visited[0][0] = true;
 // visited[-5][0] = true;
  /*
  start in 0,0
  visited[0][0] = true;
  from[0][0] = Point(- infinity, - infinity) (not from anywhere) (MIN_INT)

  go to (1, 0)
  visited[1][0] = true;
  from[1][0] = Point(0,0)
  from[1][0].weight = (1,0) weight + from[1][0] weight; (weight of previous and current)
  
  
  
  */



  auto rand = Random::Range(0,5);
  auto pos = world->getCat();
  switch(rand){
    case 0:
      return World::NE(pos);
    case 1:
      return World::NW(pos);
    case 2:
      return World::E(pos);
    case 3:
      return World::W(pos);
    case 4:
      return World::SW(pos);
    case 5:
      return World::SE(pos);
    default:
      throw "random out of range";
  }
}
