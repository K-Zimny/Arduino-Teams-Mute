#include <Arduino.h>
#line 1 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
int button = 7;
bool buttonState; // 0 is pressed. 1 is not pressed.
bool previousButtonState = 1;
int counter = 0;

#line 6 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
void setup();
#line 13 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
void loop();
#line 6 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(button, INPUT_PULLUP);
    Serial.begin(115200);
}

void loop()
{
    buttonState = digitalRead(button); // 0 on press. on release, 1.
    if ((buttonState != previousButtonState) && (buttonState == 0))
    {
        counter++;
        Serial.println("Button Press: " + String(counter));
    };
    previousButtonState = buttonState; // BS = 0
};
