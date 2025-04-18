/**
 * @file DebugDataTable.h
 * This file declares a table for generic handling of streamable debug data.
 * Representations mentioned in the table will be overwritten with the table
 * entry.
 *
 * @author Michael Spranger
 * @author Tobias Oberlies
 * @author Thomas Röfer
 */

#pragma once

#include "Streaming/InStreams.h"
#include "Streaming/MessageQueue.h"
#include <string>

/**
 * @class DebugDataTable
 *
 * A class that maintains the debug data table.
 */
class DebugDataTable final
{
private:
  std::unordered_map<std::string, char*> table;

public:
  /**
   * Default constructor.
   */
  DebugDataTable() = default;

  DebugDataTable(const DebugDataTable&) = delete;

  ~DebugDataTable();

  /**
   * Registers the object with the debug data table and updates the object if the
   * respective entry in the table has been modified through RobotControl.
   */
  template<typename T> void updateObject(const char* name, T& t, bool once);
  void processChangeRequest(MessageQueue::Message message);
};

template<typename T> void DebugDataTable::updateObject(const char* name, T& t, bool once)
{
  // Find entry in debug data table
  std::unordered_map<std::string, char*>::iterator iter = table.find(name);
  if(iter != table.end())
  {
    InBinaryMemory stream(iter->second);
    stream >> t;
    if(once)
    {
      delete[] iter->second;
      table.erase(iter);
    }
  }
}
