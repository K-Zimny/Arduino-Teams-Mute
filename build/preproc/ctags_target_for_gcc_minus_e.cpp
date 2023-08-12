# 1 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
int button = 7;
bool buttonReading;
bool buttonState = 1; // 0 is pressed. 1 is not pressed.
bool previousButtonState = 1; // init as 1
int counter = 0;
int counterDebounce = 0;
unsigned long previousDebounceTime = 0;
const long debounceDelay = 50;

void setup()
{
    pinMode((13u), OUTPUT);
    pinMode(button, INPUT_PULLUP);
    _UART1_.begin(115200);
}

void loop()
{
    // read the state of the switch into a local variable:
    buttonReading = digitalRead(button); // 0 pressed

    // check to see if you just pressed the button
    // (i.e. the input went from LOW to HIGH), and you've waited long enough
    // since the last press to ignore any noise:

    // If the switch changed, due to noise or pressing:
    if (buttonReading != previousButtonState)
    {
        // reset the debouncing timer
        previousDebounceTime = millis();
    }

    if ((millis() - previousDebounceTime) > debounceDelay)
    {
        // whatever the reading is at, it's been there for longer than the debounce
        // delay, so take it as the actual current state:

        // if the button state has changed:
        if (buttonReading != buttonState)
        {
            buttonState = buttonReading;

            // only toggle the LED if the new button state is HIGH
            if (buttonState == 0)
            {
                counterDebounce++;
                _UART1_.println("Button Press Debounced: " + String(counterDebounce));
            }
        }
    }

    // set the LED:
    // digitalWrite(ledPin, ledState);

    // save the reading. Next time through the loop, it'll be the lastButtonState:
    previousButtonState = buttonReading;

    // if ((buttonState != previousButtonState) && (buttonState == 0))
    // {
    //     counter++;
    //     // Serial.print("Button Pressed unstable: " + String(counter) + "; ");
    //     // Serial.print("Current Millis(): " + String(millis()) + "; ");
    //     Serial.println();
    //     if ((millis() - previousDebounceTime) > debounceDelay)
    //     {
    //         counterDebounce++;
    //         Serial.println("Button Press Debounced: " + String(counterDebounce));
    //         previousDebounceTime = millis();
    //     }
    // };
    // previousButtonState = buttonState;
};
