int button = 7;
bool buttonState; // 0 is pressed. 1 is not pressed.
bool previousButtonState = 1;
int counter = 0;
int counterDebounce = 0;
unsigned long previousDebounceTime = 0;
const long debounceDelay = 1000;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(button, INPUT_PULLUP);
    Serial.begin(115200);
}

void loop()
{
    // Serial.print("Previous Debounce: " + String(previousDebounceTime) + "; ");
    buttonState = digitalRead(button);
    if ((buttonState != previousButtonState) && (buttonState == 0))
    {
        counter++;
        // Serial.print("Button Pressed unstable: " + String(counter) + "; ");
        // Serial.print("Current Millis(): " + String(millis()) + "; ");
        Serial.println();
        if ((millis() - previousDebounceTime) > debounceDelay)
        {
            counterDebounce++;
            Serial.println("Button Press Debounced: " + String(counterDebounce));
            previousDebounceTime = millis();
        }
    };
    previousButtonState = buttonState;
};