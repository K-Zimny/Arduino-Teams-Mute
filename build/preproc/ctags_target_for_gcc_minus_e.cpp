# 1 "C:\\Users\\Ken\\Documents\\Code\\Arduino\\teams-mute\\teams-mute.ino"
void setup()
{
pinMode((13u),OUTPUT);
}

void loop()
{
 digitalWrite((13u),HIGH);
    delay(1000);
    digitalWrite((13u),LOW);
    delay(1000);
}
