#include <assert.h>

#include "MyModule.h"
#include "MeshService.h"
#include "configuration.h"
#include "main.h"

#include <M5StX.h>
#include <M5ez.h>

MyModule::MyModule() : SinglePortModule("MyModule", meshtastic_PortNum_PRIVATE_APP), concurrency::OSThread("MyModule"), application(M5.lcd) {}

void MyModule::setup()
{
    ez.begin();
    log_d("ESP.getChipCores() %d", ESP.getChipCores());
    log_d("Heap avail: %lu Kb", esp_get_free_heap_size() / 1024);
    application.begin();
    initialized = true;
}

int32_t MyModule::runOnce()
{
    if (!initialized)
    {
        this->setup();
    }
    application.loop();
    return 100;
}

meshtastic_MeshPacket *MyModule::allocReply()
{
    assert(currentRequest); // should always be !NULL
#ifdef DEBUG_PORT
    auto req = *currentRequest;
    auto &p = req.decoded;
    // The incoming message is in p.payload
    LOG_INFO("Received message from=0x%0x, id=%d, msg=%.*s\n", req.from, req.id, p.payload.size, p.payload.bytes);
#endif

    screen->print("Sending reply\n");

    const char *replyStr = ">>> My custom reply!!!";
    auto reply = allocDataPacket();                 // Allocate a packet for sending
    reply->decoded.payload.size = strlen(replyStr); // You must specify how many bytes are in the reply
    memcpy(reply->decoded.payload.bytes, replyStr, reply->decoded.payload.size);

    return reply;
}
