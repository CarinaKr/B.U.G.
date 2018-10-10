int thrDistance=350;
float lightIntensity[4]; //low to high
float minDif=4;
float darkDif=11;  //2 for 50%
float diff;
int turnSpeed;
int turnGoal;
int forwardCounter;
int maxForward=100;
int thrDark=-7;  //-5 for 50% ; -10 for dark
int delayInDark=5;
float delayDarkCounter=0;
int isDriving=0;

void checkCollision()
{
  //Serial.println(distance);
  if(distance>thrDistance)
  {
    turnTowards(random(150,211),1); 
    
  }
}

void findRotation()
{
  turnGoal=0;
  orderLight();
  /*Serial.println();
  for(int i=0;i<4;i++)
  {
    Serial.print("light: ");
    Serial.print(light[i]);
    Serial.print(" light intensity: ");
    Serial.println(lightIntensity[i]);
  }*/
  float value=lightIntensity[0]-lightIntensity[3];
  diff=abs(value);
  if(diff>minDif)
  {
    Serial.print("diff");
    Serial.println(diff);
    if(lightIntensity[2]>=thrDark)  //light on
    {
        forwardCounter=0;
        if(lightIntensity[0]==light[0])
        {
          turnGoal=315;
        }
        else if(lightIntensity[0]==light[1])
        {
          turnGoal=55;
        }
        else if(lightIntensity[0]==light[2])
        {
          turnGoal=225;
        }
        else if(lightIntensity[0]==light[3])
        {
          turnGoal=135;
        } 
    
        /*if(diff>5)
        {
          turnSpeed=1;
        }
        else
        {
          turnSpeed=0;
        }*/
        turnTowards(turnGoal,0);
    }
    else if(lightIntensity[2]<=thrDark && diff>darkDif && isDriving==0) //light off
    {
      Serial.println("in the dark");
      Serial.print("lightIntensity[3]");
      Serial.println(lightIntensity[3]);
      for(int i=0;i<4;i++)
       {
        Serial.println(light[i]);
        }
      
        forwardCounter=0;
        if(lightIntensity[3]==light[0] && lightIntensity[3]!= 1023)
        {
          turnGoal=135;
        }
        else if(lightIntensity[3]==light[1] && lightIntensity[3]!= 1023)
        {
          turnGoal=225;
        }
        else if(lightIntensity[3]==light[2] && lightIntensity[3]!= 1023)
        {
          turnGoal=45;
        }
        else if(lightIntensity[3]==light[3] && lightIntensity[3]!= 1023)
        {
          turnGoal=315;
        } 
        if(lightIntensity[3]<1000)
        {
          turnTowards(turnGoal,turnSpeed);
          isDriving=1;
        }
        else
        {
          pause();
        }
        
    }
    
    
  }
  
  else
  {
    forwardCounter++;
    if(forwardCounter>maxForward)
    {
      //turnTowards(random(100,260),1);
      Serial.println("too long forward");
      forwardCounter=0;
    }
  }
  
}

void orderLight()
{ 
  int lightUsed[4]={0,0,0,0};
  
  for(int k=0;k<4;k++)
  {
    lightIntensity[k]=1023;
    
    for(int i=0;i<4;i++)
    {
      if(light[i]<lightIntensity[k]&& lightUsed[i]==0)
      {
        lightIntensity[k]=light[i];
      }
    }
    for(int l=0;l<4;l++)  //check whicht light[] has been used in the end
    {
      if(lightIntensity[k]==light[l])
      {
        lightUsed[l]=1;
      }
    }
  }
}

void checkDarkness()
{
  if(lightIntensity[3]<thrDark)
  {
    Serial.println("in the dark");
    Serial.println(isDriving);
    if(isDriving==0)
    {
      pause();
    }
    else
    {
      delayDarkCounter++;
      if(delayDarkCounter>=delayInDark)
      {
        isDriving=0;
        delayDarkCounter=0;
      }
    }
    isDark=true;
  }
  else
  {
    isDark=false;
  }
}

