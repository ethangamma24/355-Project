#include "main.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Homework 3 main program.
 *
 * This program reads a directed graph and does the source removal algorithm
 * to produce a topological sort of the nodes.
 *
 * Author: Duncan A. Buell
 * Date last modified: 19 October 2015
**/

int main(int argc, char *argv[]) {
  string infilename = "";
  string outfilename = "";
  string logfilename = "";
  ofstream out_stream;

  Scanner in_stream;

  GraphCode graphcode;

  Utils::CheckArgs(3, argc, argv, "infilename outfilename logfilename");
  infilename = static_cast<string>(argv[1]);
  outfilename = static_cast<string>(argv[2]);
  logfilename = static_cast<string>(argv[3]);

  Utils::LogFileOpen(logfilename);

  Utils::log_stream << "Beginning execution\n";

  Utils::FileOpen(out_stream, outfilename);

  Utils::log_stream << "infile  '" << infilename << "'\n";
  Utils::log_stream << "outfile '" << outfilename << "'\n";
  Utils::log_stream << "logfile '" << logfilename << "'\n";

  in_stream.OpenFile(infilename);
//  graphcode.CreateGraph(instream);
  graphcode.ReadGraph(in_stream);
  in_stream.Close();

  out_stream << "RAW GRAPH\n" << graphcode.ToString() << endl;

  out_stream << "TOPO SORT\n";
  graphcode.DoTopoSort(out_stream);

  Utils::FileClose(out_stream);

  Utils::log_stream << "Ending execution\n";

  Utils::FileClose(Utils::log_stream);

  return 0;
}
