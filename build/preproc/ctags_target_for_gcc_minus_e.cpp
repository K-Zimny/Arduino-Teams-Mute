# 1 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
int button = 7;
bool buttonState; // 0 is pressed. 1 is not pressed.
bool previousButtonState = 1;
int counter = 0;

void setup()
{
    pinMode((13u), OUTPUT);
    pinMode(button, INPUT_PULLUP);
    _UART1_.begin(115200);
}

void loop()
{
    buttonState = digitalRead(button); // 0 on press. on release, 1.
    if ((buttonState != previousButtonState) && (buttonState == 0))
    {
        counter++;
        _UART1_.println("Button Press: " + String(counter));
    };
    previousButtonState = buttonState; // BS = 0
};
