#include "graphcode.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Author: Duncan A. Buell
 * Edited by Ethan Harmon
 * Date last modified: 1 November 2016
**/

static const string TAG = "GraphCode: ";

/******************************************************************************
 * Constructor
**/
GraphCode::GraphCode() {
}

/******************************************************************************
 * Destructor
**/
GraphCode::~GraphCode() {
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function 'DoTopoSort'.
 *
 * Parameter:
 *   out_stream -- the output stream to which to write the eventual result
**/
void GraphCode::DoTopoSort(ofstream& out_stream)
{
#ifdef EBUG
  cout << TAG << "enter DoTopoSort\n"; 
#endif
  vector<Node>::iterator iter;
  vector<Node>::const_iterator iter2;
  cout << "Entering DoTopoSort" << endl;

  for (iter = the_graph_.begin(); iter != the_graph_.end(); ++iter) {
    for (iter2 = the_graph_.begin(); iter2 != the_graph_.end(); ++iter2) {
      vector<int> childSubs = (*iter2).GetChildSubs();
      for (int i = 0; i < childSubs.size(); i++) {
        if (childSubs[i] == (*iter).GetNodeNumber()) {
          (*iter).IncrementIncoming();
          break;
        }
      }
    }
  }

  vector<Node> noIncoming;
  vector<Node> noIncomingReverse;
  vector<Node> thePath;
  vector<Node> thePathReverse;
  int count = 0;

  for (iter = the_graph_.begin(); iter != the_graph_.end(); ++iter) {
    if ((*iter).GetIncomingCount() == 0) {
      noIncoming.push_back((*iter));
      (*iter).SetVisited(true);
      cout << "Node " << (*iter).GetNodeNumber() << " was pushed into noIncoming." << endl;
      count++;
      vector<int> children = (*iter).GetChildSubs();
      for (int i = 0; i < children.size(); i++) {
        vector<Node>::iterator tempIter;
        for (tempIter = the_graph_.begin(); tempIter != the_graph_.end();
               ++tempIter) {
          if ((*tempIter).GetNodeNumber() == children[i]) {
            (*tempIter).DecrementIncoming();
          }
        }
      }
    }
  }

  while (!noIncoming.empty()) {
    int tempSize = noIncoming.size();
    for (int i = 0; i < tempSize; i++) {
      noIncomingReverse.push_back(noIncoming[i]);
      noIncoming.pop_back();
    }

    for (int i = 0; i < tempSize; i++) {
      Node node = noIncomingReverse.back();
      noIncomingReverse.pop_back();
      thePathReverse.push_back(node);
      node.SetVisited(true);
    }

    vector<Node>::iterator iter3;
    for (iter3 = the_graph_.begin(); iter3 != the_graph_.end(); ++iter3) {
      if ((*iter3).GetIncomingCount() == 0
           && (*iter3).HasBeenVisited() == false) {
        noIncoming.push_back(*iter3);
        vector<int> children = (*iter).GetChildSubs();
        for (int i = 0; i < children.size(); i++) {
          vector<Node>::iterator tempIter;
          for (tempIter = the_graph_.begin(); tempIter != the_graph_.end();
                 ++tempIter) {
            if ((*tempIter).GetNodeNumber() == children[i]) {
              (*tempIter).DecrementIncoming();
            }
          }
        }
        (*iter3).SetVisited(true);
        cout << "Node " << (*iter).GetNodeNumber() << " was pushed into noIncoming." << endl;
        count++;
        cout << "count: " << count << endl;
      }
    }

    for (int i = 0; i < noIncoming.size(); i++) {
      thePathReverse.push_back(noIncoming[i]);
    }
    int size = noIncoming.size();
    if (count == the_graph_.size()) {
      for (int i = 0; i < size; i++) {
        noIncoming.pop_back();
      }
    }
  }

  for (int i = 0; i < thePathReverse.size(); i++) {
    thePath.push_back(thePathReverse[i]);
  }


  if (count != the_graph_.size()) {
    cout << "This graph contains a cycle,"
         << "and cannot be topologically sorted." << endl;
    return;
  }

  out_stream << "The graph can be topologically sorted as follows:" << endl;
  vector<Node>::const_iterator iter4;
  for (iter4 = thePath.end() - 1; iter4 != thePath.begin() - 1; iter4--) {
    out_stream << (*iter4).GetNodeNumber() << " ";
  }
  cout << endl;
  return;

#ifdef EBUG
  cout << TAG << "leave DoTopoSort\n"; 
#endif

} // void GraphCode::DoTopoSort()

/******************************************************************************
 * Function 'ReadGraph'.
 * We read data from the input stream and create a graph.
 *
 * The only thing tricky about this is to make sure we have all the nodes
 * accounted for in the 'vector' since we use the subscript also as the node
 * number. That's the reason for reading in the beginning and ending node
 * numbers and creating an initial dummy 'vector'.
 *
 * Parameter:
 *     in_stream - the 'Scanner' from which to read
**/
void GraphCode::ReadGraph(Scanner& in_stream) {
  ScanLine scanline;

#ifdef EBUG
  cout << TAG << "enter ReadGraph" << endl; 
#endif

  string aStates, Alphabet;
  int numStates;
  vector<int> accept;
  vector<char> alphabet;
  vector<Node> states;

  numStates = in_stream.NextInt();
  aStates = in_stream.NextLine();
  aStates.substr(aStates.find(":") + 2);
  Alphabet = in_stream.NextLine();
  Alphabet.substr(Alphabet.find(":") + 2);

  while (aStates.HasNext()) {
    accept.push_back(aStates.NextInt());
  }

  while (Alphabet.HasNext()) {
    alphabet.push_back(Alphabet.Next());
  }

  for (int i = 0; i < numStates; i++) {
    Node node = Node(i);
    states.push_back(node);
    node.transitions = alphabet;
    for (int j = 0; j < accept.size(); j++) {
      if (i == accept[j]) {
	node.SetIsAccepting();
        break;
      }
    }
  }

  int iter = 0;
  Node currNode;

  while (in_stream.HasNext()) {
    currNode = states[iter];
    


  int first_node, last_node;
  if (in_stream.HasNext()) {
    first_node = in_stream.NextInt();
    last_node = in_stream.NextInt();
    assert ( 0 == first_node);
    // Note that we read inclusive through the 'lastNode' value.
    // Create a 'vector' of dummy nodes just so our 'vector' is of the
    //     right length.
    for(int i = 0; i <= last_node; ++i) {
      Node node = Node(i);
      the_graph_.push_back(node);
    }
  } else {
    Utils::log_stream << TAG << "Terminating. No data in input file." << endl; 
  }

  // Read line by line, one line for each node.
  // Use each line to create a 'ScanLine'.
  // Then parse each 'scanLine' instance to get the child node numbers.
  // And add each child node number to the children for the node in question.
  while (in_stream.HasNext()) {
    string the_line = in_stream.NextLine();
    scanline.OpenString(the_line);
    int parent_node_num = scanline.NextInt();
    Node node = the_graph_.at(parent_node_num);
    while( scanline.HasNext()) {
      int the_child = scanline.NextInt();

      node.AddChildSub(the_child);
    }
    this->the_graph_.at(parent_node_num) = node;
  }

#ifdef EBUG
  cout << TAG << "leave ReadGraph " << endl;
#endif
} // void GraphCode::ReadGraph(Scanner& in_stream)

/******************************************************************************
 * Function 'ToString'.
 * This is the usual 'ToString'. We output the 'vector' of 'Record'
 * instances without regard to the order.
 *
 * Returns:
 *   a formatted 'string' version of the 'vector' of records
**/
string GraphCode::ToString() const {
  string s = "";
#ifdef EBUG
  cout << TAG << "enter ToString\n"; 
#endif

  if (0 == the_graph_.size()) {
    s += "There are no nodes\n";
  } else {
    vector<Node>::const_iterator iter;
    for(iter = the_graph_.begin(); iter != the_graph_.end(); ++iter) {
      s += "Node " + (*iter).ToString();
      s += "\n";
    }
    s += "\n";
  }

#ifdef EBUG
  cout << TAG << "leave ToString\n"; 
#endif
  return s;
} // string GraphCode::ToString() const

