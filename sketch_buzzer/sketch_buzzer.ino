#include <NanitLib.h>
byte const buzz = P4_2;

int const LEN_NOTE = 300;
int const LEN_PAUSE = LEN_NOTE / 3;

//int tones[12] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};

enum E_Octava {
  C,
  Db,
  D,
  Eb,
  E,
  F,
  Gb,
  G,
  Ab,
  A,
  Bb,
  B
};

int Sm[]
{       
  130,
  138,
  147,
  156,
  165,
  174,
  185,
  196,
  208,
  220,
  233,
  247
};

int Fs[]
{       
  130 * 2,
  138 * 2,
  147 * 2,
  156 * 2,
  165 * 2,
  174 * 2,
  185 * 2,
  196 * 2,
  208 * 2,
  220 * 2,
  233 * 2,
  247 * 2
};

void Voice(byte buzer, int frequency, int length) {
  tone(buzer, frequency);
  delay(length);
}

void Pause(byte buzer, int length) {
  noTone(buzer);
  //digitalWrite(buzer, 1);//for active buzzer
  delay(length);
}


void setup() {  
  Nanit_Base_Start();  
  Serial.begin(9600);
  //GET_NANIT.getBataryVoltage();  
  //Serial.println("12345");

  // for (int i = 0; i < 30; ++i) {
  //   Serial.println(i);
  //   delay(500);
  // }
  pinMode(buzz, OUTPUT);
}

void listenDoMajScale (byte buzzer) {
  // tone(buzz, 200);  
  // delay(1000);
  Pause(buzzer, LEN_PAUSE * 2);
  for (int i = 0; i < 7; ++i) {
    if ( i != 6) Voice(buzzer, Sm[C + i], LEN_NOTE);
    else Voice(buzzer, Fs[C], LEN_NOTE);
    Pause(buzzer, LEN_PAUSE);
  }
}

void listenSmokeOnAwater(byte buzzer) {
 
  //----I takt--------
  Pause(buzzer, LEN_PAUSE * 2);
  Voice(buzzer, Sm[D], LEN_NOTE);
  Pause(buzzer, LEN_PAUSE * 3);
  Voice(buzzer, Sm[F], LEN_NOTE);
  Pause(buzzer, LEN_PAUSE * 3);
  Voice(buzzer, Sm[G], LEN_NOTE);
  Pause(buzzer, LEN_PAUSE * 4);
  Voice(buzzer, Sm[D], LEN_NOTE);
  Pause(buzzer, LEN_PAUSE);
  //---II takt--------
  Pause(buzzer, LEN_PAUSE * 3);
  Voice(buzzer, Sm[F], LEN_NOTE);
  Pause(buzzer, LEN_PAUSE * 3);
  Voice(buzzer, Sm[Bb], LEN_NOTE);
  Pause(buzzer, LEN_PAUSE);
  Voice(buzzer, Sm[A], LEN_NOTE);
  Pause(buzzer, LEN_PAUSE * 5);
  //---III takt--------
  Pause(buzzer, LEN_PAUSE);
  Voice(buzzer, Sm[D], LEN_NOTE);
  Pause(buzzer, LEN_PAUSE * 3);
  Voice(buzzer, Sm[F], LEN_NOTE);
  Pause(buzzer, LEN_PAUSE * 3);
  Voice(buzzer, Sm[G], LEN_NOTE);
  Pause(buzzer, LEN_PAUSE * 3);
  Voice(buzzer, Sm[F], LEN_NOTE);
  Pause(buzzer, LEN_PAUSE);
  //---IV takt--------
  Pause(buzzer, LEN_PAUSE * 3);
  Voice(buzzer, Sm[D], LEN_NOTE);
  Pause(buzzer, LEN_PAUSE * 4);
  Voice(buzzer, Sm[D], LEN_NOTE);
  Pause(buzzer, LEN_PAUSE * 7);
}
  
void loop() {  
  listenSmokeOnAwater(buzz);
}