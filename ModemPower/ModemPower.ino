#include "Constants.h"
#include "Pins.h"
#include "SerialPorts.h"

// Turns modem ON
void powerOn()
{
    digitalWrite(A7608H_PWRKEY_PIN, HIGH);
    delay(A7608H_POWER_ON_PULSE);

    digitalWrite(A7608H_PWRKEY_PIN, LOW);
    delay(A7608H_AFTER_POWER_DELAY);

    DebugSerial.println("Power On Completed");
}

// Turns modem OFF
void powerOff()
{
    digitalWrite(A7608H_PWRKEY_PIN, HIGH);
    delay(A7608H_POWER_OFF_PULSE);
    
    digitalWrite(A7608H_PWRKEY_PIN, LOW);
    delay(A7608H_POWER_OFF_DELAY);

    DebugSerial.println("Power Off Completed");
}

// Resets modem
void reset()
{
    digitalWrite(A7608H_RESET_PIN, HIGH);
    delay(A7608H_RESET_PULSE);

    digitalWrite(A7608H_RESET_PIN, LOW);
    delay(A7608H_AFTER_RESET_DELAY);

    DebugSerial.println("Reset Completed");
}

// Initialization
void setup()
{
    // Initialize modem control PINs.
    pinMode(A7608H_DTR_PIN, OUTPUT);
    pinMode(A7608H_RESET_PIN, OUTPUT);
    pinMode(A7608H_PWRKEY_PIN, OUTPUT);
    delay(10);

    digitalWrite(A7608H_DTR_PIN, LOW);
    digitalWrite(A7608H_RESET_PIN, LOW);
    digitalWrite(A7608H_PWRKEY_PIN, LOW);
    delay(10);

    DebugSerial.begin(DEBUG_BAUD_RATE);
    ModemSerial.begin(MODEM_BAUD_RATE, SERIAL_8N1, A7608H_RX_PIN, A7608H_TX_PIN);

    // Allow Serail Monitor connect to the board.
    delay(3000);

    DebugSerial.println("***********************************************************");
    DebugSerial.println(" Enter \"poweron\" to turn modem ON");
    DebugSerial.println(" Enter \"poweroff\" to turn modem OFF");
    DebugSerial.println(" Enter \"reset\" to reset modem");
    DebugSerial.println(" Enter \"AT\" (without quotes), and you should see \"OK\"");
    DebugSerial.println(" DISCLAIMER: Entering AT commands without knowing what they do");
    DebugSerial.println(" can have undesired consiquinces...");
    DebugSerial.println("***********************************************************\n");
}

// Working loop
void loop()
{
    while (ModemSerial.available())
        DebugSerial.write(ModemSerial.read());
    
    if (!DebugSerial.available())
        return;

    String s = DebugSerial.readString();
    if (s == "")
        return;
    
    DebugSerial.println("Processing: " + s);
    
    if (s == "poweron")
    {
        powerOn();
        return;
    }

    if (s == "poweroff")
    {
        powerOff();
        return;
    }

    if (s == "reset")
    {
        reset();
        return;
    }

    s += "\r\n";
    ModemSerial.print(s);

    delay(1);
}