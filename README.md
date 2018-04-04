01.04.2018.
Original repository is https://github.com/witnessmenow/arduino-ifttt-maker
Credits goes to original author.

Original library is changed with aim to enable destroying the object, and releasing the memory.

# arduino-ifttt-maker
A library for raising events on the maker service on [IFTTT](https://ifttt.com). (Basically create the "this" in an IFTTT from your arduino)

## Installing & Usage

The downloaded code can be included as a new library into the IDE selecting the menu:

     Sketch / include Library / Add .Zip library

You also have to install the ArduinoJson library written by [Benoît Blanchon](https://github.com/bblanchon). Search for it on the Arduino Library manager or get it from [here](https://github.com/bblanchon/ArduinoJson).

Include IFTTTwebhooks in your project:

    #include <IFTTTwebhooks.h>

and pass it a Maker service key (you can find it [here](https://ifttt.com/services/maker_webhooks/settings) and a SSL Client (See the examples for more details)

    #define KEY "zzzzzzzzzzzzzzzzzzzzzzz"
    #define EVENT_NAME "device_on"

    IFTTTwebhooks* client = nullptr;

    // Use IFTTTwebhooks class to create a new TLS connection
    client = new IFTTTwebhooks(KEY);

    client->triggerEvent(EVENT_NAME, ssid, ip.toString()); //returns true if successful
    //triggerEvent takes an Event Name and then you can optional pass in up to 3 extra Strings

    // delete IFTTTwebhooks object
      delete client;
      client = nullptr;
