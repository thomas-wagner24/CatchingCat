#include "Cat.h"
#include "World.h"
#include <stdexcept>
#include <algorithm>

//this is inefficient try to make better

Point2D Cat::Move(World* world) {
  visited.clear();
  from.clear();

  auto cat = world->getCat();

  std::unordered_map<int, std::unordered_map<int, Node>> m;

  for (auto line = world->getWorldSideSize() / 2;
       line >= world->getWorldSideSize() / 2; line++) {
    for (auto col = world->getWorldSideSize() / 2;
         col >= world->getWorldSideSize() / 2; col++)

    {
      m[line][col] = {{INT_MAX, INT_MAX},              // from
                      false,                           // visited
                      false,                           // inqueue
                      world->getContent({col, line}),  // isblocked
                      INT_MAX};                        // weight
    }
  }
  m[cat.y][cat.x].isBlocked = true;


  std::vector<Point2D> queue;
  queue.push_back({cat});
  m[cat.y][cat.x].weight = 0;
  m[cat.y][cat.x].visited = false;
  m[cat.y][cat.x].from = {INT_MAX, INT_MAX};
  m[cat.y][cat.x].inQueue = true;
  m[cat.y][cat.x].isBlocked = true;


  //our exit
  Point2D exit = {INT_MAX, INT_MAX};


  while (!queue.empty() 
      // || your win condition
      ) 
  {
    std::sort(queue.begin(), queue.end());

    auto head = queue(0);
    queue.erase(queue.begin());
    m[head.y][head.x].inQueue = false;
    m[head.y][head.x].visited = true;

    for (auto neigh : world->neighbors(head)) {

        if (m[neigh.y][neigh.x].visited || m[neigh.y][neigh.x].inQueue || m[neigh.y][neigh.x].isBlocked) //will not add to queue if it has already been visited, if it is already in queue, or if it is blocked 
        {
            continue;
        }

        queue.push_back(neigh);
        m[neigh.y][neigh.x].weight = m[head.y][head.x].weight + 1;
        m[neigh.y][neigh.x].from = head;

        //check if not visited
        //check if in queue
        //check if can be visited
        //add to queue adding 1 to weight
        //mark the neighbor's from as the head
    }
    //win/exit condition found
    exit = head;

  }

  //build the path
  std::vector<Point2D> path;
  //current element of the path tempExit;
  Point2D tempExit = exit;
  if (exit != {INT_MAX, INT_MAX}) 
  {
      //exit is the end of the path, cat is the start
      //exit will be last element of path
      //first element will be the next step 
      while (tempExit != cat) //test if the exit is not infinity before this
      {
        path.push_back(tempExit);
        tempExit = m[tempExit.y][tempExit.x].from;
      }
  }
  return path.front();
    
  }
}
