#include <Arduino.h>
#line 1 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
int button = 7;
bool buttonReading;
bool buttonState; // 0 is pressed. 1 is not pressed.
bool previousButtonReading;
int counter = 0;
int counterDebounce = 0;
unsigned long previousMillisTime = 0;
const long debounceDelay = 50;

#line 10 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
void setup();
#line 17 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
void loop();
#line 10 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(button, INPUT_PULLUP);
    Serial.begin(115200);
}

void loop()
{
    // Read our button pin.
    buttonReading = digitalRead(button);
    // Test to see if our button was pressed and record that time.
    if (buttonReading != previousButtonReading)
    {
        previousMillisTime = millis();
    }
    // Test if we have debounced the button press.
    if ((millis() - previousMillisTime) > debounceDelay)
    {
        if (buttonReading != buttonState)
        {
            buttonState = buttonReading;
            if (buttonState == 0)
            {
                counterDebounce++;
                Serial.println("Button Press Debounced: " + String(counterDebounce));
            }
            else
            {
                Serial.println("else");
                delay(1000);
            }
        }
    }
    previousButtonReading = buttonReading;
};
