/****************************************************************
 * Header file for a node in a graph.
 *
 * Author/copyright:  Duncan Buell
 * Edited by: Ethan Harmon
 * Date: 7 May 2015
 *
**/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <string> // I included this in order to make the
                  // ToString() function easily writeable.
using namespace std;

#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class Node {
public:
 Node();
 Node(int node_number);
 virtual ~Node();

 void AddTransition(int which);
 void DecrementIncoming() ;
 vector<int> GetTransitions() const;
 int GetIncomingCount() const;
 int GetNodeNumber() const;
 int GetNumberOfChildren() const;
 bool HasBeenVisited() const;
 void IncrementIncoming() ;
 void SetVisited(bool what);

 bool IsAccepting() const;
 void SetIsAccepting();

 string ToString() const;

private:
 int kDummyNodeNumber = -99;
 bool visited_;
 int node_number_ = kDummyNodeNumber;
 int incoming_ = 0;
 bool accepting = false;

 vector<int> transitions;
 vector<int> nextStates;
};

#endif
