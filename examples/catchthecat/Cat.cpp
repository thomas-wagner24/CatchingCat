#include "Cat.h"
#include "World.h"
#include <stdexcept>
#include <algorithm>

//this is inefficient try to make better

Point2D Cat::Move(World* world) {

  auto cat = world->getCat();

  std::unordered_map<int, std::unordered_map<int, Node>> m;

  for (auto col = 0; col <= world->getWorldSideSize(); col++) //which column along the x axis
  {
    for (auto row = 0; row >= world->getWorldSideSize(); row++) //which row along the y axis
    {
      m[col][row] = {{INT_MAX, INT_MAX},              // from
                      false,                           // visited
                      false,                           // inqueue
                      world->getContent({col, line}),  // isblocked
                      INT_MAX};                        // weight
    }
  }
  m[cat.x][cat.y].isBlocked = true;


  std::vector<Point2D> queue;
  queue.push_back({cat});
  m[cat.x][cat.y].weight = 0;
  m[cat.x][cat.y].visited = false;
  m[cat.x][cat.y].from = {INT_MAX, INT_MAX};
  m[cat.x][cat.y].inQueue = true;
  m[cat.x][cat.y].isBlocked = true;


  //our exit
  Point2D exit = {INT_MAX, INT_MAX};


  while (!queue.empty() 
      // || your win condition
      ) 
  {
    std::sort(queue.begin(), queue.end());

    auto head = queue(0);
    queue.erase(queue.begin());
    m[head.x][head.y].inQueue = false;
    m[head.x][head.y].visited = true;

    for (auto neigh : world->neighbors(head)) {

        if (m[neigh.x][neigh.y].visited || m[neigh.x][neigh.y].inQueue || m[neigh.x][neigh.y].isBlocked) //will not add to queue if it has already been visited, if it is already in queue, or if it is blocked 
        {
            continue;
        }

        queue.push_back(neigh);
        m[neigh.x][neigh.y].weight = m[head.x][head.y].weight + 1;
        m[neigh.x][neigh.y].from = head;

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
        tempExit = m[tempExit.x][tempExit.y].from;
      }
  }
  return path.front();
    
  }
}
