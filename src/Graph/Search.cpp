#ifndef SEARCH_CPP
#define SEARCH_CPP

#include "Node.cpp"
#include <iostream>
#include <map>
#include <memory>
#include <vector>
using namespace std;

class PathNode {
public:
  PathNode(shared_ptr<Node> NODE) { node = NODE; }

  shared_ptr<Node> node;

  void setParnet(shared_ptr<PathNode> Parnet) { parent = Parnet; }

  shared_ptr<PathNode> getParent() { return parent; }

private:
  shared_ptr<PathNode> parent;
};

class AStarPathNode {
public:
  AStarPathNode(shared_ptr<Node> Self, shared_ptr<Node> Goal) {
    self = Self;
    distanceGoal = Self->Calcdistance(Goal);
  }
  shared_ptr<Node> self;
  shared_ptr<AStarPathNode> parent;
  float stepScore = 0;
  float distanceGoal = 0;
  float totalScore = 0;
};

class Search {

private:
  static int Findlowest(vector<shared_ptr<AStarPathNode>> vec) {
    int index = 0;
    int m = vec[0]->totalScore;
    for (int i = 0; i < vec.size(); i++) {
      if (m > vec[i]->totalScore) {
        m = vec[i]->totalScore;
        index = i;
      }
    }
    return index;
  }

public:
  // Breadth First Search
  static vector<string> BFS(shared_ptr<Node> start, shared_ptr<Node> end) {

    map<string, bool> visited;
    vector<shared_ptr<PathNode>> queue;
    queue.push_back(shared_ptr<PathNode>(new PathNode(start)));
    queue[0]->setParnet(nullptr);

    while (queue.size() != 0) {

      shared_ptr<Node> currentNode = queue[0]->node;
      shared_ptr<PathNode> path = queue[0];

      if (currentNode->name == end->name) {
        vector<string> paths;
        shared_ptr<PathNode> currentpath = path;

        while (currentpath != nullptr) {
          paths.insert(paths.begin(), currentpath->node->name);
          currentpath = currentpath->getParent();
        }

        return paths;
      }

      // Remove first Element
      queue.erase(queue.begin());

      if (visited[currentNode->name])
        continue;

      vector<shared_ptr<Node>> neighbors = currentNode->GetNeighbor();

      for (shared_ptr<Node> neighbor : neighbors) {
        shared_ptr<PathNode> newPathNode =
            shared_ptr<PathNode>(new PathNode(neighbor));
        newPathNode->setParnet(path);
        queue.push_back(newPathNode);
      }
      visited[currentNode->name] = true;
    }
    return vector<string>();
  }

  // Depth First Search
  static vector<string> DFS(shared_ptr<Node> start, shared_ptr<Node> end) {
    map<string, bool> visited;
    vector<shared_ptr<PathNode>> stack;
    stack.push_back(shared_ptr<PathNode>(new PathNode(start)));
    stack[0]->setParnet(nullptr);

    while (stack.size() != 0) {

      shared_ptr<Node> currentNode = stack.back()->node;
      shared_ptr<PathNode> path = stack.back();

      if (currentNode->name == end->name) {
        vector<string> paths;
        shared_ptr<PathNode> currentpath = path;

        while (currentpath != nullptr) {
          paths.insert(paths.begin(), currentpath->node->name);
          currentpath = currentpath->getParent();
        }

        return paths;
      }

      // Remove last Element
      stack.pop_back();

      if (visited[currentNode->name])
        continue;

      vector<shared_ptr<Node>> neighbors = currentNode->GetNeighbor();

      for (shared_ptr<Node> neighbor : neighbors) {
        shared_ptr<PathNode> newPathNode =
            shared_ptr<PathNode>(new PathNode(neighbor));
        newPathNode->setParnet(path);
        stack.push_back(newPathNode);
      }
      visited[currentNode->name] = true;
    }
    return vector<string>();
  }

  static vector<string> AStar(shared_ptr<Node> start, shared_ptr<Node> end) {
    vector<shared_ptr<AStarPathNode>> Open;
    Open.push_back(shared_ptr<AStarPathNode>(new AStarPathNode(start, end)));
    Open[0]->stepScore = 0;
    Open[0]->totalScore = Open[0]->distanceGoal + Open[0]->stepScore;

    map<string, bool> Close;
    while (Open.size() > 0) {
      int index = Findlowest(Open);
      shared_ptr<AStarPathNode> currentPath = Open[index];

      if (currentPath->self->name == end->name) {

        vector<string> paths;
        shared_ptr<AStarPathNode> cur_path = currentPath;

        while (cur_path != nullptr) {
          paths.insert(paths.begin(), cur_path->self->name);
          cur_path = cur_path->parent;
        }

        return paths;
      }

      for (shared_ptr<Node> neighbor : currentPath->self->GetNeighbor()) {
        if (Close[neighbor->name])
          continue;
        shared_ptr<AStarPathNode> Path =
            shared_ptr<AStarPathNode>(new AStarPathNode(neighbor, end));
        Path->parent = currentPath;
        Path->stepScore =
            currentPath->stepScore + neighbor->Calcdistance(currentPath->self);
        Path->totalScore = Path->stepScore + Path->distanceGoal;

        Open.push_back(Path);
      }
      Open.erase(Open.begin() + index);
      Close[currentPath->self->name] = true;
    }
    return vector<string>();
  }
};

#endif
