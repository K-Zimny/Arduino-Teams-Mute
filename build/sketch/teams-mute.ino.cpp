#include <Arduino.h>
#line 1 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
/*-------------------------------------------------
Teams Mute Button
Ken Zimny
V1
-------------------------------------------------*/

// ---------- Define Variables ---------- //

// Button
int button = 7;
bool buttonState = 1;
bool buttonReading;
bool previousButtonReading;
// bool buttonPressed;

// Counter
int counterDebounce = 0;

// Debounce
unsigned long previousMillisTime = 0;
const long debounceDelay = 50;

// ---------- Setup ---------- //

#line 25 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
void setup();
#line 34 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
void loop();
#line 43 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
void readButtonPin();
#line 49 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
bool buttonPressed();
#line 80 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
void sendKeystroke();
#line 25 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(button, INPUT_PULLUP);
    Serial.begin(115200);
}

// ---------- Loop ---------- //

void loop()
{
    readButtonPin();
    if (buttonPressed())
    {
        sendKeystroke();
    }
};

void readButtonPin()
{
    // Read our button pin value.
    buttonReading = digitalRead(button);
}

bool buttonPressed()
{
    // reset our button press
    bool wasPressed = false;
    // Test to see if our button was pressed and record that time.
    if (buttonReading != previousButtonReading)
    {
        previousMillisTime = millis();
    }
    // Test if we have debounced the button press.
    if ((millis() - previousMillisTime) > debounceDelay)
    {
        // Test if the button was pressed
        if (buttonReading != buttonState)
        {
            // Update the Button's State
            buttonState = buttonReading;
            if (buttonState == 0)
            {
                // Button has been pressed
                wasPressed = true;
            }
        }
    }
    // Record the button value of this loop
    previousButtonReading = buttonReading;

    // Return bool for wasPressed
    return wasPressed;
};

void sendKeystroke()
{
    counterDebounce++;
    Serial.println("Button Press Debounced: " + String(counterDebounce));
}

