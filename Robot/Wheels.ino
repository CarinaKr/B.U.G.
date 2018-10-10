int motorSpeed=175;

void pause()
{
  analogWrite(motor1Enable,0);
  analogWrite(motor2Enable,0);
}

void leftForward()
{
  analogWrite(motor1Enable,motorSpeed);
  digitalWrite(motor1In1,HIGH);
  digitalWrite(motor1In2,LOW);
}
void leftBackward()
{
  analogWrite(motor1Enable,motorSpeed);
  digitalWrite(motor1In1,LOW);
  digitalWrite(motor1In2,HIGH);
}
void leftStop()
{
  analogWrite(motor1Enable,0);
}

void rightForward()
{
  analogWrite(motor2Enable,motorSpeed);
  digitalWrite(motor2In1,HIGH);
  digitalWrite(motor2In2,LOW);
}
void rightBackward()
{
  analogWrite(motor2Enable,motorSpeed);
  digitalWrite(motor2In1,LOW);
  digitalWrite(motor2In2,HIGH);
}
void rightStop()
{
  analogWrite(motor2Enable,0);
}

void forward()
{
  //both wheels forward
  leftForward();
  rightForward();
}

void turnLeft()
{
  rightForward();
  leftStop();
}

void hardLeft()
{
  leftBackward();
  rightForward();
}

void turnRight()
{
  leftForward();
  rightStop();
}

void hardRight()
{
  leftForward();
  rightBackward();
}

