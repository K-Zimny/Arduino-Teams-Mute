int button = 7;
bool buttonReading;
bool buttonState = 1;         // 0 is pressed. 1 is not pressed.
bool previousButtonState = 1; // init as 1
int counter = 0;
int counterDebounce = 0;
unsigned long previousDebounceTime = 0;
const long debounceDelay = 50;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(button, INPUT_PULLUP);
    Serial.begin(115200);
}

void loop()
{
    buttonReading = digitalRead(button);
    if (buttonReading != previousButtonState)
    {
        previousDebounceTime = millis();
    }
    if ((millis() - previousDebounceTime) > debounceDelay)
    {
        if (buttonReading != buttonState)
        {
            buttonState = buttonReading;
            if (buttonState == 0)
            {
                counterDebounce++;
                Serial.println("Button Press Debounced: " + String(counterDebounce));
            }
        }
    }
    previousButtonState = buttonReading;
};