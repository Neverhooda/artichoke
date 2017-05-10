#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>

//#include <QApplication>

#include <ns3/core-module.h>
#include <ns3/nstime.h>
#include <ns3/simulator.h>
#include <ns3/packet.h>
#include <ns3/output-stream-wrapper.h>
#include <ns3/gnuplot.h>
#include <ns3/trace-source-accessor.h>

#include "ns3/plc.h"

using namespace ns3;


int main ()//(int argc, char *argv[])
{
	PLC_SpectrumModelHelper smHelper;
  Ptr<const SpectrumModel> sm;
  sm = smHelper.GetSpectrumModel(0, 10e6, 100);
  // Set up channel
  Ptr<PLC_Node> n1 = CreateObject<PLC_Node> ();
  Ptr<PLC_Node> n2 = CreateObject<PLC_Node> ();
  PLC_NodeList nodes;
  nodes.push_back(n1);
  nodes.push_back(n2);
  //
  PLC_ChannelHelper channelHelper(sm); channelHelper.Install(nodes);
  Ptr<PLC_Channel> channel = channelHelper.GetChannel();

  n1->SetPosition(0,0,0);
  n2->SetPosition(1000,0,0);
  Ptr<PLC_Cable> cable = CreateObject<PLC_NAYY150SE_Cable> (sm); // Link nodes
  CreateObject<PLC_Line> (cable, n1, n2);
  return 0;
}
