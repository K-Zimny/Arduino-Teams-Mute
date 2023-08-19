/*-------------------------------------------------
Teams Mute Button
Ken Zimny
V1
-------------------------------------------------*/

#include <Keyboard.h>

// Buttons
struct Button
{
    int input;
    bool state;
    bool reading;
    bool previousReading;
    unsigned long previousMillis;
};

Button tempUnmute = {7, HIGH, false, false, 0};
Button unmute = {5, HIGH, false, false, 0};
Button video = {4, HIGH, false, false, 0};
Button hand = {3, HIGH, false, false, 0};
Button end = {2, HIGH, false, false, 0};

// ---------- Setup ---------- //

void setup()
{
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(tempUnmute.input, INPUT_PULLUP);
    pinMode(unmute.input, INPUT_PULLUP);
    pinMode(video.input, INPUT_PULLUP);
    pinMode(hand.input, INPUT_PULLUP);
    pinMode(end.input, INPUT_PULLUP);
}

// ---------- Loop ---------- //

void loop()
{
    if (buttonPressed(tempUnmute))
        holdKeypress('t');
    if (buttonPressed(unmute))
        sendKeypress('m');
    if (buttonPressed(video))
        sendKeypress('v');
    if (buttonPressed(hand))
        sendKeypress('h');
    if (buttonPressed(end))
        sendKeypress('e');
};

// ---------- Functions ---------- //

void sendKeypress(char key)
{
    Keyboard.begin();
    Keyboard.press(key);
    endKeypress();
};
void holdKeypress(char key)
{
    Keyboard.begin();
    Keyboard.press(key);
};
void endKeypress()
{
    Keyboard.releaseAll();
    Keyboard.end();
};

bool buttonPressed(Button &btn)
{
    bool firstPress = false;
    btn.reading = digitalRead(btn.input);
    // Debounce
    if (btn.reading != btn.previousReading)
    {
        btn.previousMillis = millis();
    }
    if ((millis() - btn.previousMillis) > 50) // Debounce Delay
    {
        if (btn.reading != btn.state)
        {
            btn.state = btn.reading;
            if (btn.state == LOW)
            {
                // Button has been pressed
                firstPress = true;
                digitalWrite(LED_BUILTIN, HIGH);
            }
            else
            {
                digitalWrite(LED_BUILTIN, LOW);
                endKeypress();
            }
        }
    }
    btn.previousReading = btn.reading;

    return firstPress;
};
