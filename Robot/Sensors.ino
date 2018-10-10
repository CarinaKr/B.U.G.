int maxReadings=20;
int readings;
float baseline;

void setBaseLine()
{
  /*baselineLight[0]=analogRead(frontLeft);
  baselineLight[1]=analogRead(frontRight);
  baselineLight[2]=analogRead(backLeft);
  baselineLight[3]=analogRead(backRight);*/
  baseline=(analogRead(frontLeft)+analogRead(frontRight)+analogRead(backLeft)
                    +analogRead(backRight))/4;
}

void readLightSensors()
{
  if(readings<maxReadings)
  {
    isReading=true;
    readings++;
    
    /*light[0]=(light[0]+(analogRead(frontLeft)-baselineLight[0]))/readings;
    light[1]=(light[1]+(analogRead(frontRight)-baselineLight[1]))/readings;
    light[2]=(light[2]+(analogRead(backLeft)-baselineLight[2]))/readings;
    light[3]=(light[3]+(analogRead(backRight)-baselineLight[3]))/readings;*/
    light[0]=(light[0]+(analogRead(frontLeft)-baseline))/readings;
    light[1]=(light[1]+(analogRead(frontRight)-baseline))/readings;
    light[2]=(light[2]+(analogRead(backLeft)-baseline))/readings;
    light[3]=(light[3]+(analogRead(backRight)-baseline))/readings;
    delay(1);
  }
  else
  {
    /*Serial.println("Light readings");
    for(int i=0;i<4;i++)
    {
      Serial.println(light[i]);
    }*/
    isReading=false;
    readings=0;
  }
  
  /*for(int i=0;i<4;i++)
  {
    Serial.print(" Sensor");
    Serial.print(i);
    Serial.print(":");
    Serial.print(light[i]);
  }
  Serial.println();*/
}


void readDistance()
{
  distance=analogRead(distancePin);
  /*Serial.print("Distance: ");
  Serial.println(distance);*/
}

