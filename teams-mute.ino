/*-------------------------------------------------
Teams Mute Button
Ken Zimny
V1
-------------------------------------------------*/

// ---------- Include Libraries ---------- //

#include <Keyboard.h>

// ---------- Define Variables ---------- //

// Button
int button = 7;
bool buttonState = HIGH;
bool buttonReading;
bool previousButtonReading;

// Debounce
unsigned long previousMillisTime = 0;
const long debounceDelay = 50;

// ---------- Setup ---------- //

void setup()
{
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(button, INPUT_PULLUP);
}

// ---------- Loop ---------- //

void loop()
{
    readButtonPin();
    buttonPressed();
};

// ---------- Functions ---------- //

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
            if (buttonState == LOW)
            {
                // Button has been pressed
                wasPressed = true;
                digitalWrite(LED_BUILTIN, HIGH);
                // Send keypress
                Keyboard.begin();
                Keyboard.press(KEY_LEFT_ALT);
                Keyboard.press(' ');
            }
            else
            {
                digitalWrite(LED_BUILTIN, LOW);
                // Release All keys
                Keyboard.releaseAll();
                Keyboard.end();
            }
        }
    }
    // Record the button value of this loop
    previousButtonReading = buttonReading;

    // Return bool for wasPressed
    return wasPressed;
};
