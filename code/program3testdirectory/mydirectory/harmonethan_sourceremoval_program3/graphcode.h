/****************************************************************
 * Homework 4 header file for the application class.
 *
 * Author/copyright:  Duncan Buell
 * Date: 13 July 2015
 *
**/

#ifndef GRAPHCODE_H
#define GRAPHCODE_H

#include <iostream>
#include <vector>
using namespace std;

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

#include "node.h"
#include "myrandom.h"

class GraphCode {
public:
 GraphCode();
 virtual ~GraphCode();

 void CreateGraph(Scanner& in_stream);
// void DescendFrom(ofstream& out_stream, string blanks, Node node);
 void DoTopoSort(ofstream& out_stream);
 void ReadGraph(Scanner& in_stream);
 string ToString() const;

private:
 vector<string> path_;
 vector<Node> the_graph_;

 string ToStringChildren(string blanks, const vector<int>& children) const;
 string ToStringPath(string blanks) const;
};

#endif
