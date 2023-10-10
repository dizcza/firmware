#include <assert.h>

#include "MyModule.h"
#include "MeshService.h"
#include "configuration.h"
#include "main.h"

#include "esp_task_wdt.h"

#include <M5StX.h>


static MyModule *my_module = NULL;


MyModule::MyModule() : SinglePortModule("MyModule", meshtastic_PortNum_PRIVATE_APP), concurrency::OSThread("MyModule"), topmenu("Top Menu") {
    topmenu.buttons("up # select # down");
    topmenu.addItem("Spectrogram", show_spectrogram);
    my_module = this;
}


void MyModule::show_spectrogram() {
    if (M5.BtnA.read()) {
        my_module->application->stop();
        my_module->started = false;
        return;
    }
    if (!my_module->started) {
        my_module->application->begin();
        my_module->started = true;
        return;
    }
    my_module->application->loop();
}


void MyModule::setup()
{
    ez.begin();
    application = new Application(M5.Lcd);
    log_d("ESP.getChipCores() %u", ESP.getChipCores());
    log_d("Running on core %lu", xPortGetCoreID());
    log_d("Heap avail: %lu Kb", esp_get_free_heap_size() / 1024);
}


MyModule::~MyModule() {
    delete application;
}


int32_t MyModule::runOnce()
{
    esp_task_wdt_reset();
    if (application == NULL)
    {
        this->setup();
    }
    if (!started) {
        topmenu.runOnce();
    } else {
        show_spectrogram();
    }
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
