int goal=0;
//float dpmss=0.12;  //degrees per millisecond -> 120° in 1s; 360° in 3 seconds
float mspd=7;   //milliseconds needed for one degree
float mspdFast=2.75;

void turnTowards(int pGoal,int pSpeed)
{
  Serial.print("Turn towards ");
  Serial.println(pGoal);
  if(pGoal>0 && pGoal<180)
  {
    if(pSpeed==0)
    {
      turnRight();
      delay(pGoal*(mspd));
    }
    else
    {
      hardRight();
      delay(pGoal*mspdFast);
    }
    forward();
  }
  else if(pGoal>=180)
  {
    if(pSpeed==0)
    {
      turnLeft();
      delay((360-pGoal)*(mspd-2));
    }
    else
    {
      hardLeft();
      delay((360-pGoal)*mspdFast);
    }
    forward();
  }
  else if(pGoal==0)
  {
    forward();
  }
}



