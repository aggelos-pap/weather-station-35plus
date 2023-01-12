#define rainfall A0

int value;

int set = 10;

void setup()
{

    Serial.begin(9600);

    pinMode(rainfall, INPUT);
}

void loop()
{

    value = analogRead(rainfall);

    //  Serial.print("Value is ");

    //  Serial.println(value);

    value = map(value, 0, 1023, 225, 0);
    //  Serial.println(value);

    //  Serial.println(value);
    if (value = 0)
    {
    }
    if (value >= set)
    {

        Serial.println("rain detected");
        if (value <= 60)
        {
            Serial.println("Drizzle");
        }
        else if (value <= 90)
        {
            Serial.println("Middle rain");
        }
        else
        {
            Serial.println("When it rains it pours");
        }
    }

    else
    {
        Serial.println("Rain is not detected");
    }

    delay(200);
}