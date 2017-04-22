///*------------音符对应蜂鸣器频率------------*/
//
//#define B0  31
//#define C1  33
//#define CS1 35
//#define D1  37
//#define DS1 39
//#define E1  41
//#define F1  44
//#define FS1 46
//#define G1  49
//#define GS1 52
//#define A1  55
//#define AS1 58
//#define B1  62
//#define C2  65
//#define CS2 69
//#define D2  73
//#define DS2 78
//#define E2  82
//#define F2  87
//#define FS2 93
//#define G2  98
//#define GS2 104
//#define A2  110
//#define AS2 117
//#define B2  123
//#define C3  131
//#define CS3 139
//#define D3  147
//#define DS3 156
//#define E3  165
//#define F3  175
//#define FS3 185
//#define G3  196
//#define GS3 208
//#define A3  220
//#define AS3 233
//#define B3  247
//#define C4  262
//#define CS4 277
//#define D4  294
//#define DS4 311
//#define E4  330
//#define F4  349
//#define FS4 370
//#define G4  392
//#define GS4 415
//#define A4  440
//#define AS4 466
//#define B4  494
//#define C5  523
//#define CS5 554
//#define D5  587
//#define DS5 622
//#define E5  659
//#define F5  698
//#define FS5 740
//#define G5  784
//#define GS5 831
//#define A5  880
//#define AS5 932
//#define B5  988
//#define C6  1047
//#define CS6 1109
//#define D6  1175
//#define DS6 1245
//#define E6  1319
//#define F6  1397
//#define FS6 1480
//#define G6  1568
//#define GS6 1661
//#define A6  1760
//#define AS6 1865
//#define B6  1976
//#define C7  2093
//#define CS7 2217
//#define D7  2349
//#define DS7 2489
//#define E7  2637
//#define F7  2794
//#define FS7 2960
//#define G7  3136
//#define GS7 3322
//#define A7  3520
//#define AS7 3729
//#define B7  3951
//#define C8  4186
//#define CS8 4435
//#define D8  4699
//#define DS8 4978
//
//#define buzzer_pin 8 //定义蜂鸣器引脚
//
///*------------定义歌曲音调的数组------------*/
//
//int notes[] = {
//  C5, D5, E5, F5, G5, A5, B5, C6
//};
//
///*------------定义歌曲节奏的数组------------*/
//
//byte beats[] = {
//  200, 200, 200, 200, 200, 200, 200, 800
//};
//
//void setup() {
//  pinMode(buzzer_pin, OUTPUT); //定义蜂鸣器引脚为输出状态
//}
//
//void loop() {
//  for ( int i = 0; i < 7; i++) {
//
///*------------设置i在歌曲长度内递增，这样就能逐一执行数组中的数据------------*/
//
//    tone(buzzer_pin, notes[i]); //播放音乐
//    delay(200);//beats[i]); //播放间隔
//
//    noTone(buzzer_pin);
//    delay(10);
//  }


//}

#define NOTE_D0 -1
#define NOTE_D1 294
#define NOTE_D2 330
#define NOTE_D3 350
#define NOTE_D4 393
#define NOTE_D5 441
#define NOTE_D6 495
#define NOTE_D7 556

#define NOTE_DL1 147
#define NOTE_DL2 165
#define NOTE_DL3 175
#define NOTE_DL4 196
#define NOTE_DL5 221
#define NOTE_DL6 248
#define NOTE_DL7 278

#define NOTE_DH1 589
#define NOTE_DH2 661
#define NOTE_DH3 700
#define NOTE_DH4 786
#define NOTE_DH5 882
#define NOTE_DH6 990
#define NOTE_DH7 112
//以上部分是定义是把每个音符和频率值对应起来，其实不用打这么多，但是都打上了，后面可以随意编写

#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625
//这部分是用英文对应了拍子，这样后面也比较好看


int tune[] =
{
  NOTE_D0, NOTE_D0, NOTE_D0, NOTE_D6, NOTE_D7, NOTE_DH1, NOTE_D7, NOTE_DH1, NOTE_DH3, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D3, NOTE_D3,
  NOTE_D6, NOTE_D5, NOTE_D6, NOTE_DH1, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D3, NOTE_D4, NOTE_D3, NOTE_D4, NOTE_DH1,
  NOTE_D3, NOTE_D3, NOTE_D0, NOTE_DH1, NOTE_DH1, NOTE_DH1, NOTE_D7, NOTE_D4, NOTE_D4, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D0, NOTE_D6, NOTE_D7,
  NOTE_DH1, NOTE_D7, NOTE_DH1, NOTE_DH3, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D3, NOTE_D3, NOTE_D6, NOTE_D5, NOTE_D6, NOTE_DH1,
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D2, NOTE_D3, NOTE_D4, NOTE_DH1, NOTE_D7, NOTE_D7, NOTE_DH1, NOTE_DH1, NOTE_DH2, NOTE_DH2, NOTE_DH3, NOTE_DH1, NOTE_DH1, NOTE_DH1,
  NOTE_DH1, NOTE_D7, NOTE_D6, NOTE_D6, NOTE_D7, NOTE_D5, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_DH1, NOTE_DH2, NOTE_DH3, NOTE_DH2, NOTE_DH3, NOTE_DH5,
  NOTE_DH2, NOTE_DH2, NOTE_DH2, NOTE_D5, NOTE_D5, NOTE_DH1, NOTE_D7, NOTE_DH1, NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH3,
  NOTE_D6, NOTE_D7, NOTE_DH1, NOTE_D7, NOTE_DH2, NOTE_DH2, NOTE_DH1, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_DH4, NOTE_DH3, NOTE_DH2, NOTE_DH1,
  NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH6, NOTE_DH6, NOTE_DH5, NOTE_DH5, NOTE_DH3, NOTE_DH2, NOTE_DH1, NOTE_DH1, NOTE_D0, NOTE_DH1,
  NOTE_DH2, NOTE_DH1, NOTE_DH2, NOTE_DH2, NOTE_DH5, NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH6, NOTE_DH6, NOTE_DH5, NOTE_DH5,
  NOTE_DH3, NOTE_DH2, NOTE_DH1, NOTE_DH1, NOTE_D0, NOTE_DH1, NOTE_DH2, NOTE_DH1, NOTE_DH2, NOTE_DH2, NOTE_D7, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D7
};//这部分就是整首曲子的音符部分，用了一个序列定义为tune，整数

float duration[] =

{
  1, 1, 1, 0.5, 0.5,     1 + 0.5, 0.5, 1, 1,     1, 1, 1, 0.5, 0.5,
  1 + 0.5, 0.5, 1, 1,     1, 1, 1, 1,          1 + 0.5, 0.5, 1, 1,
  1, 1, 0.5, 0.5, 0.5, 0.5,    1 + 0.5, 0.5, 1, 1,     1, 1, 1, 0.5, 0.5,
  1 + 0.5, 0.5, 1, 1,    1, 1, 1, 0.5, 0.5,     1 + 0.5, 0.5, 1, 1,
  1, 1, 1, 0.5, 0.5,    1, 0.5, 0.25, 0.25, 0.25, 0.5,    0.5, 0.5, 0.5, 0.25, 0.5, 1,
  0.5, 0.5, 0.5, 0.5, 1, 1,    1, 1, 1, 0.5, 0.5,    1 + 0.5, 0.5, 1, 1,
  1, 1, 1, 0.5, 0.5,    1.5, 0.5, 1, 1,    1, 1, 1, 1,
  0.5, 0.5, 1, 1, 0.5, 0.5,    1.5, 0.25, 0.5, 1,    1, 1, 1, 1,
  1, 1, 1, 1,    1, 1, 1, 1,    0.5, 0.5, 1, 1, 0.5, 0.5,
  1, 0.5, 0.5, 1, 1,    1, 1, 1, 1,    1, 1, 1, 1,
  0.5, 0.5, 1, 1, 0.5, 0.5,    1, 0.5, 0.25, 0.5, 1,    1, 1, 1, 0.5, 0.5
};//这部分是整首曲子的节拍部分，也定义个序列duration，浮点（数组的个数和前面音符的个数是一样的，一一对应么）

int length;//这里定义一个变量，后面用来表示共有多少个音符

int tonePin = 8; //蜂鸣器的pin


void setup()

{
  pinMode(tonePin, OUTPUT); //设置蜂鸣器的pin为输出模式

  length = sizeof(tune) / sizeof(tune[0]); //这里用了一个sizeof函数， 可以查出tone序列里有多少个音符

}

void loop()

{

  for (int x = 0; x < length; x++) //循环音符的次数
  {
    tone(tonePin, tune[x]); //此函数依次播放tune序列里的数组，即每个 音符

    delay(400 * duration[x]); //每个音符持续的时间，即节拍duration，是调整时间的越大，曲子速度越慢，越小曲子速度越快，自己掌握吧

    noTone(tonePin);//停止当前音符，进入下一音符

  }
  delay(5000);//等待5秒后，循环重新开始
}

