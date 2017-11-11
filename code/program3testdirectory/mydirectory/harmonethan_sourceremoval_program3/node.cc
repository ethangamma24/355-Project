#include "node.h"

/******************************************************************************
 * Class for creating and handling nodes.
 * Author: Ethan M. Harmon. All Rights Reserved.
 * Date last modified: 27 October 2016
**/

/******************************************************************************
 * Constructors
**/
Node::Node() {
}

Node::Node(int node_number) {
  node_number_ = node_number;
}

/******************************************************************************
 * Destructor
**/
Node::~Node() {
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function 'AddChildSub'.
 *
 * Parameter:
 *   int which -- The index of the child to be added.
**/

void Node::AddTransition(int which) {
  transitions.push_back(which);
  return;
}

/******************************************************************************
 * Function 'IncrementIncoming'.
**/

void Node::IncrementIncoming() {
  incoming_++;
  return;
}

/******************************************************************************
 * Function 'DecrementIncoming'.
**/

void Node::DecrementIncoming() {
  incoming_--;
  return;
}

/******************************************************************************
 * Function 'GetChildSubs'.
**/

vector<int> Node::GetTransitions() const {
  return transitions;
}

/******************************************************************************
 * Function 'GetIncomingCount'.
**/

int Node::GetIncomingCount() const {
  return incoming_;
}

/******************************************************************************
 * Function 'GetNodeNumber'.
**/

int Node::GetNodeNumber() const {
  return node_number_;
}

/******************************************************************************
 * Function 'GetNumberOfChildren'.
**/

int Node::GetNumberOfChildren() const {
  return child_subs_.size();
}

/******************************************************************************
 * Function 'HasBeenVisited'.
**/

bool Node::HasBeenVisited() const {
  return visited_;
}

/******************************************************************************
 * Function 'SetVisited'.
 *
 * Parameter:
 *   bool what -- A boolean whose truth is based on whether the node has been
 *                visited or not.
**/

void Node::SetVisited(bool what) {
  visited_ = what;
  return;
}

/******************************************************************************
 * Function 'IsAccepting'.
 *
 * Returns either true or false, depending on whether the state is accepting
 * or not.
**/

bool Node::IsAccepting() {
  return accepting;
}

/******************************************************************************
 * Function 'SetIsAccepting'.
**/

void Node::SetIsAccepting() {
  accepting = true;
}

/******************************************************************************
 * Function 'ToString'.
**/

string Node::ToString() const {
  std::string number = std::to_string(GetNodeNumber());
  return number;
}