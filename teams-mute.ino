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
};

// ---------- Loop ---------- //

void loop()
{
    if (buttonPressed(tempUnmute))
    {
        // Option + Spacebar
        Keyboard.press(KEY_LEFT_ALT); // Option
        Keyboard.press(' ');
    };
    if (buttonPressed(unmute))
    {
        // Command + Shift + M
        Keyboard.press(KEY_LEFT_GUI); // Command
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('m');
        Keyboard.releaseAll();
    };
    if (buttonPressed(video))
    {
        // Command + Shift + O
        Keyboard.press(KEY_LEFT_GUI); // Command
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('o');
        Keyboard.releaseAll();
    };
    if (buttonPressed(hand))
    {
        // Command + Shift + K
        Keyboard.press(KEY_LEFT_GUI); // Command
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('k');
        Keyboard.releaseAll();
    };
    if (buttonPressed(end))
    {
        // Command + Shift + H
        Keyboard.press(KEY_LEFT_GUI); // Command
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press('h');
        Keyboard.releaseAll();
    };
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
                Keyboard.begin();
                firstPress = true;
                digitalWrite(LED_BUILTIN, HIGH);
            }
            else
            {
                Keyboard.releaseAll();
                Keyboard.end();
                digitalWrite(LED_BUILTIN, LOW);
            }
        }
    }
    btn.previousReading = btn.reading;

    return firstPress;
};
