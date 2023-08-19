# 1 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
/*-------------------------------------------------

Teams Mute Button

Ken Zimny

V1

-------------------------------------------------*/
# 7 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
# 8 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino" 2

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
    SerialUSB.begin(115200);
    pinMode((13u), OUTPUT);
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
                digitalWrite((13u), HIGH);
            }
            else
            {
                digitalWrite((13u), LOW);
                endKeypress();
            }
        }
    }
    btn.previousReading = btn.reading;

    return firstPress;
};
