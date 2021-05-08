int motion = D2;
int led = D3;

void setup() 
{
    pinMode(motion, INPUT);
    pinMode(led, OUTPUT);
    Particle.subscribe("Motion", senseMotion, MY_DEVICES);
}

void loop() 
{
    if (digitalRead(motion) == HIGH)
    {
        Particle.publish("Motion", "Movement", PRIVATE);
    }
    delay(3000);
}

void flash()
{
    digitalWrite(D3, HIGH);
    delay(100);
    digitalWrite(D3, LOW);
    delay(100);
}

void senseMotion(const char *event, const char *data)
{
    flash();
    flash();
    flash();
}