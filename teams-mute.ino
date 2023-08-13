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

// Counter
int counterDebounce = 0;

// Debounce
unsigned long previousMillisTime = 0;
const long debounceDelay = 50;

// ---------- Setup ---------- //

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(button, INPUT_PULLUP);
    Serial.begin(115200);
}

// ---------- Loop ---------- //

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
        // Test if the button was pressed
        if (buttonReading != buttonState)
        {
            // Update the Button's State
            buttonState = buttonReading;
            // Run on button press
            if (buttonState == 0)
            {
                counterDebounce++;
                Serial.println("Button Press Debounced: " + String(counterDebounce));
            }
        }
    }
    // Record the button value of this loop
    previousButtonReading = buttonReading;
};