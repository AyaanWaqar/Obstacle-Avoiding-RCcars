const int trigPin1 = 8;
const int echoPin1 = 9;

const int trigPin2 = 10;
const int echoPin2 = 11;

const int trigPin3 = 12;
const int echoPin3 = 13;

const int in1 = 3;
const int in2 = 4;
const int in3 = 2;
const int in4 = 7;
const int ls= 5;
const int rs = 6;


void setup()
{

pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);

pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);

pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);

pinMode (in1, OUTPUT);
pinMode (in2, OUTPUT);
pinMode (in3, OUTPUT);
pinMode (in4, OUTPUT);
pinMode (ls, OUTPUT);
pinMode (rs, OUTPUT);

}

long duration1, distance1;
long duration2, distance2;
long duration3, distance3;

void loop()

{
analogWrite(ls,120);
analogWrite(rs,100);

digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
distance1 = duration1/58.2;
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
distance2 = duration2/58.2;

digitalWrite(trigPin3, LOW);
delayMicroseconds(2);
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);
duration3 = pulseIn(echoPin3, HIGH);
distance3 = duration3/58.2;
if(distance1<20&&distance2>15 && distance3>15)

{

digitalWrite(in1, LOW);  //TurnRight
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
}

else if(distance1<20&&distance3<15 && distance2>16)
{

digitalWrite(in1, LOW);  //TurnRight
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);

}

else if(distance1<20&&distance2<10 && distance3>15){

digitalWrite(in1, HIGH);  //TurnLeft
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);



}

else

{

digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}


}
