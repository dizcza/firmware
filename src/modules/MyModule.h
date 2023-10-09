#pragma once
#include "concurrency/OSThread.h"
#include "SinglePortModule.h"
#include "Application.h"

/**
 * A simple example module that just replies with "Message received" to any message it receives.
 */
class MyModule : public SinglePortModule, private concurrency::OSThread
{
private:
  Application application;
  bool initialized = false;

public:
  /** Constructor
   * name is for debugging output
   */
  MyModule();

protected:
  /** For reply module we do all of our processing in the (normally optional)
   * want_replies handling
   */
  virtual meshtastic_MeshPacket *allocReply() override;

  virtual int32_t runOnce() override;

  virtual void setup() override;
};
